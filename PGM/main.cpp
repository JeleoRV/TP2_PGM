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
#include "PGM_image.h"
using namespace std;

/*
 *
 */
    int main(int argc, char** argv) {

    string in("lena.pmg");
    PGM_image lena(in);
    lena.seuillage(60);
    lena.write("lena_seuillee.pmg");
    return 0;
}

