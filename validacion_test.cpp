// test_fecha.cpp
#include "validacion.h"
#include <cassert>
#include <iostream>

void testConstructor() {
    Fecha f(10, 5, 2022);
    assert(f.getDia() == 10);
    assert(f.getMes() == 5);
    assert(f.getAnio() == 2022);
    std::cout << "testConstructor \033[32mOK\033[0m.\n";
}

void testToString() {
    Fecha f(10, 5, 2022);
    assert(f.toString() == "10/5/2022");
    std::cout << "testToString \033[32mOK\033[0m.\n";
}

void testOperatorSum() {
    Fecha f(28, 2, 2020);  // Año bisiesto
    Fecha resultado = f + 1;
    assert(resultado.getDia() == 29);  // Febrero tiene 29 días en años bisiestos
    assert(resultado.getMes() == 2);
    assert(resultado.getAnio() == 2020);

    resultado += 1;
    assert(resultado.getDia() == 1);  // Después del 29 de febrero, debería ser 1 de marzo
    assert(resultado.getMes() == 3);
    assert(resultado.getAnio() == 2020);

    std::cout << "testOperatorSum \033[32mOK\033[0m.\n";
}

void testOperatorSubtraction() {
    Fecha f(1, 3, 2020);  // Año bisiesto
    Fecha resultado = f - 1;
    assert(resultado.getDia() == 29);  // Volver al 29 de febrero
    assert(resultado.getMes() == 2);
    assert(resultado.getAnio() == 2020);

    resultado -= 1;
    assert(resultado.getDia() == 28);  // Volver al 28 de febrero
    assert(resultado.getMes() == 2);
    assert(resultado.getAnio() == 2020);

    std::cout << "testOperatorSubtraction \033[32mOK\033[0m.\n";
}

void testComparisons() {
    Fecha f1(10, 5, 2022);
    Fecha f2(15, 5, 2022);

    assert(f1 < f2);
    assert(f2 > f1);
    assert(f1 <= f2);
    assert(f2 >= f1);
    assert(!(f1 == f2));
    assert(f1 != f2);

    std::cout << "testComparisons \033[32mOK\033[0m.\n";
}

int main() {
    testConstructor();
    testToString();
    testOperatorSum();
    testOperatorSubtraction();
    testComparisons();

    std::cout << "All tests \033[32mOK\033[0m.\n";
    return 0;
}
