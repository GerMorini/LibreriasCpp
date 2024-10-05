#ifndef STREAM_H
#define STREAM_H

#include <vector>
#include <fstream>

/**
    permite cargar cualquier clase que tenga definida el siguiente metodo:

    friend std::istream& operator>>(std::istream& is, CLASE& c) {
        is >> c.atributo1 >> c.atributo2 >> ...

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

/**
    permite guardar cualquier clase que tenga definida el siguiente metodo:

    friend std::ostream& operator<<(std::ostream& os, const CLASE& c) {
        os << c.atributo1 << c.atributo2 << ...
        return os;
    }
 */
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
