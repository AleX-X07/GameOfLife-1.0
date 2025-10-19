# Game OF Life
Le **jeu de la Vie** (Game of Life) est un automate cellulaire (devenu un jeu de simulation mathématique) imaginé par John Horton Conway en 1970.
## Description du projet : 
Le jeu se déroule sur une grille à deux dimensions, dont les cases (appelées « cellules », par analogie avec les cellules vivantes) peuvent prendre deux états distincts : « vivante » ou « morte ».
Une cellule possède huit voisines, qui sont les cellules adjacentes horizontalement, verticalement et diagonalement.
À chaque itération, l'état d’une cellule est entièrement déterminé par l’état de ses huit cellules voisines, selon les règles suivantes :
- Si une cellule a exactement trois voisines vivantes, elle est vivante à l’étape suivante.
- Si une cellule a exactement deux voisines vivantes, elle reste dans son état actuel à l’étape suivante.
- Si une cellule a strictement moins de deux ou strictement plus de trois voisines vivantes, elle est morte à l’étape suivante.

