#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1


#N varia
#n=$1 $2=num iteración
function nVaria {
  #elimina todo el contenido del archivo a guardar si es que existe.
  echo -n "" > informe/plots/plot$2n$1.txt
  num=$(awk 'BEGIN{for(i=0;i<=1.01;i+=0.01)print i}')

  for i in $num
  do
    echo -e $(./a.out $1 $i \n)   >> informe/plots/plot$2n$1.txt
  done

  gnuplot -persist <<-EOFMarker
   set title "n = $1" font ",14" textcolor rgbcolor "royalblue"
   set nokey
   set ylabel "Tiempo"
   set format y "%7.3f"
   set xlabel "p"
   set format y "%.7f"
   set term png
   set yrange [0:1]
   set xrange [0:1]
   set output "informe/plots/plot$2n$1.png"
   plot "informe/plots/plot$2n$1.txt"  using 1:2 with lines
EOFMarker
}


echo "Se están creando las gráficas, por favor espere"
#Crea las gráficas para los 5 metodos

n=100
nVaria $n 1

n=500
nVaria $n 2

n=1000
nVaria $n 3

n=10000
nVaria $n 4


done
