/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: dies
 *
 * Created on September 22, 2020, 2:52 PM
 */
#include <iostream>
#include <cstdlib>
#include "FC/FC.h"


using namespace std;

int main(int argc, char** argv) {
    if (argc == 1) {
        FC * main_copier = new FC();
        main_copier->main_loop();
    }
    if (argc == 2) {
        FC main_copier(argv[1]);
        main_copier.main_loop();
    }
    if (argc == 3) {
        FC main_copier(argv[1], argv[2]);
        main_copier.main_loop();
    }
    return 0;
}

