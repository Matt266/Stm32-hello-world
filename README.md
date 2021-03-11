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

## Code Example
* The following code is a snippet extracted from the main.c file showcasing the I2C event handler. For further detail and explanation the full code / linker script and 
  corresponding comments shall be referenced
  
 ```
   void I2C1_EV_HANDLER(void) {	
		
		if(i2c_tx.pos == -2){
			while((*I2C1_SR1 & 1) == 0); //wait for start bit
			unsigned int SR1_Value = *I2C1_SR1;
			*I2C1_DR = (i2c_tx.adress<<1);
			i2c_tx.pos++;
		}
		else if(i2c_tx.pos == -1){
			while(((*I2C1_SR1>>1)&0x01)==0); //wait for ADDR bit
			unsigned int SR1_Value = *I2C1_SR1;
			unsigned int SR2_Value = *I2C1_SR2; //read SR1 & SR2 to clear ADDR
			i2c_tx.pos++;
			
			//write first byte of data
			*I2C1_DR = i2c_tx.buffer[i2c_tx.pos];
			i2c_tx.pos++;
		}
		else if(i2c_tx.pos > 0 && i2c_tx.pos < i2c_tx.len){
			while((((*I2C1_SR1)>>7)&0x01)==0);	//wait for TxE bit
			*I2C1_DR = i2c_tx.buffer[i2c_tx.pos];
			i2c_tx.pos++;
		}
		else if(i2c_tx.pos >= i2c_tx.len){
			*I2C1_CR1 |= (1<<9);	//generate stop condition
		}
		
		*NVIC_ICPR0 |= (0x01<<31); //clear pending bit
	}
  ```
