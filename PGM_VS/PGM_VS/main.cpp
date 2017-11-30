/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: GlouglouLand
 *
 * Created on 23 novembre 2017, 08:32
 */

#include <cstdlib>
#include <iostream>
#include "PGM_image.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    PGM_image lena("lena.pgm");
    lena.seuillage(60);
    lena.write("lena_seuillee.pgm");
    cout << "Appuyer sur n'importe quelle touche puis ENTREE pour terminer l'application..." << endl;
    char i;
    cin >> i;
    return 0;
}

