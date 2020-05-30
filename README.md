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
