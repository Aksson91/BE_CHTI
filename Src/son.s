; ce programme est pour l'assembleur RealView (Keil)
	thumb
		
	include etat.inc
	import etat_son
	
	area  moncode, code, readonly
		
	export timer_callback
		
TIM3_CCR3	equ	0x4000043C	; adresse registre PWM
;

	
timer_callback	proc
	push {r4, r5}
	ldr r0,= etat_son ; r0 pointe sur l'adresse de la structure etat_son que l'on importe 	
	ldr r1,[r0, #E_POS] ; on charge la valeur de la position actuelle de l'echantillon dans r1
	ldr r2,[r0, #E_TAI] ; on charge la valeur du nombre total d'echantillons dans r2 
	ldr r3, [r0, #E_RES] ; on charge la valeur de la resolution dans r3	
	ldr r4, [r0, #E_SON] ; on charge la valeur du premier echantillon dans r4
	ldr r5,=TIM3_CCR3 ; r5 pointe sur l'adresse de la variable TIM3_CCR3
	
	cmp r2, r1 ; on compare r2 avec r1 pour savoir si on a parcourut tous les echantillons
	beq fin ; si oui alors fin de la procedure
	
	
	ldrsh r4, [r4, r1, LSL #1] ; on charge la valeur de l'echantillon correpondant a la position actuelle dans r4
	add r4, #32768 ; on y ajoute une composante continue qui vaut 32,768 car on a  -32,768< bruitdeverre <32,768 afin d'avoir une valeur comprise entre 0 et 2^16-1
	mul r4, r3
	lsr r4, #16
		
	str r4, [r5]
	
	add r1, #1
	str r1, [r0, #E_POS]
	

fin	
	pop {r4, r5}
	bx lr
	endp
	end
