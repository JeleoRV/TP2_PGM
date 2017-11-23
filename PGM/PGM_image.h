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

class PGM_image{
private:
    int XSIZE, YSIZE ; // Taille de l'image
    int MAXG ; // valeur du niveau de gris maximum
    vector<int> values ; // Tableau contenant toutes les valeurs de chaque pixel

    // Le tableau est à une dimension et a donc une taille XSIZE*YSIZE

public:
    PGM_image(); // Constructeur par défaut
    PGM_image(string filename); // Contructeur par lecture d'un fichier PGM
    PGM_image(const PGM_image& orig); // Constructeur par recopie
    // Constructeur complet
    PGM_image(int XSIZE, int YSIZE, int MAXG, vector<int> values);
    virtual ~PGM_image(); // Destructeur
    
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
    
    // ECRITURE ET SAUVEGARDE D'UNE IMAGE PGM
    void write(string imageName);

};

#endif /* PGM_IMAGE_H */
