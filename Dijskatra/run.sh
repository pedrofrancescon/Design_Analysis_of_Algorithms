#!/bin/bash

# Compila.
make;

./run $1 > graph.gv;

neato -Tpng graph.gv -o graph.png

# Limpa.
make clean;
