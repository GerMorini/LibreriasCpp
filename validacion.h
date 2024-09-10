#ifndef VALIDACION_H
#define VALIDACION_H

#include <cstdio>
#include <iostream>
#include <fstream>

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a);

        int getDia();
        int getMes();
        int getAnio();

        // define como imprimir fecha
        friend std::ostream& operator<<(std::ostream& os, const Fecha& fec) {
            os << fec.dia << "/" << fec.mes << "/" << fec.anio;
            return os;
        }

        // // define la lectura de una fecha
        // friend std::istream& operator>>(std::istream& is, Fecha& fec) {
        //     getline(is, adaw, '\n')
        //     return is;
        // }
};
   
int numero_entre(int min, int max);
int numero_validado();
bool validar_fecha(Fecha fec);
Fecha fecha_validada();

#endif // VALIDACION_H
