#ifndef VALIDACION_H
#define VALIDACION_H

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <cmath>

bool es_bisiesto(int anio);
int dias_en_mes(int mes, int anio);

class Fecha {
    private:
        int dia, mes, anio;
        int fecha_int; // representacion entera de la fecha

        inline void crearFechaInt() {
            fecha_int = anio * 10000 + mes * 100 + dia;
        }
    public:
        inline Fecha() {}
        inline Fecha(int d, int m, int a) {
            dia = d;
            mes = m;
            anio = a;
            crearFechaInt();
        }
        inline Fecha(const Fecha& f) {
            dia = f.dia;
            mes = f.mes;
            anio = f.anio;
            crearFechaInt();
        }
        inline Fecha(const std::string f) {
            std::stringstream ss(f);
            char barra;
            ss >> dia >> barra >> mes >> barra >> anio;
            crearFechaInt();
        }

        inline int getDia()        { return dia; }
        inline int getMes()        { return mes; }
        inline int getAnio()       { return anio; }

        inline void setDia(int d)  { dia = d; }
        inline void setMes(int m)  { mes = m; }
        inline void setAnio(int a) { anio = a; }

        inline Fecha operator+(int dias) {
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

            copia.crearFechaInt();

            return copia;
        }

        inline Fecha& operator+=(int dias) {
            *this = *this + dias;

            return *this;
        }

        inline Fecha operator-(int dias) {
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

            copia.crearFechaInt();

            return copia;
        }

        inline Fecha& operator-=(int dias) {
            *this = *this - dias;

            return *this;
        }

        inline bool operator==(Fecha& fec) { return fecha_int == fec.fecha_int; }
        inline bool operator!=(Fecha& fec) { return !(*this == fec); }
        inline bool operator<(Fecha& fec)  { return fecha_int < fec.fecha_int; }
        inline bool operator<=(Fecha& fec) { return *this < fec || *this == fec; }
        inline bool operator>(Fecha& fec)  { return fecha_int > fec.fecha_int; }
        inline bool operator>=(Fecha& fec) { return *this > fec || *this == fec; }
        
        inline bool operator==(const Fecha& fec) { return fecha_int == fec.fecha_int; }
        inline bool operator!=(const Fecha& fec) { return !(*this == fec); }
        inline bool operator<(const Fecha& fec)  { return fecha_int < fec.fecha_int; }
        inline bool operator<=(const Fecha& fec) { return *this < fec || *this == fec; }
        inline bool operator>(const Fecha& fec)  { return fecha_int > fec.fecha_int; }
        inline bool operator>=(const Fecha& fec) { return *this > fec || *this == fec; }

        // define como imprimir fecha (para almacenar en archivos)
        // la fecha se va a guardar en forma: 'DIA/MES/AÑO'
        inline friend std::ostream& operator<<(std::ostream& os, const Fecha& fec) {
            os << fec.dia << "/" << fec.mes << "/" << fec.anio;
            return os;
        }

        // define la lectura de una fecha (para archivos)
        // la fecha debe estar en forma: 'DIA/MES/AÑO'
        inline friend std::istream& operator>>(std::istream& is, Fecha& fec) {
            // char barra;
            std::string dia, mes, anio;
            // is >> fec.dia >> barra >> fec.mes >> barra >> fec.anio;
            
            getline(is, dia,'/');
            getline(is, mes,'/');
            getline(is, anio,','); // separador de campo del .csv

            fec.dia = std::stoi(dia);
            fec.mes = std::stoi(mes);
            fec.anio = std::stoi(anio);
            return is;
        }

        // usar este para imprimir en pantalla
        std::string toString();
};
   
int numero_entre(int min, int max);
float numero_entreFloat(float min, float max);
float truncar(float valor, int decimales);
int numero_validado();
bool validar_fecha(Fecha& fec);
Fecha fecha_validada(int anio_max, int anio_min);
void esperar(int segundos);
std::string color_fuente(std::string txt, int color);
std::string color_fondo(std::string txt, int color);
void limpiar_consola();
unsigned int simpleHash(std::string& str);

const std::string INFO_PFX = color_fuente("[INFO] ", 3); // prefijo de informacion
const std::string ERR_PFX = color_fuente("[ERROR] ", 2); // prefijo de error

#endif // VALIDACION_H
