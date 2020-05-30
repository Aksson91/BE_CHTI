#include <gassp72.h>
#include <etat.h>
#define Periode_en_Tck 72*PeriodeSonMicroSec //correspond a la periode du son en tck // le microprocesseur a une frequence d'horloge de 72Mhz 
#define Periode_PWM_en_Tck  72*18.2 //= 1310 la resolution // 1/(10989,01*5) = 18.2 *10^-6 sec = frequence d'echantillonage * frequence de modulation afin d'avoir une frequence >> 20Khz

extern void timer_callback(void);

// Les variables Son,LongueurSon et PeriodeSonMicroSec sont presentes dans le fichier bruitverre.asm
extern short Son;
extern int LongueurSon;
extern int PeriodeSonMicroSec;

type_etat etat_son;

int main(void)
{
//Initialisation des valeurs de la structure etat_son
etat_son.son = &Son;
etat_son.position = 0;
etat_son.taille = LongueurSon;
etat_son.periode_ticks = Periode_en_Tck; // on veut avoir un echantillon toute les peeriodesonmicrosec X frequence d'horloge

// activation de la PLL qui multiplie la fréquence du quartz par 9
CLOCK_Configure();
// config port PB1 pour être utilisé en sortie
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
	
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);

etat_son.resolution = PWM_Init_ff( TIM3, 3, Periode_PWM_en_Tck );
// initialisation du timer 4
// Periode_en_Tck doit fournir la durée entre interruptions,
// exprimée en périodes Tck de l'horloge principale du STM32 (72 MHz)
 Timer_1234_Init_ff( TIM4, Periode_en_Tck );
	
// enregistrement de la fonction de traitement de l'interruption timer
// ici le 2 est la priorité, timer_callback est l'adresse de cette fonction, a créér en asm,
// cette fonction doit être conforme à l'AAPCS
Active_IT_Debordement_Timer( TIM4, 2, timer_callback);
// lancement des timers
Run_Timer( TIM3);
Run_Timer( TIM4 );

while	(1)
	{
	}
}
