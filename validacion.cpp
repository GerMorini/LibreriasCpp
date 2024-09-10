#include "validacion.h"

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

int Fecha::getDia() {return dia;}
int Fecha::getMes() {return mes;}
int Fecha::getAnio() {return anio;}

int numero_entre(int min, int max) {
    int x;
    std::cin >> x;

    while(std::cin.fail() || x < min || x > max) {
        std::cin.clear();
        std::cin.ignore(9223372036854775807,'\n');
        std::cout << "Entrada invalida, ingrese un numero entre " << min << " - " << max << ": ";
        std::cin >> x;

        // borra la linea anterior
        std::cout << "\033[F\033[2K";
    }
    return x;
}

int numero_validado() {
    int x;
    std::cin >> x;

    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(9223372036854775807,'\n');
        std::cout << "Entrada invalida, ingrese un numero: ";
        std::cin >> x;

        // borra la linea anterior
        std::cout << "\033[F\033[2K";
    }
    return x;
}

bool validar_fecha(Fecha fec) {
    bool b = fec.getDia() > 0;

    switch (fec.getMes()) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return b && fec.getDia() <= 31;
        case 4: case 6: case 9: case 11:
            return b && fec.getDia() <= 30;
        case 2:
            // es año bisiesto
            if ((fec.getAnio()%4 == 0 && fec.getAnio()%100 != 0) || fec.getAnio()%400 == 0) {
                return b && fec.getDia() <= 29;
            } 
            
            return b && fec.getDia() <= 28;
        default:
            return false;
    }
}

Fecha fecha_validada() {
    Fecha* fec;
    int dia, mes, anio;

    while (true) {
        std::cout << "\tDía: ";
        dia = numero_entre(1, 31);

        std::cout << "\tMes: ";
        mes = numero_entre(1, 12);

        std::cout << "\tAño: ";
        anio = numero_entre(1940, 2030);

        fec = new Fecha(dia, mes, anio);
        if (!validar_fecha(*fec)) {
            std::cout<<"Fecha invalida, inténtelo nuevamente\n";
        } else {
            return *fec;
        }
    }
}
