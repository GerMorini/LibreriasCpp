#include "validacion.h"

Fecha::Fecha() {}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

Fecha::Fecha(const Fecha& f) {
    dia = f.dia;
    mes = f.mes;
    anio = f.anio;
}

int Fecha::getDia() {return dia;}
int Fecha::getMes() {return mes;}
int Fecha::getAnio() {return anio;}

void Fecha::setDia(int d) {dia = d;}
void Fecha::setMes(int m) {mes = m;}
void Fecha::setAnio(int a) {anio = a;}

std::string Fecha::toString() {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

Fecha Fecha::operator+(int dias) {
    Fecha copia(*this);

    copia.dia += dias;

    while (copia.dia > dias_en_mes(copia.mes, copia.anio)) {
        copia.dia -= dias_en_mes(copia.mes, copia.anio);
        copia.mes++;
        if (copia.mes > 12) {
            copia.anio++;
            copia.mes = 1;
        }
    }

    return copia;
}

Fecha& Fecha::operator+=(int dias) {
    *this = *this + dias;

    return *this;
}

Fecha Fecha::operator-(int dias) {
    Fecha copia(*this);
    
    copia.dia -= dias;

    while (copia.dia < 1) {
        copia.dia += dias_en_mes(copia.mes - 1, copia.anio);
        copia.mes--;
        if (copia.mes < 1) {
            copia.anio--;
            copia.mes = 12;
        }
    }

    return copia;
}

Fecha& Fecha::operator-=(int dias) {
    *this = *this - dias;

    return *this;
}

bool Fecha::operator==(Fecha& fec) {return dia == fec.dia && mes == fec.mes && anio == fec.anio;}
bool Fecha::operator!=(Fecha& fec) {return !(*this == fec);}

bool Fecha::operator<(Fecha& fec) {
    return (anio < fec.anio) ||
           (anio == fec.anio && mes < fec.mes) ||
           (anio == fec.anio && mes == fec.mes && dia < fec.dia);
}

bool Fecha::operator<=(Fecha& fec) {return *this < fec || *this == fec;}

bool Fecha::operator>(Fecha& fec) {
    return (anio > fec.anio) ||
           (anio == fec.anio && mes > fec.mes) ||
           (anio == fec.anio && mes == fec.mes && dia > fec.dia);
}

bool Fecha::operator>=(Fecha& fec) {return *this > fec || *this == fec;}

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
    0 \033[0m    # Resetea el color y el formato (de caulquier tipo)
    1 \033[30m   # negro
    2 \033[31m   # rojo
    3 \033[32m   # verde
    4 \033[33m   # amarillo
    5 \033[34m   # azul
    6 \033[35m   # magenta
    7 \033[36m   # cian
    8 \033[37m   # blanco
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
