/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PGM_image.h
 * Author: GlouglouLand
 *
 * Created on 23 novembre 2017, 09:23
 */

#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

#include <vector>
using namespace std;

class PGM_image {
private:
    int XSIZE, YSIZE ; // Taille de l'image
    int MAXG ; // valeur du niveau de gris maximum
    vector<int> values ; // Tableau contenant toutes les valeurs de chaque pixel
    // Le tableau est à une dimension et a donc une taille XSIZE*YSIZE
public:
    PGM_image();
    PGM_image(const PGM_image& orig);
    virtual ~PGM_image();
    
    // SEUILLAGE
    bool seuillage(int seuil); // Fonction de seuillage
    bool seuillage(); // Surcharge avec seuil = MAXG/2 par défaut
    // La méthode seuillage renvoie true si ça a fonctionné, false sinon (dans
    // le cas ou seuil est une valeur aberrante)
    
    // DIFFERENCE ENTRE DEUX IMAGES
    bool difference(PGM_image img);

};

#endif /* PGM_IMAGE_H */

