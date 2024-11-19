#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

inline void read_csv(std::string path) {
    ifstream fd(path);

    if (not fd) {
        exit(2);
    }

    string LINEA, campo_1, campo_n;
    getline(fd, LINEA); // lee la primer linea, la que contiene los headers
    while(getline(fd, LINEA, '\n')) {
        stringstream ss(LINEA);

        // obtenemos los valores de cada campo
        getline(ss, campo_1, ',');
        // ... 
        getline(ss, campo_n, '\r');

    }

    fd.close();
}

#endif // CSV_H
