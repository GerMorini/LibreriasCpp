#include "validacion.h"

std::string Fecha::toString() {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

int numero_entre(int min, int max) {
    int x;
    std::cin >> x;

    while (std::cin.fail() || x < min || x > max) {
        std::cin.clear();
        std::cin.ignore(9223372036854775807,'\n');
        std::cout << "Entrada invalida, ingrese un numero entre " << min << " - " << max << ": ";
        std::cin >> x;

        // borra la linea anterior
        std::cout << "\033[F\033[2K";
    }
    return x;
}

float numero_entreFloat(float min, float max) {
    float x;
    std::cin >> x;

    while (std::cin.fail() || x < 0 || x > max) {
        std::cin.clear();
        std::cin.ignore(9223372036854775807,'\n');
        std::cout << "Entrada invalida, ingrese un numero mayor que 0 y menor que " << max << ": ";
        std::cin >> x;

        // borra la linea anterior
        std::cout << "\033[F\033[2K";
    }
    return x;
}

float truncar(float valor, int decimales) {
    float factor = std::pow(10.0, decimales);
    return std::trunc(valor * factor) / factor;
}

int numero_validado() {
    int x;
    std::cin >> x;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(9223372036854775807,'\n');
        std::cout << "Entrada invalida, ingrese un numero: ";
        std::cin >> x;

        // borra la linea anterior
        std::cout << "\033[F\033[2K";
    }
    return x;
}



bool es_bisiesto(int anio) {
    return (anio%4 == 0 && anio%100 != 0) || anio%400 == 0;
}

int dias_en_mes(int mes, int anio) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // es año bisiesto
            if (es_bisiesto(anio)) {
                return 29;
            } 
            return 28;
        default:
            return -1;
    }
}

bool validar_fecha(Fecha& fec) {
    return fec.getDia() > 0 && fec.getDia() <= dias_en_mes(fec.getMes(), fec.getAnio());
}

Fecha fecha_validada(int anio_max = 2030, int anio_min = 0) {
    Fecha* fec;
    int dia, mes, anio;

    while (true) {
        std::cout << "\tDía: ";
        dia = numero_entre(1, 31);

        std::cout << "\tMes: ";
        mes = numero_entre(1, 12);

        std::cout << "\tAño: ";
        anio = numero_entre(anio_min, anio_max);

        fec = new Fecha(dia, mes, anio);
        if (!validar_fecha(*fec)) {
            std::cout<<"Fecha invalida, inténtelo nuevamente\n";
        } else {
            return *fec;
        }
    }
}


void esperar(int segundos) {
    sleep(segundos);
}

/**
Colores disponibles:
    0 Resetea el color y el formato (de caulquier tipo)
    1 negro
    2 rojo
    3 verde
    4 amarillo
    5 azul
    6 magenta
    7 cian
    8 blanco
 */
std::string color_fuente(std::string txt, int color) {
    if (color < 0 or color > 8) return txt;

    std::string COLORES[] = {
    "\033[0m",
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m"
    };

    return COLORES[color] + txt + COLORES[0];
}

/**
Los colores son los mismos que en el método anterior
 */
std::string color_fondo(std::string txt, int color) {
    if (color < 0 or color > 8) return txt;

    std::string COLORES[] = {
    "\033[0m",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m"
    };

    return COLORES[color] + txt + COLORES[0];
}

void limpiar_consola() {
    std::cout << "\033[H\033[2J";
}

unsigned int simpleHash(std::string& str) {
    unsigned int hash = 0;
    const unsigned int prime = 31;

    for (char c : str) {
        hash = hash * prime + static_cast<unsigned int>(c);
    }

    return hash;
}
