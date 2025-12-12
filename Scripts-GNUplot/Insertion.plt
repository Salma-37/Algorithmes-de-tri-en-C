set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output "GrapheInsertion.png"

set title "Complexité du Tri par Insertion - O(N^2)"
set xlabel "Taille (N)"
set ylabel "Nombre d'opérations"
set grid
set xrange [0:10000]

plot x**2 title "O(N^2)" lw 2

set output