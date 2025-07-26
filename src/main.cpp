#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string inputFiles = "../input/";

bool lireLigne(const string& nomFichier, int numeroLigne, string& result) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
        return false;
    }

    string ligne;
    int index = 0;

    while (getline(fichier, ligne)) {
        if (index == numeroLigne) {
            result = ligne;
            return true; // ligne trouvée
        }
        index++;
    }

    // Si on sort de la boucle, la ligne demandée n'existe pas
    return false;
}

int main() {
    #ifdef __unix__
        printf("Unix system\n generating list of asm files\n");
        system("find ../input -type f -name '*.asm' | sed 's|^\.\./input/||' > ../asmFiles.txt");
    #endif

    #ifdef _win32
        printf("recompile the project for linux with Msys2 and run the bin file via Msys2");
        exit(1);
    #endif

    // for read asmFiles.txt
    fstream newfile; // new file object 
    newfile.open("../asmFiles.txt",ios::in); // open file for reading information
    if (newfile.is_open()) {
        string tp;
        string chemin;
        int ligne = 0;
        while (true)
        {
            if (lireLigne("../asmFiles.txt", ligne, chemin)) {
                cout << chemin << endl;
                // ici il faudra ouvrir chaque fichier asm avec fstream et vérifié la présence de macro
                fstream targetFile; // créer un nouveau object qui servira pour pointé le fichier asm
                targetFile.open("../",ios::in);
            } else {
                cout << "La ligne " << ligne + 1 << " n'existe pas dans le fichier." << endl;
                break;
            }
            ligne++;
        }
        newfile.close(); // close the file object
    };
    return 0;
}