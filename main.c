
	extern unsigned long _sisr_vector;
	extern unsigned long _esisr_vector;
	extern unsigned long _etext;
	extern unsigned long _sidata; //flash adress of to data
	extern unsigned long _sdata; //SRAM adress to copy data to
	extern unsigned long _edata;
	extern unsigned long _sbss;
	extern unsigned long _ebss;
	extern unsigned long _min_stack_size;
	extern unsigned long _stack_top; // bigger Memory Adress
	
	typedef volatile struct {
			volatile char adress;
			volatile int len;
			volatile int pos;
			volatile char* buffer;
	} i2c_transmission_t;
	
	 i2c_transmission_t i2c_tx;
	
	/*********************************************************
	 *														 *
	 *	Custom Memory Section names: .isr_vector 	._stack	 *
	 *													 	 *
	 *********************************************************/

	typedef void (*isr_handler)(void);
	
	#define RCC_Base 0x40023800
	#define GPIOA_Base 0x40020000
	#define GPIOB_Base 0x40020400
	#define GPIOC_Base 0x40020800
	#define GPIOD_Base 0x40020C00
	#define FLASH_Base 0x40023C00
	#define TIM2_Base 0x40000000
	#define NVIC_Base 0xE000E000
	#define I2C1_Base 0x40005400 
	#define FPU_Base 0xE000EF30
	#define SCB_Base 0xE000E008
	
	#define OLED_Adress_HIGH 0x3D
	#define OLED_Adress_LOW 0x3C //0b0111100 and 0b0111101 are possible
	
	#define DEFAULT_HANDLER(name) __attribute__((interrupt)) __attribute__((used)) __attribute__((weak)) __attribute__((noreturn)) void name(void)  {while(1);}
	
		DEFAULT_HANDLER(NMI_Handler);
		//DEFAULT_HANDLER(HARD_FAULT_HANDLER);
		DEFAULT_HANDLER(MEM_MANAGE_HANDLER);
		DEFAULT_HANDLER(BUS_FAULT_HANDLER);
		//DEFAULT_HANDLER(USAGE_FAULT_HANDLER);
		DEFAULT_HANDLER(SVCALL_HANDLER);
		DEFAULT_HANDLER(DEBUG_MONITOR_HANDLER);
		DEFAULT_HANDLER(PENDSV_HANDLER);
		DEFAULT_HANDLER(SYSTICK_HANDLER);
		DEFAULT_HANDLER(WWDG_HANDLER);
		DEFAULT_HANDLER(EXTI16_PVD_Handler);
		DEFAULT_HANDLER(EXTI21_TAMP_STAMP_HANDLER);
		DEFAULT_HANDLER(EXTI22_RTC_WKUP_HANDLER);
		DEFAULT_HANDLER(FLASH_HANDLER);
		DEFAULT_HANDLER(RCC_HANDLER);
		DEFAULT_HANDLER(EXTI0_HANDLER);
		DEFAULT_HANDLER(EXTI1_HANDLER);
		DEFAULT_HANDLER(EXTI2_HANDLER);
		DEFAULT_HANDLER(EXTI3_HANDLER);
		DEFAULT_HANDLER(EXTI4_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM0_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM1_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM2_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM3_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM4_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM5_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM6_HANDLER);
		DEFAULT_HANDLER(ADC_HANDLER);
		DEFAULT_HANDLER(EXTI9_5_HANDLER);
		DEFAULT_HANDLER(TIM1_BRK_TIM9_HANDLER);
		DEFAULT_HANDLER(TIM1_UP_TIM10_HANDLER);
		DEFAULT_HANDLER(TIM1_TRG_COM_TIM11_HANDLER);
		DEFAULT_HANDLER(TIM1_CC_HANDLER);
		//DEFAULT_HANDLER(TIM2_HANDLER);
		DEFAULT_HANDLER(TIM3_HANDLER);
		DEFAULT_HANDLER(TIM4_HANDLER);
		//DEFAULT_HANDLER(I2C1_EV_HANDLER);
		//DEFAULT_HANDLER(I2C1_ER_HANDLER);
		DEFAULT_HANDLER(I2C2_EV_HANDLER);
		DEFAULT_HANDLER(I2C2_ER_HANDLER);
		DEFAULT_HANDLER(SPI1_HANDLER);
		DEFAULT_HANDLER(SPI2_HANDLER);
		DEFAULT_HANDLER(USART1_HANDLER);
		DEFAULT_HANDLER(USART2_HANDLER);
		DEFAULT_HANDLER(EXTI15_10_HANDLER);
		DEFAULT_HANDLER(EXTI17_RTC_ALARM_HANDLER);
		DEFAULT_HANDLER(EXTI18_OTG_FS_WKUP_HANDLER);
		DEFAULT_HANDLER(DMA1_STREAM7_HANDLER);
		DEFAULT_HANDLER(SDIO_HANDLER);
		DEFAULT_HANDLER(TIM5_HANDLER);
		DEFAULT_HANDLER(SPI3_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM0_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM1_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM2_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM3_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM4_HANDLER);
		DEFAULT_HANDLER(OTG_FS_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM5_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM6_HANDLER);
		DEFAULT_HANDLER(DMA2_STREAM7_HANDLER);
		DEFAULT_HANDLER(USART6_HANDLER);
		DEFAULT_HANDLER(I2C3_EV_HANDLER);
		DEFAULT_HANDLER(I2C3_ER_HANDLER);
		DEFAULT_HANDLER(FPU_HANDLER);
		DEFAULT_HANDLER(SPI4_HANDLER);
	
	void Reset_Handler (void);
	void init_data (void);
	void init_bss (void);
	void init_system (void);
	int main(void);
	void toggle_LED(void);
	
	void HARD_FAULT_HANDLER(void);
	void USAGE_FAULT_HANDLER(void);
	void TIM2_HANDLER(void);
	void I2C1_ER_HANDLER(void);
	void I2C1_EV_HANDLER(void);
	void I2C1_transmitt(i2c_transmission_t);
	
		//System Control Block Register
		volatile unsigned int* CCR = (unsigned int*) 0xE000ED14;
		
		//NVIC Register
		volatile unsigned int* NVIC_ISER0 = (unsigned int*)( NVIC_Base + 0x100); 
		volatile unsigned int* NVIC_ISER1 = (unsigned int*)( NVIC_Base + 0x100 + (0x04 * 1)); 
		volatile unsigned int* NVIC_IPR7 = (unsigned int*) (NVIC_Base + 0x400 + (0x04 * 7));
		volatile unsigned int* NVIC_IPR8 = (unsigned int*) (NVIC_Base + 0x400 + (0x04 * 8));
		
		volatile unsigned int* NVIC_ICPR0 = (unsigned int*)( NVIC_Base + 0x280);
		volatile unsigned int* NVIC_ICPR1 = (unsigned int*) (NVIC_Base + 0x280 + 0x04);
		
		//RCC Register
		volatile unsigned int* RCC_AHB1ENR =(unsigned int*)(  RCC_Base + 0x30);
		volatile unsigned int* RCC_APB1ENR = (unsigned int*) (RCC_Base + 0x40);
		volatile unsigned int* RCC_APB1RSTR = (unsigned int*) (RCC_Base + 0x20);
		volatile unsigned int* RCC_APB1LPENR = (unsigned int*) (RCC_Base + 0x60);		
		
		//GPIO Register
		volatile unsigned int* GPIOA_MODER = (unsigned int*)( GPIOA_Base);
		volatile unsigned int* GPIOB_MODER = (unsigned int*) (GPIOB_Base);
		volatile unsigned int* GPIOC_MODER = (unsigned int*) (GPIOC_Base);
		volatile unsigned int* GPIOD_MODER = (unsigned int*) (GPIOD_Base);
		volatile unsigned int* GPIOA_OTYPER = (unsigned int*) (GPIOA_Base + 0x04);
		volatile unsigned int* GPIOB_OTYPER = (unsigned int*)( GPIOB_Base + 0x04);
		volatile unsigned int* GPIOC_OTYPER = (unsigned int*)( GPIOC_Base + 0x04);
		volatile unsigned int* GPIOD_OTYPER = (unsigned int*)( GPIOD_Base + 0x04);
		volatile unsigned int* GPIOA_BSRR = (unsigned int*) (GPIOA_Base + 0x18);
		
		volatile unsigned int* GPIOB_AFRL = (unsigned int*)( GPIOB_Base + 0x20);
		volatile unsigned int* GPIOB_AFRH = (unsigned int*) (GPIOB_Base + 0x24);
		
		//I2C Register
		volatile unsigned int* I2C1_CR1 = (unsigned int*)( I2C1_Base);
		volatile unsigned int* I2C1_CR2 = (unsigned int*) (I2C1_Base + 0x04);
		volatile unsigned int* I2C1_OAR1 = (unsigned int*)( I2C1_Base + 0x08);
		volatile unsigned int* I2C1_CCR = (unsigned int*) (I2C1_Base + 0x1C);
		volatile unsigned int* I2C1_TRISE = (unsigned int*) (I2C1_Base + 0x20);
		volatile unsigned int* I2C1_DR = (unsigned int*) (I2C1_Base + 0x10);
		volatile unsigned int* I2C1_SR1 = (unsigned int*)( I2C1_Base + 0x14);
		volatile unsigned int* I2C1_SR2 = (unsigned int*) (I2C1_Base + 0x18);
		
		//Timer Register
		volatile unsigned int* TIM2_PSC = (unsigned int*) (TIM2_Base + 0x28);
		volatile unsigned int* TIM2_ARR = (unsigned int*) (TIM2_Base + 0x2C);
		volatile unsigned int* TIM2_CR1 = (unsigned int*) (TIM2_Base);
		volatile unsigned int* TIM2_EGR = (unsigned int*)( TIM2_Base + 0x14);
		volatile unsigned int* TIM2_DIER = (unsigned int*) (TIM2_Base + 0x0C);
		volatile unsigned int* TIM2_SR = (unsigned int*) (TIM2_Base + 0x10);
	
	
	__attribute__((section(".isr_vector"))) isr_handler isr_vector_table[] = {

		(isr_handler)&_stack_top, //000
		Reset_Handler,	//004
		NMI_Handler,	//008
		HARD_FAULT_HANDLER,		//00C
		MEM_MANAGE_HANDLER,	//010
		BUS_FAULT_HANDLER,		//014
		USAGE_FAULT_HANDLER,	//018
		0,	//01c
		0,	//020
		0,	//024
		0,	//028
		SVCALL_HANDLER,	//02c
		DEBUG_MONITOR_HANDLER,	//030
		0,	//034
		PENDSV_HANDLER,	//038
		SYSTICK_HANDLER,	//03c
		WWDG_HANDLER,	//040
		EXTI16_PVD_Handler,//044
		EXTI21_TAMP_STAMP_HANDLER,//048
		EXTI22_RTC_WKUP_HANDLER,//04c
		FLASH_HANDLER,//050
		RCC_HANDLER,//054
		EXTI0_HANDLER,//058
		EXTI1_HANDLER,//05c
		EXTI2_HANDLER,//060
		EXTI3_HANDLER,//064
		EXTI4_HANDLER,//068
		DMA1_STREAM0_HANDLER,//06c
		DMA1_STREAM1_HANDLER,//070
		DMA1_STREAM2_HANDLER,//074
		DMA1_STREAM3_HANDLER,//078
		DMA1_STREAM4_HANDLER,//07c
		DMA1_STREAM5_HANDLER,//080
		DMA1_STREAM6_HANDLER,//084
		ADC_HANDLER,//088
		0,// 08c
		0,//090
		0,//094
		0,//098
		EXTI9_5_HANDLER,//09c
		TIM1_BRK_TIM9_HANDLER,//0A0
		TIM1_UP_TIM10_HANDLER,//0A4
		TIM1_TRG_COM_TIM11_HANDLER,//0a8
		TIM1_CC_HANDLER,//0ac
		TIM2_HANDLER,//0b0
		TIM3_HANDLER,//0b4
		TIM4_HANDLER,//0b8
		I2C1_EV_HANDLER,//0bc	Interrupt Number 31
		I2C1_ER_HANDLER,//0c0	Interrupt Number 32
		I2C2_EV_HANDLER,//0c4
		I2C2_ER_HANDLER,//0c8
		SPI1_HANDLER,//0cc
		SPI2_HANDLER,//0d0
		USART1_HANDLER,//0d4
		USART2_HANDLER,//0d8
		0,//0dc
		EXTI15_10_HANDLER,//0e0
		EXTI17_RTC_ALARM_HANDLER,//0e4
		EXTI18_OTG_FS_WKUP_HANDLER,//0e8
		0,//0ec
		0,//0f0
		0,//0f4
		0,//0f8
		DMA1_STREAM7_HANDLER,//0fc
		0,//100
		SDIO_HANDLER,//104
		TIM5_HANDLER,//108
		SPI3_HANDLER,//10c
		0,//110
		0,//114
		0,//118
		0,//11c
		DMA2_STREAM0_HANDLER,//120
		DMA2_STREAM1_HANDLER,//124
		DMA2_STREAM2_HANDLER,//128
		DMA2_STREAM3_HANDLER,//12c
		DMA2_STREAM4_HANDLER,//130
		0,//134
		0,//138
		0,//13c
		0,//140
		0,//144
		0,//148
		OTG_FS_HANDLER,//14c
		DMA2_STREAM5_HANDLER,//150
		DMA2_STREAM6_HANDLER,//154
		DMA2_STREAM7_HANDLER,//158
		USART6_HANDLER,//15c
		I2C3_EV_HANDLER,//160
		I2C3_ER_HANDLER,//164
		0,//168
		0,//16c
		0,//170
		0,//174
		0,//178
		0,//17c
		0,//180
		FPU_HANDLER,//184
		0,//188
		0,//18c
		SPI4_HANDLER//190
	};
	
	void Reset_Handler (void) {
		
		init_bss();
		init_data();
		init_system();
		main();

	} 
	
	void HARD_FAULT_HANDLER(void){
		
		*GPIOA_BSRR &= ~(0x01 << 5); //clear PA5 set
		*GPIOA_BSRR &= ~(0x01 << 21); //clear PA5 reset
		*GPIOA_BSRR |= (0x01 << 21); //set Pin A5 off
		
		while(1);
	}
	
	void USAGE_FAULT_HANDLER(void){
		
		*GPIOA_BSRR &= ~(0x01 << 5); //clear PA5 set
		*GPIOA_BSRR &= ~(0x01 << 21); //clear PA5 reset
		*GPIOA_BSRR |= (0x01 << 21); //set Pin A5 off
		
		while(1);
	}

	void init_data (void){

		unsigned long* data_flash = &_sidata;
		unsigned long* data_sram = &_sdata;
		unsigned long* data_sram_end = &_edata;
		while(data_sram < data_sram_end){
			*(data_sram++) = *(data_flash++);
		} 
	}

	void init_bss (void){
		unsigned long* bss = &_sbss;
		unsigned long* bss_end = &_ebss;

		while(bss < bss_end){
			*(bss++) = 0;
		}
	}

	void init_system(void){
		
	/* System Control Block */
		*CCR |= (1<<4); //Trap div by zero
		
	/*	configure interrupts */
		
		*NVIC_IPR7 &= ~(0xFF);
		*NVIC_IPR8 &= ~(0xFF);	//reset priorities
		
		*NVIC_IPR7 |= (200); //set Timer Interrupt to low priority level
		*NVIC_ISER0 |= (0x01<<28); //enable timer 2 interrupt
		
		
		*NVIC_IPR7 |= (100<<(8*3)); //set medium priority for i2c1_ev
		*NVIC_IPR8 |= (100); //set medium priority for i2c1_er
		*NVIC_ISER0 |= (0x01<<31); //Enable I2C1_EV isr
		*NVIC_ISER1 |= 0x01; 	   //Enable I2C1_ER isr
		
	
	/*	configure GPIO Pins */
	
	
		*RCC_AHB1ENR |= 0x01; //Enable Clock for Port A
		*RCC_AHB1ENR |= 0x02; //Enable Clock for Port B
		*RCC_AHB1ENR |= 0x04; //Enable Clock for Port C
		*RCC_AHB1ENR |= 0x08; //Enable Clock for Port D

		*GPIOA_MODER &= ~(0x03<<(5*2));
		*GPIOA_MODER |= (0x01<<(5*2)); //set Pin A5 to General purpose output mode
		
		*GPIOA_OTYPER &= ~(0x01<<5); //set Pin A5 as Push-Pull;
		
		//PB8 -> I2C1_SCL | AF04
		//PB9 -> I2C1_SDA | AF04
		*GPIOB_AFRH |= 0x44; //set PB8&PB9 to AF04 0b0100_0100
		
		*GPIOB_MODER &= ~(0xF<<(8*2)); //clear Mode pf  PB8&PB9
		*GPIOB_MODER |= (0xA<<(8*2)); //Set PB8&PB9 to Alternate Function Mode (0b1010)
		
		*GPIOB_OTYPER |= (0x03<<8); //Set PB8&PB9 as Open Drain

	/* Configure I2C Bus */
		
		*RCC_APB1ENR |= (0x01<<21);		//enable clock for i2c1
		
		*RCC_APB1RSTR |= (0x01<<21);
		*RCC_APB1RSTR &= ~(0x01<<21);	//reset i2c1
		
		*I2C1_CR1 |= (0x01<<15);
		*I2C1_CR1 &= ~(0x01<<15);	// software reset i2c1
		
		*I2C1_CR1 &= ~(0x01); //disable Peripheral
		
		*I2C1_OAR1 |= (0x01<<14); //Bit 14 must be kept on 1
		*I2C1_OAR1 &= ~(0x01<<15); // 7bit Adressing
		
		*I2C1_OAR1 |= (0x3F<<1); // set own Adress
		
		*I2C1_CR2 |= (0x08); //4 MHz Peripheral Clock
		*I2C1_CR2 |= (0x07<<8); //enable Evt, Buffer and Err interrupts
		
		
		*I2C1_CCR &= ~(0x01<<15); // I2C SM
		*I2C1_CCR |= (0x28); // 4MHz / 40 = 100KHz Clk speed
		
		*I2C1_TRISE &= ~(0x3F);
		*I2C1_TRISE |= 0x09; //Set Rise Time
		
		*I2C1_CR1 |= 0x01; //enable Peripheral
		
	/* configure 32bit Timer TIM2 for delay */
		
		*RCC_APB1ENR |= 0x01; //enable clock for TIM2
	
		*TIM2_CR1 &= ~0x01; //make sure Timer 2 is off
	
		*RCC_APB1RSTR |= 0x01;
		*RCC_APB1RSTR &= ~0x01;		//reset timer 2
	
		*TIM2_PSC = 8000; //set prescale
		*TIM2_ARR = 2000; // set autoreload
	
		*TIM2_EGR |= 0x01; //Send update event to reset timer and apply settings
	
		*TIM2_DIER |= 0x01; //enable Update Interrupt

		*TIM2_CR1 |= 0x01; //enable Timer 2
	}
	
	
	void TIM2_HANDLER(void){
		
		volatile static int state = 0;
		
		if(state == 0){	//turn LED on if it is off
			*GPIOA_BSRR &= ~(0x01 << 5); //clear PA5 set
			*GPIOA_BSRR &= ~(0x01 << 21); //clear PA5 reset
			*GPIOA_BSRR |= (0x01 << 5); //set Pin A5 on
			
			state = !state;
		}
		else{	//turn LED off if it is on
			*GPIOA_BSRR &= ~(0x01 << 5); //clear PA5 set
			*GPIOA_BSRR &= ~(0x01 << 21); //clear PA5 reset
			*GPIOA_BSRR |= (0x01 << 21); //set Pin A5 off
			
			state = !state;
		}
		
			*TIM2_SR &= ~(0x01);	//clear Update Interrupt flag
			*NVIC_ICPR0 |= (0x01<<28);	//clear pending state of Timer Interrupt

	}
	
	
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
	
	
	void I2C1_ER_HANDLER(void) {
		
		*GPIOA_BSRR &= ~(0x01 << 5); //clear PA5 set
		*GPIOA_BSRR &= ~(0x01 << 21); //clear PA5 reset
		*GPIOA_BSRR |= (0x01 << 21); //set Pin A5 off
		while(1);
		
		*NVIC_ICPR1 |= (0x01); //clear pending bit
	}
	
	void I2C1_transmitt(i2c_transmission_t tx_data){
		
		i2c_tx.adress = tx_data.adress;
		i2c_tx.len = tx_data.len;
		i2c_tx.buffer = tx_data.buffer;
		i2c_tx.pos = -2;	//init global struct from data
		
		//	Set Start Condition
		*I2C1_CR1 |= (0x01<<8); //generate Start condition

	}
	
	int main(void){
		
		i2c_transmission_t oled_command;
		oled_command.adress = OLED_Adress_LOW;
		oled_command.len = 6+2144+172; // 166 -> HELLO WORLD!
		char data[oled_command.len];
		
		/* display hello word */
		
		//display starts at com0 and line 0 
		//page adress commands: 0xB0 - 0xB7
		
		data[oled_command.len-6] = 0x80;
		data[oled_command.len-5] = 0x81;
		data[oled_command.len-4] = 0x80;
		data[oled_command.len-3] = 0x80; // set contrast 
		
		data[oled_command.len-2] = 0x00;
		data[oled_command.len-1] = 0xAf; // turn display on
		
		//set every page white;
		for(int j = 0; j < 8; j++){
			data[j*268+0] = 0x80;
			data[j*268+1] = 0xB0 + j;	//set page
			
			data[j*268+2] = 0x80;
			data[j*268+3] = 0x00;
			data[j*268+4] = 0x80;
			data[j*268+5] = 0x10;	//reset column on page change
			
			for(int i = 6; i < 268; i = i + 2){	//clear to black
				data[j*268+i] = 0xC0;
				data[j*268+i+1] = 0x00;
			}
		}
		
		
		
		/* print Hello world*/
		
		int current_pos = 2144; //131 columns * 2 for control bytes * 8 for all pages = 2144
	
		//6B setup
		data[current_pos] = 0x80; current_pos++;
		data[current_pos] = 0xB3; current_pos++;	//page 4
		
		data[current_pos] = 0x80; current_pos++;
		data[current_pos] = 0x04; current_pos++;	
		data[current_pos] = 0x80; current_pos++;
		data[current_pos] = 0x11; current_pos++;	//column 4
		
		//HELLO WORLD
		
		//2 space bars + ! - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFD; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//D - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x18; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x24; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x42; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x81; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//L - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//R - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x61; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x92; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x94; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x98; current_pos++;		
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;		
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;	
		
		//O - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x3C; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x7E; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x81; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x7E; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x3C; current_pos++;
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
				
		//W - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFC; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x03; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x3C; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x03; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFC; current_pos++;
				
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
				
		//O - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x3C; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x7E; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x81; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x7E; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x3C; current_pos++;
		
				
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//L - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
		
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
				
		//L - 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x01; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
			
		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
	
		//E	- 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x91; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x91; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x91; current_pos++;

		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x91; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;	

		//3 space bars - 6B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x00; current_pos++;
		
		//H	- 10B
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x08; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x08; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0x08; current_pos++;
		
		data[current_pos] = 0xC0; current_pos++;
		data[current_pos] = 0xFF; current_pos++;
		

		oled_command.buffer = data;
		oled_command.pos = -2;
		
		I2C1_transmitt(oled_command);
		while(1);
		
		return 0;
	}


	