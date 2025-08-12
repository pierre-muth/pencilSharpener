/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15313
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_servo aliases
#define IO_servo_TRIS                 TRISAbits.TRISA0
#define IO_servo_LAT                  LATAbits.LATA0
#define IO_servo_PORT                 PORTAbits.RA0
#define IO_servo_WPU                  WPUAbits.WPUA0
#define IO_servo_OD                   ODCONAbits.ODCA0
#define IO_servo_ANS                  ANSELAbits.ANSA0
#define IO_servo_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_servo_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_servo_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_servo_GetValue()           PORTAbits.RA0
#define IO_servo_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_servo_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_servo_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_servo_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_servo_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_servo_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_servo_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_servo_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_sk6812 aliases
#define IO_sk6812_TRIS                 TRISAbits.TRISA2
#define IO_sk6812_LAT                  LATAbits.LATA2
#define IO_sk6812_PORT                 PORTAbits.RA2
#define IO_sk6812_WPU                  WPUAbits.WPUA2
#define IO_sk6812_OD                   ODCONAbits.ODCA2
#define IO_sk6812_ANS                  ANSELAbits.ANSA2
#define IO_sk6812_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_sk6812_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_sk6812_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_sk6812_GetValue()           PORTAbits.RA2
#define IO_sk6812_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_sk6812_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_sk6812_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_sk6812_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_sk6812_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_sk6812_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_sk6812_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_sk6812_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_start aliases
#define IO_start_TRIS                 TRISAbits.TRISA4
#define IO_start_LAT                  LATAbits.LATA4
#define IO_start_PORT                 PORTAbits.RA4
#define IO_start_WPU                  WPUAbits.WPUA4
#define IO_start_OD                   ODCONAbits.ODCA4
#define IO_start_ANS                  ANSELAbits.ANSA4
#define IO_start_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_start_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_start_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_start_GetValue()           PORTAbits.RA4
#define IO_start_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_start_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_start_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_start_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_start_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_start_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_start_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_start_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_end aliases
#define IO_end_TRIS                 TRISAbits.TRISA5
#define IO_end_LAT                  LATAbits.LATA5
#define IO_end_PORT                 PORTAbits.RA5
#define IO_end_WPU                  WPUAbits.WPUA5
#define IO_end_OD                   ODCONAbits.ODCA5
#define IO_end_ANS                  ANSELAbits.ANSA5
#define IO_end_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_end_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_end_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_end_GetValue()           PORTAbits.RA5
#define IO_end_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_end_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_end_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_end_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_end_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_end_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_end_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define IO_end_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/