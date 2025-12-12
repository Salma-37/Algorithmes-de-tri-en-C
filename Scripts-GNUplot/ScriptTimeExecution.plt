set terminal pngcairo size 800,600 enhanced font 'Arial,12'
set output "graph1.png"

set datafile separator ","
set title "Temps d'exécution des algorithmes de tri"
set xlabel "Taille du tableau"
set ylabel "Temps (s)"
set grid

plot "Resultats0.csv" using 1:2 with linespoints title "Bulle", \
     "Resultats0.csv" using 1:3 with linespoints title "Selection", \
     "Resultats0.csv" using 1:4 with linespoints title "Insertion", \
     "Resultats0.csv" using 1:5 with linespoints title "Shell", \
     "Resultats0.csv" using 1:6 with linespoints title "Tas", \
     "Resultats0.csv" using 1:7 with linespoints title "Rapide", \
     "Resultats0.csv" using 1:8 with linespoints title "Fusion"

set output
