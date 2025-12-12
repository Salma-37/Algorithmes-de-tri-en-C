set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output "GrapheShell.png"

set title "Complexité du Tri par Shell - O(N^2)"
set xlabel "Taille (N)"
set ylabel "Nombre d'opérations"
set grid
set xrange [0:10000]

plot x*log(x)**2 title "O(N*log^2(N))" lw 2

set output