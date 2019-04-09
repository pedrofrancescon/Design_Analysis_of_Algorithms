reset
set key right bottom
set ylabel "Tempo"
set xlabel "Tamanho da entrada"
set term pdf color enhanced font 'Times-New Roman,11' size 6in,4in
set out 'etimes.pdf'
plot 'etimes.txt' u 1:2 t 'Insertion Sort' with l lw 2 lt 1,\
     'etimes.txt' u 1:3 t 'Merge Sort' with l lw 2 lt 2
