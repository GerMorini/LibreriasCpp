#ifndef STREAM_H
#define STREAM_H

#include <vector>
#include <fstream>

/*
    Hay que definir los siguientes metodos en las clases que necesitemos guardar
    Sobreescribimos los operadores '<<' y '>>'

    // define como imprimir la clase
    friend std::ostream& operator<<(std::ostream& os, const CLASE& c) {

        os << c.ATTR1 << c.ATTR2 << ...

        return os;
    }

    // define la lectura de la clase
    friend std::istream& operator>>(std::istream& is, CLASE& c) {
        
        is >> c.ATTR1 >> c.ATTR2 >> ...

        return is;
    }
*/

template<class T>
void cargar(std::vector<T>& l, std::string path_archivo) {
    std::ifstream file(path_archivo);

    if (!file) {
        // si no se pudo abrir el archivo
        return;
    }

    T c;
    while (file >> c) {
        l.push_back(c);
    }

    file.close();
}

template<class T>
void guardar(std::vector<T>& l, std::string path_archivo) {
    std::ofstream file(path_archivo);

    if (!file) {
        // si no se pudo abrir el archivo
        return;
    }

    for (int i = 0; i < l.size(); i++) {
        file << l.at(i) << std::endl;
    }

    file.close();
}

#endif // STREAM_H
