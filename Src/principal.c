#include <gassp72.h>

#define SYSTICK_PER 360000 // 5*72000=> periode du traitement fois le temps d'horloge de la carte du microcontroleur
#define M2TIR 985661 // constante calcule permettant de valider un tir laser

extern int modulo(int,unsigned short*);//importation de notre fonction calculant M2K du fichier DFT.s (realise dans l'etape 2)
static int score[6]={0,0,0,0,0,0}; //tableau des scores 
int occurence[6]={0,0,0,0,0,0}; //tableau des occurences
unsigned short dma_buf[64];// buffer dma de 64 echantillons 
int pistolet[6] = {17,18,19,20,23,24};// k des pistolets

void sys_callback(){
	GPIO_Set(GPIOB, 1);
	// Démarrage DMA pour 64 points
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	
	for(int i =0;i<6;i++){
	
		 
		if(modulo(pistolet[i],dma_buf)>=M2TIR){ //si M2k du tir laser est superieur a M2TIR alors on incremente le nombre d'occurence du tir
			occurence[i]++; //mise a jour de l'occurence
		}
		else{
			occurence[i]=0;
		}
		if(occurence[i]==11){ // il y a maximum 20 occurences donc avec 11 occurences on ne peut pas compter 2 fois le même tir => le tir est valide
			score[i]=score[i]+1; // mise a jour du score
			GPIO_Set(GPIOB,14); // allumer la led
		}
		else if(occurence[i]==0){
			GPIO_Clear(GPIOB,14); // eteindre la led
		}
	}
	GPIO_Clear(GPIOB, 1);
}	
	
int main(void)
{
// activation de la PLL qui multiplie la fréquence du quartz par 9
CLOCK_Configure();
// PA2 (ADC voie 2) = entrée analog
GPIO_Configure(GPIOA, 2, INPUT, ANALOG);
// PB1 = sortie pour profilage à l'oscillo
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
// PB14 = sortie pour LED
GPIO_Configure(GPIOB, 14, OUTPUT, OUTPUT_PPULL);

// activation ADC, sampling time 1us
Init_TimingADC_ActiveADC_ff( ADC1, 0x43 );
Single_Channel_ADC( ADC1, 2 );
// Déclenchement ADC par timer2, periode (72MHz/320kHz)ticks
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
// Config DMA pour utilisation du buffer dma_buf (a créér)
Init_ADC1_DMA1( 0, dma_buf );

// Config Timer, période exprimée en périodes horloge CPU (72 MHz)
Systick_Period_ff( SYSTICK_PER );
// enregistrement de la fonction de traitement de l'interruption timer
// ici le 3 est la priorité, sys_callback est l'adresse de cette fonction, a créér en C
Systick_Prio_IT( 3, sys_callback );
SysTick_On;
SysTick_Enable_IT;



while	(1){
		
}
}
