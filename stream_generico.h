#ifndef STREAM_GENERICO_H
#define STREAM_GENERICO_H

#include <vector>
#include <fstream>

template<class T>
void cargar(std::vector<T>& l, std::string path_archivo);

template<class T>
void guardar(std::vector<T>& l, std::string path_archivo);

#endif // STREAM_GENERICO_H
