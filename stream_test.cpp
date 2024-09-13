#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "./stream.h"
#include "./validacion.h"
#include "./random.cpp"

using namespace std;

class Persona {
public:
    string nombre;
    Fecha nacimiento;

    Persona() = default;

    Persona(string n, Fecha f) : nombre(n), nacimiento(f) {}

    // Sobrecarga del operador '<<'
    friend ostream& operator<<(ostream& os, const Persona& p) {
        os << p.nombre << " " << p.nacimiento;
        return os;
    }

    // Sobrecarga del operador '>>'
    friend istream& operator>>(istream& is, Persona& p) {
        is >> p.nombre >> p.nacimiento;
        return is;
    }
};

vector<Persona> PERSONAS_TEST;

void test_guardar() {
    // Guarda los datos en un archivo
    guardar(PERSONAS_TEST, "personas_guardar.txt");

    // Verifica que el archivo se creó correctamente
    ifstream file("personas_guardar.txt");
    assert(file.good());  // Comprueba que el archivo existe y se puede leer

    cout << "testGuardar \033[32mOK\033[0m" << endl;
}

void test_cargar() {
    vector<Persona> personas_cargadas;
    cargar(personas_cargadas, "personas_guardar.txt");

    // Asegura que el tamaño de los vectores es el mismo
    assert(PERSONAS_TEST.size() == personas_cargadas.size());

    // Compara cada elemento
    for (size_t i = 0; i < PERSONAS_TEST.size(); i++) {
        assert(PERSONAS_TEST[i].nombre == personas_cargadas[i].nombre);
        assert(PERSONAS_TEST[i].nacimiento.getDia() == personas_cargadas[i].nacimiento.getDia());
        assert(PERSONAS_TEST[i].nacimiento.getMes() == personas_cargadas[i].nacimiento.getMes());
        assert(PERSONAS_TEST[i].nacimiento.getAnio() == personas_cargadas[i].nacimiento.getAnio());
    }

    cout << "testCargar \033[32mOK\033[0m" << endl;
}

int main() {
    srand(time(NULL));
    int i = 100;

    do {
        PERSONAS_TEST.push_back(Persona(aleatorio(NOMBRES), fecha_aleatoria()));
        i--;
    } while (i > 0);
    
    test_guardar();
    test_cargar();

    cout << "All tests \033[32mOK\033[0m\n";
    return 0;
}
