#!/bin/bash

cmd='g++ -Wall -g -o exec/val_test validacion.cpp validacion_test.cpp'

echo -e "\033[32m[INFO]\033[0m compilando \033[33m($cmd)\033[0m" &&
eval $cmd &&
echo -e "\033[32m[INFO]\033[0m compilado con exito. ejecutando...\n\n" &&
./exec/val_test
