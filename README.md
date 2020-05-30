
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
