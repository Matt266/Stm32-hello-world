# STM32 Bare Metal I2C Display "Hello World"
## Introduction
* This project uses a STM32f401re based Nucleo development board and a SH1106 display module connected via I2C. 
* The STM32 microcontroller is used without a RTOS or any libraries. Instead it is purely bare metal C-code.

  ![Hello World Image](/hello-world.jpg)

## Approach
* The software (with the associated linker script) provides a vector table and stack pointer before it starts configuring the system settings. 
* On reset the ".bss" section is initialized to zero while the ".data" section is copied from Flash to SRAM.
* A timer is configured to periodically start an interrupt in order to blink the onboard LED at about 0.5Hz. 
* Finally a transmission on the I2C interface is initialized and the hardcoded "Hello World" is displayed on the OLED.

## Purpose
* I started this project with the purpose of developing a better understanding about how the ARM toolchain, interrupts, and peripheral registers work.
* For this sake I didn't use any libraries (not even the standard one).

## Further Details
* I had to create a new linker script for this project. It is bases on existing scripts that can be found online. As the work that needs to be done by the script is nearly the same it looks similar to those or is even identical for larger parts. 
* I learned a lot while creating it so I don't think of this is a problem but it is definitely something I wanted to note.
* The code written includes flaws which I didn't correct as they don't further affect the educational value it provides for me. 
* For the biggest ones I added short comments explaining why the implementation is bad and ideas how to improve it.
