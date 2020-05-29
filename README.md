# Bureau d'étude CHTI
Bienvenue sur le répertoire GIT du Bureau d'étude CHTI de Dany LAU et Alexandre AL AJROUDI, étudiants en 3MIC à l'INSA Toulouse.  

Vous pouvez consulter les différents objectifs réalisés en allant sur la branche de l'objectif:
[OBJECTIF 1](https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_1)
[OBJECTIF 2](https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_2)
N'hesitez pas à lire nos conseils d'utilisation pour chaque branche afin de réaliser les tests adéquats.

Cordialement,  

AL AJROUDI Alexandre et LAU Dany

# OBJECTIF 1
L'objectif 1 permet de réaliser un programme en ASM permettant de calculer le module mis au carré (M2K) de la DFT au rang k.

Instructions pour les tests :
Télécharger les fichiers d'essais fournies , déplacer dans le dossier /src et les renommer à chaque changement de fichiner Signal.s 
Placer un point d'arrêt sur la boucle while{1} dans le fichier principale.c 
Lancer le debuger puis faîtes run(F5) et à l'aide de l'outil watcher1, analyser les valeurs de tab et vous devriez retrouver des valeurs qui coïncident avec celles écrites en commentaire dans le fichier Signal.s

# OBJECTIF 2
L'objectif 2 permet de simuler et de valider des tirs lasers afin d'afficher des scores.

Instructions pour les tests :
Placer un point d'arrêt sur la boucle while{1} et sur l'instruction GPIO_Set(GPIOB, 14) afin de voir l'évolution des scores.
Lancer le debuger puis faîtes run(F5) et à l'aide de l'outil watcher1, analyser les valeurs de score et vous devriez voir une évolution des scores qui corresponds aux tirs lasers validés. Vous pouvez constater en ouvrant le logic analyzer l'évolution des variables d'occurences.

# OBJECTIF 3
L'objectif 3 permet le déclenchement de l'émission d'un son.

Instructions pour les tests :
Lancer le debuger puis faîtes run(F5) et ouvrez le logic analyzer afin de visualiser l'emission du son correspondant au fichier bruitverre.asm.
(Instructions pour les 91micros secs a venir...)

# OBJECTIF 4
L'objectif 4 regroupe l'objectif 2 et 3 et consiste à déclencher l'émission d'un son à chaque tir laser validé tout en affichant les scores.

Instructions pour les tests :
Lancer le debuger puis faîtes run(F5) et ouvrez le logic analyser afin de visualiser l'emission du son correspondant au fichier au bruitverre.asm à chaque tir laser validé tout en mettant à jour les scores que vous pouvez vérifier à l'aide de l'outil watcher1.



