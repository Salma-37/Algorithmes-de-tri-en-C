set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output "graph1.png"

set datafile separator ","
set title "Temps d'exécution des algorithmes de tri"
set xlabel "Taille du tableau"
set ylabel "Temps (s)"
set grid

plot "Resultat.csv" using 1:2 with linespoints title "Bulle", \
     "Resultat.csv" using 1:3 with linespoints title "Selection", \
     "Resultat.csv" using 1:4 with linespoints title "Insertion", \
     "Resultat.csv" using 1:5 with linespoints title "Shell", \
     "Resultat.csv" using 1:6 with linespoints title "Tas", \
     "Resultat.csv" using 1:7 with linespoints title "Comptage", \
     "Resultat.csv" using 1:8 with linespoints title "Rapide", \
     "Resultat.csv" using 1:9 with linespoints title "Fusion"

set output

