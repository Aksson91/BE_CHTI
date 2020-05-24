

; ce programme est pour l'assembleur RealView (Keil)
	thumb 
	import TabCos;
	import TabSin;	
	import TabSig;		
	area mesdata, data, readwrite
		
	area  moncode, code, readonly

	export modulo
	export Reel
	export Imaginaire		
;
N equ 64;
mod equ 0x3F; permet d'effectuer un modulo 64 	
	
modulo proc

	; k est stock� dans r0, l'adresse du signal dans r1, Reel dans r3, L'Imaginaire dans r2

	push {lr, r4-r7} ; on push les regitres allant de r4 à r7 et lr
	ldr r1, =TabSig ; on charge l'adresse du signal dans r1 
	
	bl Reel; appel de la procedure pour calculer le reel 
	
	mov r3, r6 ; on stock la valeur du reel(Re(k)) contenu dans r6 dans r3
	mov r6, #0 ; On met r6 à zero avant le calcul de l'imaginaire
	push {r3}
	
	bl Imaginaire;appel de la procedure pour calculer l'imaginaire 
	
	mov r2, r6; on stock la valeur de l'imaginaire(Im(k)) contenu dans r6 dans r2
	pop {r3}
	
	smull r4, r5,r3,r3; Calcul de (Re(k))² 

	smlal r4, r5, r2, r2 ; Calcul de M2= (Im(k))²+(Re(k))²;
	mov r0, r5; Stock M2 dans r0 pour le retour final
	pop {r4-r7}
	pop {pc}

	bx lr
	endp

	
Reel proc

	mov r12,#0x00 ; r12 contient la valeur de i, mise à 0
	ldr r2, =TabCos; on recupere l'adresse de TabCos et on le stock dans r2
	b loop
	endp
	
Imaginaire proc

	mov r12,#0x00; on initialise i à 0, pour s'assurer que i est bien égale à 0 au début de la boucle 
	ldr r2,=TabSin; on recupere l'adesse de TabSin et on le stock dans r2
	b loop
	endp
	

loop
	mul r5,r12,r0 ; calcul de ik
	and r5, #mod; ik modulo 64 
	ldrsh r4,[r2,r5,lsl #0x01]; valeur de sin(ik) ou (cos(ik)
	ldrsh r3,[r1,r12,lsl #0x01]; valeur du signal x(i); 
	mul r7,r3,r4;valeur de la multiplication du cos ou sin avec x(i)
	add r6,r7; somme de l'ensemble des valeurs;

	add r12, #0x01; incr�mentation de i
	cmp r12, #N ; compare si i = N quitte la boucle si ce n'est pas le cas
	bne loop
	
	b fin
 
fin proc

	bx lr
	endp	

	end


