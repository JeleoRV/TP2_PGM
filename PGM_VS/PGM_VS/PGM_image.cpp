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


#include <cmath>

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "PGM_image.h"

using namespace std;

PGM_image::PGM_image() {
    XSIZE = 0;
    YSIZE = 0;
    MAXG = 0;
}

PGM_image::PGM_image(int _XSIZE, int _YSIZE, int _MAXG, vector<int> _values) {
    XSIZE = _XSIZE;
    YSIZE = _YSIZE;
    MAXG = _MAXG;
    values = _values ;
}

PGM_image::PGM_image(const char *filename) {
     /*
    input : location of the .pmg to read
    output : vector of int to thresh etc...
    */
  int row = 0, col = 0, numrows = 0, numcols = 0;
  int trash = 0;
  string line("");
  fstream infile(filename);

  if(infile)
  {// First line : version
      getline(infile,line);

      // Second line : comment
      getline(infile,line);

      // Third line : size
      infile >> numcols >> numrows >> trash;

      XSIZE = numcols;
      YSIZE = numrows;
      MAXG = 255;

      // Following lines : data
      for(row = 0; row < numrows; ++row)
      {
          for (col = 0; col < numcols; ++col)
          {
              values.push_back(0);
              infile >> values[row*YSIZE+col];
          }
      }
  }
  infile.close();
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

void PGM_image::write(const char* imageName)
{
    {
        std::ofstream f(imageName,std::ios_base::out
                                  |std::ios_base::binary
                                  |std::ios_base::trunc
                       );

        f << "P2\n" << XSIZE << " " << YSIZE << "\n" << MAXG << "\n";


        for(int row=0;row<XSIZE;++row)
        {
            f.write( reinterpret_cast<const char*>(values[row*YSIZE]), XSIZE );
            f<<"\n";
        }
    }
}
