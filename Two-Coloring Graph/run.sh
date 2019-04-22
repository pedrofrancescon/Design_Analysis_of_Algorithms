#!/bin/bash

# Compila.
make;

./run $1 > graph.gv;

if [ $? -ne 0 ]; then
	make clean;
	rm graph.gv;
	echo;
	echo "Graph cannot be colored!!";
	echo;
	exit 1;
fi

neato -Tpng graph.gv -o graph.png

# Limpa.
make clean;