/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PGM_image.cpp
 * Author: GlouglouLand
 * 
 * Created on 23 novembre 2017, 09:23
 */

#include "PGM_image.h"

PGM_image::PGM_image() {
}

PGM_image::PGM_image(const PGM_image& orig) {
}

PGM_image::~PGM_image() {
}

bool PGM_image::seuillage(int seuil){
    // Vérification que seuil est bien compris entre 0 et MAXG
    if(seuil > MAXG || seuil < 0){
        return false;
    }
    // On parcourt le tableau de valeurs
    for  (int i=0; i<XSIZE*YSIZE; i++) {
        // Si la valeur est supérieure au seuil (cad plus blanc que le seuil),
        // on change la valeur à blanc.
        if (values[i]>= seuil){
            values[i] = MAXG;
        } 
        // Sinon la valeur est noire.
        else{values[i] = 0;}
    } 
    return true;
}

bool PGM_image::seuillage() {
    return seuillage(floor(MAXG/2));
}

bool PGM_image::difference(PGM_image img) {
    // Vérification de la compatibilité des deux images
    if(!(YSIZE == img.YSIZE && XSIZE==img.XSIZE && MAXG==img.MAXG)){
        return false;
    }
    
    // On parcourt les tableaux de valeurs
    for (int i=0; i< YSIZE*XSIZE; i++){
        // On affecte une nouvelle valeur à chaque pixel : différence entre les
        // des deux images, (0 si la différence est négative).
        values[i] = max(0 ,values[i]-img.values[i]);
    }
    
    return true;
}

