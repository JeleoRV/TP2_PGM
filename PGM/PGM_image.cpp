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
#include <cmath>

PGM_image::PGM_image() {
<<<<<<< HEAD
    XSIZE = 0;
    YSIZE = 0;
    MAXG = 0;
}

PGM_image::PGM_image(string filename) {
    XSIZE, YSIZE, MAXG = 0;
     /*
    input : location of the .pmg to read
    output : vector of int to thresh etc...
    */
  int row = 0, col = 0, numrows = 0, numcols = 0;
  fstream infile(filename);
  string inputLine = "";

  // First line : version
  getline(infile,inputLine);

  // Second line : comment
  getline(infile,inputLine);

  // Third line : size
  infile >> numcols >> numrows;

  XSIZE = numcols;
  YSIZE = numrows;
  MAXG = 255;

  // Following lines : data
  for(row = 0; row < numrows; ++row)
  {
      for (col = 0; col < numcols; ++col)
      {
          values.push_back(infile);
      }
  }

  infile.close();
=======
    XSIZE, YSIZE, MAXG = 0;
>>>>>>> c247eb21a88f09d0a3fb027a008f873538636085
}

PGM_image::PGM_image(const PGM_image& orig) {
    XSIZE = orig.XSIZE;
    YSIZE = orig.YSIZE;
    MAXG = orig.MAXG;
    values = orig.values;
}

PGM_image::~PGM_image() {
}

bool PGM_image::seuillage(int seuil){
<<<<<<< HEAD
    // V�rification que seuil est bien compris entre 0 et MAXG
=======
    // Vérification que seuil est bien compris entre 0 et MAXG
>>>>>>> c247eb21a88f09d0a3fb027a008f873538636085
    if(seuil > MAXG || seuil < 0){
        return false;
    }
    // On parcourt le tableau de valeurs
    for  (int i=0; i<XSIZE*YSIZE; i++) {
<<<<<<< HEAD
        // Si la valeur est sup�rieure au seuil (cad plus blanc que le seuil),
        // on change la valeur � blanc.
        if (values[i]>= seuil){
            values[i] = MAXG;
        }
        // Sinon la valeur est noire.
        else{values[i] = 0;}
    }
=======
        // Si la valeur est supérieure au seuil (cad plus blanc que le seuil),
        // on change la valeur à blanc.
        if (values[i]>= seuil){
            values[i] = MAXG;
        } 
        // Sinon la valeur est noire.
        else{values[i] = 0;}
    } 
>>>>>>> c247eb21a88f09d0a3fb027a008f873538636085
    return true;
}

bool PGM_image::seuillage() {
    return seuillage(floor(MAXG/2));
}

bool PGM_image::difference(PGM_image img) {
<<<<<<< HEAD
    // V�rification de la compatibilit� des deux images
    if(!(YSIZE == img.YSIZE && XSIZE==img.XSIZE && MAXG==img.MAXG)){
        return false;
    }

    // On parcourt les tableaux de valeurs
    for (int i=0; i< YSIZE*XSIZE; i++){
        // On affecte une nouvelle valeur � chaque pixel : diff�rence entre les
        // des deux images, (0 si la diff�rence est n�gative).
        values[i] = max(0 ,values[i]-img.values[i]);
    }

    return true;
}

bool PGM_image::write(string imageName)
{
    {
        std::ofstream f(imageName,std::ios_base::out
                                  |std::ios_base::binary
                                  |std::ios_base::trunc
                       );

        int maxColorValue = 255;
        f << "P2\n" << XSIZE << " " << YSIZE << "\n" << MAXG << "\n";
        // std::endl == "\n" + std::flush
        // we do not want std::flush here.

        for(int i=0;i<height;++i)
            f.write( reinterpret_cast<const char*>(values[i]), XSIZE );

        if(wannaFlush)
            f << std::flush;
    }

}
=======
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

>>>>>>> c247eb21a88f09d0a3fb027a008f873538636085
