#!/bin/bash

# Compila.
make;

# Define tamanhos máximo e mínimo para os vetores, juntamente com passo para incremento do tamanho dos vetores e número de repetições para cada tamanho.
min_size=1;
max_size=500;
inc_step=10;
itr_size=5;

# Iteração para avaliar algoritmos com diferentes tamanhos de vetores.
echo -n > etimes.txt;
for s in $(seq ${min_size} ${inc_step} ${max_size}); do

	# Repete para cada tamanho várias vezes (itr_size).
	echo -n > Tis_temp;
	echo -n > Tms_temp;
	for t in $(seq 1 ${itr_size}); do

		# Cria vetor de entrada.
		./geninput.sh $s;

		# Computa algoritmos e salva os tempos.
		Tis=$(./insertionsort input.txt | tail -1);
		Tms=$(./mergesort input.txt | tail -1);
	
		# Grava tempos da t-ésima execução em arquivos para depois computar a mediana.
		echo ${Tis} >> Tis_temp;
		echo ${Tms} >> Tms_temp;
	done

	# Computa mediana dos tempos.
	Tis=$(sort -n Tis_temp | awk '{ a[i++]=$1; } END { x=int((i+1)/2); if (x < (i+1)/2) printf("%.8f", (a[x-1]+a[x])/2); else printf("%.8f", a[x-1]); }');
	Tms=$(sort -n Tms_temp | awk '{ a[i++]=$1; } END { x=int((i+1)/2); if (x < (i+1)/2) printf("%.8f", (a[x-1]+a[x])/2); else printf("%.8f", a[x-1]); }');

	# Imprime o tempo.
	echo "$s ${Tis} ${Tms}";

	# Salva tempos em arquivo para o gnuplot ler.
	echo "$s ${Tis} ${Tms}" >> etimes.txt;
done

# Cria gráfico.
gnuplot etimes.plot;

# Limpa.
make clean;
rm Tis_temp Tms_temp;
