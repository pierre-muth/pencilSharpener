/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15313
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <builtins.h>

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
enum state {SHARPING, STOPPING, IDLE}; 

uint8_t pwm_value = 0xBB;
uint8_t red; uint8_t green; uint8_t blue;
enum state status = SHARPING;

void TMR0interrupHandler(void) {
    IO_servo_SetHigh();
    TMR2_Start();
}

void TMR2interrupHandler(void) {
    IO_servo_SetLow();
}

// reverse the bits in a char
uint8_t bitflip(uint8_t b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return (uint8_t)b;
}

void sendSK6812rgb(uint8_t r, uint8_t g, uint8_t b) {
    char i;
    r = bitflip(r);
    g = bitflip(g);
    b = bitflip(b);

    INTCONbits.GIE = 0;
    
    for (i=0; i<8; i++){
        if ((g & 1) == 1) {
            IO_sk6812_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            IO_sk6812_PORT = 0;
        } else {
            IO_sk6812_PORT = 1;
            NOP();
            IO_sk6812_PORT = 0;
        }
        g = g >> 1;
    }
    
    for (i=0; i<8; i++){
        if ((r & 1) == 1) {
            IO_sk6812_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            IO_sk6812_PORT = 0;
        } else {
            IO_sk6812_PORT = 1;
            NOP();
            IO_sk6812_PORT = 0;
        }
        r = r >> 1;
    }
    
    for (i=0; i<8; i++){
        if ((b & 1) == 1) {
            IO_sk6812_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            IO_sk6812_PORT = 0;
        } else {
            IO_sk6812_PORT = 1;
            NOP();
            IO_sk6812_PORT = 0;
        }
        b = b >> 1;
    }
    
    INTCONbits.GIE = 1;
}

void resetSK6812() {
    IO_sk6812_PORT = 0;
    __delay_us(15);
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    
    for (uint8_t i=0; i<6; i++) {
        sendSK6812rgb(0, 0, 255);
        __delay_ms(80);
        sendSK6812rgb(0, 0, 0);
        __delay_ms(200);
    }
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    TMR0_SetInterruptHandler(TMR0interrupHandler);
    TMR2_SetInterruptHandler(TMR2interrupHandler);
    
    
    while (1) {
        __delay_ms(20);
        switch (status) {
            case SHARPING:
                pwm_value++;
                red = 255; green = 255; blue = 0;
                if (pwm_value > 0xF9) pwm_value = 0xF9;
                if (IO_start_GetValue()) status = STOPPING;
                if (!IO_end_GetValue()) status = STOPPING;
                break;
            case STOPPING:
                red = 255; green = 0; blue = 255;
                pwm_value--;
                if (pwm_value < 0xBB) pwm_value = 0xBB;
                if (IO_start_GetValue() && IO_end_GetValue()) status = IDLE;
                break;
            case IDLE:
                pwm_value--;
                red = 0; green = 255; blue = 0;
                if (pwm_value < 0xBB) pwm_value = 0xBB;
                if (!IO_start_GetValue()) status = SHARPING;
                if (!IO_end_GetValue()) status = STOPPING;
                break;
        }
        TMR2_Period8BitSet(pwm_value);
        sendSK6812rgb(red, green, blue);
    }
}
/**
 End of File
*/