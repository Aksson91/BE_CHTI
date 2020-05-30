
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
     
