#ifndef VALIDACION_H
#define VALIDACION_H

#include <iostream>
#include <unistd.h>
#include <fstream>

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a);
        Fecha(const Fecha& f);
        Fecha(const std::string f);

        int getDia();
        int getMes();
        int getAnio();

        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        // usar este para imprimir en pantalla
        std::string toString();

        Fecha operator+(int dias);
        Fecha& operator+=(int dias);
        Fecha operator-(int dias);
        Fecha& operator-=(int dias);

        bool operator==(Fecha& fec);
        bool operator!=(Fecha& fec);
        bool operator<(Fecha& fec);
        bool operator<=(Fecha& fec);
        bool operator>(Fecha& fec);
        bool operator>=(Fecha& fec);

        // define como imprimir fecha (para almacenar en archivos)
        // la fecha se va a guardar en forma: 'DIA MES AÑO'
        friend std::ostream& operator<<(std::ostream& os, const Fecha& fec) {
            os << fec.dia << " " << fec.mes << " " << fec.anio;
            return os;
        }

        // define la lectura de una fecha (para archivos)
        // la fecha debe estar en forma: 'DIA MES AÑO'
        friend std::istream& operator>>(std::istream& is, Fecha& fec) {
            is >> fec.dia >> fec.mes >> fec.anio;
            return is;
        }
};
   
int numero_entre(int min, int max);
int numero_validado();
bool es_bisiesto(int anio);
int dias_en_mes(int mes, int anio);
bool validar_fecha(Fecha& fec);
Fecha fecha_validada();
void esperar(int segundos);
std::string color_fuente(std::string txt, int color);
std::string color_fondo(std::string txt, int color);
void limpiar_consola();

#endif // VALIDACION_H
