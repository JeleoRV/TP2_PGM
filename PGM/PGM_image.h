/*
 * La classe PGM_image est la structure permettant de manipuler les images au
 * format PGM dans C++.
 * On manipule seulement ici des images PGM en ASCII (ie. la ligne 2 du fichier
 * PGM est P2)
 */

/*
 * File:   PGM_image.h
 * Author: Jérôme et Léo
 *
 * Created on 23 novembre 2017, 09:23
 */

#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include <vector>
# include <fstream>
# include <cstring>
# include <cstdlib>
# include <iostream>

using namespace std;

class PGM_image {
private:
    int XSIZE, YSIZE ; // Taille de l'image
    int MAXG ; // valeur du niveau de gris maximum
    vector<int> values ; // Tableau contenant toutes les valeurs de chaque pixel
<<<<<<< HEAD
    // Le tableau est � une dimension et a donc une taille XSIZE*YSIZE
=======
    // Le tableau est à une dimension et a donc une taille XSIZE*YSIZE
>>>>>>> c247eb21a88f09d0a3fb027a008f873538636085
public:
    PGM_image();
    PGM_image(string filename);
    PGM_image(const PGM_image& orig);
    virtual ~PGM_image();
    
    // SEUILLAGE
    bool seuillage(int seuil); // Fonction de seuillage
    bool seuillage(); // Surcharge avec seuil = MAXG/2 par défaut
    // La méthode seuillage renvoie true si ça a fonctionné, false sinon (dans
    // le cas ou seuil est une valeur aberrante)
    
    // DIFFERENCE ENTRE DEUX IMAGES
    bool difference(PGM_image img);

    // SEUILLAGE
    bool seuillage(int seuil); // Fonction de seuillage
    bool seuillage(); // Surcharge avec seuil = MAXG/2 par d�faut
    // La m�thode seuillage renvoie true si �a a fonctionn�, false sinon (dans
    // le cas ou seuil est une valeur aberrante)

    // DIFFERENCE ENTRE DEUX IMAGES
    bool difference(PGM_image img);

    void write(string imageName);

};

#endif /* PGM_IMAGE_H */
