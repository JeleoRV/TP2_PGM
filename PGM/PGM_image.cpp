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
    bool fonctionne=false;
    if(seuil > MAXG || seuil < 0){
        return fonctionne;
    }
    for  (int i=0; i<XSIZE*YSIZE; i++) {
        if (values[i]>= seuil){
            values[i] = MAXG;
        } 
        else{values[i] = 0;}
    } 
}