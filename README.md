# Game OF Life

Le **jeu de la Vie** (Game of Life) est un automate cellulaire (devenu un jeu de simulation mathématique) imaginé par John Horton Conway en 1970.

## Description du projet : 

Le jeu se déroule sur une grille à deux dimensions, dont les cases (appelées « cellules », par analogie avec les cellules vivantes) peuvent prendre deux états distincts : **« vivante »** ou **« morte »**.
Une cellule possède huit voisines, qui sont les cellules adjacentes horizontalement, verticalement et diagonalement.
À chaque itération, l'état d’une cellule est entièrement déterminé par l’état de ses huit cellules voisines, selon les règles suivantes :
- Si une cellule a exactement trois voisines vivantes, elle est vivante à l’étape suivante.
- Si une cellule a exactement deux voisines vivantes, elle reste dans son état actuel à l’étape suivante.
- Si une cellule a strictement moins de deux ou strictement plus de trois voisines vivantes, elle est morte à l’étape suivante.

## Fonctionnement du programme :

L'utilisateur choisi une entrée manuel ou alors par fichier texte. Dans les deux cas, il devra choisr : 
- Les dimensions de la grille,
- Le temps entre 2 itérations,
- Le nombre de cellules vivantes à la première itération,
- Les coordonnées des cellules vivantes lors de la permière itération.

Pour un choix manuel, tout se fait dans la console.
Pour le fichier texte, il suffi d'écrire ce qui est demander dans un fichier texte et mettre ce fichier dans le même document que le cpp du jeu.
<img width="1123" height="633" alt="image" src="https://github.com/user-attachments/assets/d7386e69-63ca-4710-8992-73652191cc7b" />


A partir de là, l'utilisateur peut :
- Modifier la vitesse avec "Q" et "D",
- Arrêter le programme avec "Echap",
- Faire pause avec "Espace".

Pendant la pause, il peut : 
- Reprendre avec "Espace",
- Recommencer une simulation avec "R".

## Disponible pour toute question :
- LinkedIn : https://www.linkedin.com/in/alex-soulier/
- Mail : asoulier@gaming.tech

