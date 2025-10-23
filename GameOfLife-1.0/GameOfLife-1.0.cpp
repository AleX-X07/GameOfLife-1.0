#include <iostream> // Bibliothèque standard qui permet la communication entre le programme et les périphériques.(Ex : "cout" pour une sortie écran et "cin" pour une entrée clavier.)
#include <chrono>  // Bibliothèque qui permet de manipuler le temps.
#include<conio.h> // Bibliothèque qui permet de récupérer un input du clavier.
#include <fstream> // Bibliothèque qui permet de récupérer un fichier.

int main() {
    bool Restart = true;
    while (Restart) {
        int SizeX = 0; //Initialisation de valeur.Taille de la grille de jeu, SizeX pour les lignes, SizeY pour les colones, Size pour le nombre total de cellule dans la gille de jeu.
        int SizeY = 0;
        int Size = 0;
        int NbrCells = 0; //Nombre de cellules qe l'on rentre pour la première itération.
        bool Game = true; //Booléen de ma boucle principal.
        float Time = 0; // Temps entre deux itérations.
        float TimeStart = 0; // Temps donner par l'utilistateur.
        int ChoiceStart = 0; // Booléen pour choisir entre rentrer les commandes manuellement ou avec un fichier texte.

        std::cout << "Si il y a une valeur negatif dans le fichier txt, elle sera changee en valeur positive." << std::endl;
        std::cout << "Manuel [0] ou fichier txt [1] ? : "; //Choix manuel ou fichier txt.
        std::cin >> ChoiceStart; // Demande une entrée clavier pour un booléen. 1 ou 2.   
        if (ChoiceStart > 1) { // Mets la valeur de choix_entree à 1 si on choisi un chiffre plus grand que 1 et 0 si on choisi un chiffre plus petit que 0.
            ChoiceStart = 1;
        }
        else if (ChoiceStart < 0) {
            ChoiceStart = 0;
        }

        int* Cell = nullptr; // Initialisation du tableau


        // Fichier txt ou manuel : //


        if (ChoiceStart == 1) { // Choix par fichier txt
            std::ifstream File("config.txt"); // Récupération du fichier
            if (!File) { // Vérification de l'existance du fichier
                std::cerr << "Erreur d'ouverture du fichier !" << std::endl;
                break;
            }

            File >> SizeX >> SizeY; // Récupère les valeurs présente dans le fichier ligne par ligne. Donc pour la premiere, les valeurs sont mises dans les variables SizeX et SizeY.
            File >> Time;
            File >> NbrCells;
            if (SizeX <= 0) {
                SizeX = SizeX * (-1);
            }
            if (SizeY <= 0) {
                SizeY = SizeY * (-1);;
            }
            if (Time <= 0) {
                Time = Time * (-1);
            }
            if (NbrCells <= 0) {
                NbrCells = NbrCells * (-1);
            }

            Size = SizeX * SizeY; // On modifie la valeur de Size pour qu'il soit égale au nombre de cellule présent dans notre grille de jeu.
            Cell = new int[Size]; // On mets la taille du tableau à la taille de la grille de jeu pour stocker toute la grille dans un seul tableau.

            for (int i = 0; i < Size; i++) { // Mets toutes les valeurs du tableau à 0.
                Cell[i] = 0;
            }

            for (int i = 0; i < NbrCells; i++) { // Boucle qui créer le nombre de cellules qu'on veut mettre dans la grille de jeu lors de la première itération.
                int X = 0, Y = 0;
                File >> X >> Y;
                if (X <= 0) {
                    X = X * (-1);
                }
                if (Y <= 0) {
                    Y = Y * (-1);
                }
                int ActualCoor = X * SizeY + Y; // Calcule la coordonnées où on est actuellement dans le tableau.
                if (ActualCoor < Size) { // Vérifie que la coordonnée est bien présente dans le tableau.
                    Cell[ActualCoor] = 1; // C hange la valeur à l'endroit du tableau prévu pour rendre la cellules vivantes.
                }
                else { //Stop le programme et prévient l'utilisateur si les coordonnées rentrées sont hors du tableau.
                    std::cout << "Les coordonnees sont en dehors du tableau !" << std::endl;
                    Game = false;
                    i = NbrCells;
                    std::cout << "Le programme s'est arreter. " << std::endl;
                }
            }
        }

        else { // Choix manuel.

            std::cout << "Dimension de la grille : " << std::endl; // Interface pour demande manuellement les dimensions de la grille,  
            std::cout << "X : ";
            std::cin >> SizeX;
            if (SizeX <= 0) { // Modifie la valeur rentrée si elle est négatif en positif.
                SizeX = SizeX * (-1);
                std::cout << "Valeur negatif ! X = " << SizeX << std::endl;
            }
            std::cout << "Y : ";
            std::cin >> SizeY;
            if (SizeY <= 0) {
                SizeY = SizeY * (-1);
                std::cout << "Valeur negatif ! Y = " << SizeY << std::endl;
            }
            std::cout << "Temps entre deux iteration (en seconds): " << std::endl; // Le temps entre deux itération,
            std::cin >> Time;
            if (Time <= 0) {
                Time = Time * (-1);
                std::cout << "Valeur negatif ! Le temps devient egale a : " << Time << std::endl;
            }
            std::cout << "Nombre de Cellules vivantes a la premiere iteration : " << std::endl;
            std::cin >> NbrCells; // Le nombre de cellules vivantes au début et leurs coordonnées.
            if (NbrCells <= 0) {
                NbrCells = NbrCells * (-1);
                std::cout << "Valeur negatif ! Le nombre de cellules devient : " << NbrCells << std::endl;
            }

            Size = SizeX * SizeY; // On modifie la valeur de Size pour qu'il soit égale au nombre de cellule présent dans notre grille de jeu.
            Cell = new int[Size]; // On mets la taille du tableau à la taille de la grille de jeu pour stocker toute la grille dans un seul tableau.

            for (int i = 0; i < Size; i++) { // Mets toutes les valeurs du tableau à 0.
                Cell[i] = 0;
            }


            for (int i = 0; i < NbrCells; i++) { // Boucle qui va créer le nombre de cellules vivantes au début, avec leurs coordonnées.
                int X = 0;
                int Y = 0;
                int ActualCoor = 0;
                std::cout << "Coordonnees de la " << i + 1 << " cellule : " << std::endl;
                std::cout << "X : ";
                std::cin >> X;
                if (X < 0) {
                    X = X * (-1);
                    std::cout << "Valeur negatif ! La coordonnees X devient : " << X << std::endl;
                }
                std::cout << "Y : ";
                std::cin >> Y;
                if (Y < 0) {
                    Y = Y * (-1);
                    std::cout << "Valeur negatif ! La coordonnees Y devient : " << Y << std::endl;
                }

                system("CLS");

                // Commande qui "Clear" le console pour un affichage propre.
                ActualCoor = X * SizeY + Y; // Calcules la coordonnées où on est actuellement dans le tableau.
                if (X <= SizeX && Y <= SizeY) {
                    Cell[ActualCoor] = 1;
                }
                else { // Arrête le programme si les coordonnées rentrées sont en dehors du tableau.
                    std::cout << "Les coordonnees sont en dehors du tableau !" << std::endl;
                    std::cout << "Rentrez a nouveau les commandes : " << std::endl;
                    i--;
                }

                for (int X = 0; X < SizeX; X++) { // Double boucle qui parcours le tableau, X et Y sont les coordonnées.
                    for (int Y = 0; Y < SizeY; Y++) {
                        int ActualIndex = X * SizeY + Y;// qui regarde l'endroit ou on est actuellement dans le tableau
                        if (Cell[ActualIndex] == 0) {
                            std::cout << " ."; // qui affiche un " ." si la valeur à l'endroit où on est est égale à 0,
                        }
                        else {
                            std::cout << "[]"; // sinon un "[]".
                        }
                    }
                    std::cout << std::endl; // revient à la ligne à chaque boucle de X, donc à chaque fois qu'on change de ligne dans le tableau.
                }
            }
        }


        int* NewCells = new int[Size]; // Initialisation d'un deuxième tableau, pour ne pas modifier le premier pendant la bouclce.
        int Neightbor = 0;
        bool IsStop = false;
        auto TimePoint = std::chrono::steady_clock::now(); // Créer un point temporel, baser sur une horloge qui sert de repère pour calculer le temps.
        TimeStart = Time; // Mets la variable temps_start à la valeur du temps donner à l'entrée.
        // Boucle du jeu //
        while (Game) {
            if (_kbhit()) { // se déclenche quand une touche est presser.
                int Key = _getch(); // récupère la touche pressée
                if (Key == 32) { // vérifie le code ASCII de la touche presser, et exécute le programme lier lorsque la condition est rempli.
                    IsStop = !IsStop; // Inverse la valeur de "IsStop".
                    std::cout << std::endl;
                    std::cout << "Mise en pause." << std::endl;
                    std::cout << "Espace pour reprendre." << std::endl;
                    std::cout << "R pour recommencer." << std::endl;
                    /*Key = _getch();*/
                    /*while (Key != 114 || Key != 82 ||)*/
                    if (Key == 114 || Key == 82) { // Clear la console et relance la boucle si on appuye sur R.
                        system("CLS");
                        std::cout << "Le jeu recommence !";
                        break;
                    }
                    else if (Key == 27) { // Ferme le jeu si on appuye sur "Echap".
                        Game = false;
                        Restart = false;
                        break;
                    }
                }
                else if (Key == 100 || Key == 68) { // Si on appuye sur "d" ou "D", la vitesse augmente.
                    Time += 0.05;
                    if (Time >= TimeStart + 1) { // Vérification que le vitesse ne dépasse pas une certaine valeur.
                        Time = TimeStart + 1;
                    }
                }
                else if (Key == 113 || Key == 81) { // Si on appuye sur "q" ou "Q", la vitesse diminue.
                    Time -= 0.05;
                    if (Time <= 0.05) { // Vérification que le vitesse ne soit pas trop petite.
                        Time = 0.05;
                    }
                }
                else if (Key == 27) { // Si "Echap" est pressé, le programme s'arrête.
                    Game = false;
                    Restart = false;
                    break;
                }
            }
            if (IsStop == false)
            {
                auto TimePoint2 = std::chrono::steady_clock::now(); // Créer un deuxième repère 
                std::chrono::duration<float> Duration = TimePoint2 - TimePoint; // Calcule le temps écoulé entre les deux repères.
                if (Duration.count() >= Time) { // Si le résultat obtenu correspond à la valeur de la variable "temps", on lance l'iteration. Sinon on attend.
                    TimePoint = std::chrono::steady_clock::now(); // Reinitialise la valeur du premier repère pour recalculer le temps à chaque boucle.


                    for (int i = 0; i < Size; i++) { // Mets toutes les valeurs du deuxième tableau à 0.
                        NewCells[i] = 0;
                    }

                    system("CLS"); // Clear la console.

                    for (int X = 0; X < SizeX; X++) { // Double boucle pour se déplacer dans le tableau, X et Y sont les coordonnées.
                        for (int Y = 0; Y < SizeY; Y++) {
                            int ActualIndex = X * SizeY + Y; // Calcule l'index actuelle.
                            if (Cell[ActualIndex] == 0) { // Si l'index est égale à 0, on affiche ". ".
                                std::cout << " .";
                            }
                            else {
                                std::cout << "[]"; // Sinon, "[]"
                            }
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "Vitesse actuel : " << Time << " seconds. " << std::endl;
                    std::cout << "Espace pour mettre en pause." << std::endl;
                    std::cout << "Echap pour arreter." << std::endl;
                    std::cout << "D pour augmenter la vitesse de 0.1." << std::endl;
                    std::cout << "Q pour reduire la vitesse de 0.1." << std::endl;

                    for (int X = 0; X < SizeX; X++) { // Double boucle pour se déplacer dans le tableau, X et Y sont les coordonnées.
                        for (int Y = 0; Y < SizeY; Y++) {

                            int ActualIndex = X * SizeY + Y; // Calcule l'index actuelle.

                            for (int VX = X - 1; VX <= X + 1; VX++) { // Double boucle qui parcours les 8 voisins de l'index actuelle.
                                for (int VY = Y - 1; VY <= Y + 1; VY++) {
                                    if (VX >= 0 && VX < SizeX && VY >= 0 && VY < SizeY) { // Condition qui vérifie que tout les voisins sont présent dans le tableau. ( Pour les cellules au bord du tableau. )
                                        int VIndex = VX * SizeY + VY; // Calcule l'index du voisins sur lequel on est.
                                        if (VIndex != ActualIndex) { // Vérifie que l'index du voisins sur lequel on est n'est pas le même que celui de la cellules où on est placer, pour pas qu'elle se compte elle même en tant que voisins.
                                            if (Cell[VIndex] == 1) // Si la cellules est égale à 1, on ajoute 1 au compteur des voisins.
                                            {
                                                Neightbor++;
                                            }
                                        }
                                    }
                                }
                            }

                            // Vérifie les rèlges du jeu de la vie, pour modifier les cellules en conséquences.//

                            if (Cell[ActualIndex] == 1) // Si la cellules est vivantes,
                            {
                                if (Neightbor == 3 || Neightbor == 2) // et qu'elle a 2 ou 3 voisins,
                                {
                                    NewCells[ActualIndex] = 1; // elle devient vivantes,
                                }
                                else {
                                    NewCells[ActualIndex] = 0; // sinon elle meurt.
                                }
                            }
                            else { // Si elle est morte, 
                                if (Neightbor == 3) { // et qu'elle a 3 voisins, 
                                    NewCells[ActualIndex] = 1; // elle devient vivantes.
                                }
                            }
                            Neightbor = 0; // Reinitialise la valeur de voisins, pour les cellules suivantes.
                        }
                    }

                    for (int y = 0; y < Size; y++) { // Modifie les valeurs du tableau de base avec celle du tableau temporaire.
                        Cell[y] = NewCells[y];
                    }
                }
            }
        }
        delete[] Cell; // Supressions des adresses mémoires, pour libérer la mémoire après utilisation.
        Cell = nullptr; // Pointeur nul. Ne pointe vers aucune adresse valide. 
        delete[] NewCells;
        NewCells = nullptr;
    }

}