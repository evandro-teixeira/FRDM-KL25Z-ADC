/*
Projeto: Aplicação com Biblioteca ADC 
*/
#include "MKL25Z4.h"
#include "adc.h"
#include "gpio.h"

uint32_t i = 0;
uint16_t adc = 0;

int main(void)
{

	adc_init( _16BIT ); // Inicializa ADC
	gpio_direction(PORT_B,18,OUTPUT,NO_PULL_RESISTOR); // Inicializa IO PTB18 - LED Vermelho
	gpio_direction(PORT_B,19,OUTPUT,NO_PULL_RESISTOR); // Inicializa IO PTB19 - LED Verde

	gpio_set(PORT_B,19,1); // Desliga LED vermelho
	gpio_set(PORT_B,18,1); // Desliga LED verde

    for (;;)
    {
    	adc = adc_read( ADC_5 );	// Le ADC ~ PTB1

    	if(adc > 50000)
    	{
    		gpio_set(PORT_B,19,0); // Liga LED vermelho
    		gpio_set(PORT_B,18,1); // Desliga LED verde
    	}
    	else
    	{
    		gpio_set(PORT_B,18,0); // Liga LED verde
    		gpio_set(PORT_B,19,1); // Desliga LED vermelho
    	}
	}
}