#!/bin/sh

read n

sum=0
for (( i=1; i<=$n; i=i+1))
do
  read x
  sum=$(( sum + x ))
done

printf "%.3f" $(echo "scale=4; $sum / $n" | bc -l)
