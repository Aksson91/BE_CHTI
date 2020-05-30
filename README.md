# Bureau d'étude CHTI
Bienvenue sur le répertoire GIT du Bureau d'étude CHTI de Dany LAU et Alexandre AL AJROUDI, étudiants en 3MIC à l'INSA Toulouse. Ce projet nécessite l'utilisation d'un environnement de travail Windows ainsi que l'installation du logiciel Keil.
<dl><dt>Nous souhaitons remercier Monsieur Thierry Rocacher ainsi que Monsieur Jean-Louis Noullet qui nous ont encandré dans la réalisation de ce bureau d'étude.</dt></dl>

Vous pouvez consulter les différents objectifs réalisés en allant sur la branche de l'objectif :
<dl>
  <dt><a href="https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_1">OBJECTIF 1<a/></dt>
  <dt><a href="https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_2">OBJECTIF 2<a/></dt>
  <dt><a href="https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_3">OBJECTIF 3<a/></dt> 
  <dt><a href="https://github.com/Aksson91/BE_CHTI/tree/OBJECTIF_4">OBJECTIF 4<a/></dt>
</dl>
N'hesitez pas à lire nos conseils d'utilisation pour chaque branche afin de réaliser les tests adéquats.

Cordialement,  

AL AJROUDI Alexandre et LAU Dany

## Conseils d'utilisation OBJECTIF 1
L'objectif 1 permet de réaliser un programme en ASM permettant de calculer le module mis au carré (M2K) de la DFT au rang k.

#### Instructions pour les tests :
<dl>
  <dt> Instructions pour tester la valeur M2 de tous les k (Procédure rapide)</dt>
  <dd>1) Lancez projet.uvprojx</dd>
  <dd>2) Placez un point d'arrêt dans la boucle while{1} dans le fichier principale.c</dd>
  <dd>3) Build (F7)</dd>
   <dd>4) Start Debug Session (CTRL + F5) </dd>
   <dd>5) RUN (F5)</dd>
   <dd>6) Ouvrez l'outil watch windows</dd>
  <dt> Instructions pour tester la valeur M2, Re et Im (correspondants respectivement aux registres R0, R3 et R2) d'un certain k (Procédure longue) </dt>
  <dd>1) Placer un point d'arrêt dans la boucle for du fichier principal.c comme montré ci-dessous</dd>
  <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/objectif1pointd_arrettest2.png" width="340" height="280" /> <a/>
  <dd>2) Build (F7)</dd>
  <dd>3) Start Debug Session (CTRL + F5)</dd>
  <dd>4) RUN (F5) le nombre de k choisit </dd>
  <dt> Voici en exemple ce que nous obtenons pour k=17. Nous constatons que les valeurs présentes dans les registres correspondent bien aux valeurs indiqués en commentaire du fichier Signal.s</dt>
  <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/objectif1valsreIm.png" width="690" height="480" /> <a/>
</dl>

#### Remarque au lecteur:
Nous avons bien entendu réaliser tous les jeux de tests disponibles. Si vous souhaitez faire de même, vous pouvez télécharger les jeux de tests en cliquant sur ce <a href="https://noullet-gei.gitlab.io/asm/BE/TEST_DFT/test_DFT.7z">lien<a/> puis en renommant le jeu de test voulu par Signal.s et en le remplaçant par celui déjà présent dans le dossier /src.

## Conseils d'utilisation OBJECTIF 2
L'objectif 2 permet de simuler et de valider des tirs lasers afin d'afficher des scores.

#### Instructions pour les tests :
<dl>
  <dd>1) Lancez projet.uvprojx</dd>
  <dd>2) Placez un point d'arrêt dans la boucle while{1} (et sur l'instruction GPIO_Set(GPIOB, 14) si vous souhaitez profiter de chaque tir réussi) afin de voir l'évolution des scores dans le fichier principale.c</dd>
  <dd>3) Build (F7)</dd>
   <dd>4) Start Debug Session (CTRL + F5) </dd>
   <dd>5) RUN (F5) (plusieurs fois si vous avez placé un point d'arrêt sur l'instruction GPIO_Set(GPIOB, 14))</dd>
   <dd>6) Ouvrez le logic analyser et utiliser le boutton zoom pour bien visualiser l'évolution des variables d'occurences </dd>
  <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/OBJECTIF2.png" width="690" height="480" /> <a/>
   <dd>6) Ouvrez l'outil watch windows afin de visualiser l'évolution des scores correspondants aux tirs validés </dd>
    <dt>Vous devriez constater, qu'une fois le tableau des scores remplis, il contient respectivement les valeurs 1,2,3,4,5 et 15 (Ox0F) </dt>
    <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/OBJECTIF2SCORES.png" width="340" height="280" /> <a/>
</dl>

##  Conseils d'utilisation OBJECTIF 3
L'objectif 3 permet le déclenchement de l'émission d'un son.

#### Instructions pour les tests :
<dl>
  <dt> Instructions pour visualiser l'emission du son correspondant au fichier bruitverre.asm</dt>
  <dd>1) Lancez projet.uvprojx</dd>
  <dd>2) Ouvrez le logic analyzer</dd>
  <dd>3) RUN (F5)</dd>
   <dd>4) Utilisez le zoom dans le logic analyser pour visualiser l'emission du son </dd>
   <dt>5) Vous devriez obtenir l'allure suivante dans le logic analyser</dt>
  <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/Test1objectif3.png" width="690" height="480" /> <a/>
   <dt> Instructions pour vérifier que la durée entre chaque échantillon est de 91 microsecondes (à la suite de la première instruction</dt>
     <dd>1) Stop Debug Session (CTRL + F5)</dd>
  <dd>2) Mettez un point d'arrêt</dd>
     <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/Test2_1objectif3.png" width="340" height="280" /> <a/>
  <dd>3) Start Debug Session (CTRL + F5) </dd>
  <dd>3) RUN (F5) </dd>
  <dd>3) Réalisez un reset watch comme indiqué ci-dessous </dd>
   <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/Test2_2objectif3.png" width="340" height="280" /> <a/>
  <dd>3) RUN (F5) </dd>
   <dt> Vous devriez obtenir une durée de 91 microsecondes</dt>
     <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/Test2_3objectif3.png" width="140" height="80" /> <a/>
     
##  Conseils d'utilisation OBJECTIF 4
L'objectif 4 regroupe l'objectif 2 et 3 et consiste à déclencher l'émission d'un son à chaque tir laser validé tout en affichant les scores.

#### Instructions pour les tests :
<dl>
  <dt> Instructions pour visualiser l'emission du son à chaque tir validé</dt>
  <dd>1) Lancez projet.uvprojx</dd>
  <dd>2) Ouvrez le logic analyser</dd>
   <dd>3) RUN (F5)</dd>
<dl><df>Remarque : Nous avons diminuer la longueur du son afin de bien visualiser l'émission du son à chaque tir validé.
  Voici ce que vous devriez observer. N'hesitez pas à utiliser le boutton zoom dans le logic analyser.</df></dl>
  <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/Objectif4.png" width="690" height="480" /> <a/>
   <dl> <df>Vous pouvez constater qu'un bruit est émis après qu'il ait été validé, soit au bout de 11 occurences (afin d'éviter des doublons (cf code source))</df></dl>
   <a href="#"><img src="https://github.com/Aksson91/BE_CHTI/blob/OBJECTIF_4/ScreenTests/OBJECTIF4precis.png" width="690" height="480" /> <a/>
   <dl><df>Suivez les instructions de l'objectif 2 pour retrouvez les valeurs du tableau de score ;) </df></dl>
</dl>




