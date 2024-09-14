#!/bin/bash

mkdir -p exec

cmd=(
    'g++ -Wall -g -o exec/val_test validacion.cpp validacion_test.cpp'
    'g++ -Wall -g -o exec/stream_test stream_test.cpp validacion.cpp'
)

for c in "${cmd[@]}"; do 
    echo -e "\033[32m[INFO]\033[0m compilando... \033[33m("$c")\033[0m"
    eval "$c"

    if [ $? != 0 ]; then
        echo -e "\033[31m[ERROR]\033[0m fallo en la compilación"
        exit 2
    fi
done

echo -e "\033[32m[INFO]\033[0m compilado con exito. ejecutando...\n\n"

./exec/val_test 
./exec/stream_test

