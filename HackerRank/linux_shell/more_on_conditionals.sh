#!/bin/sh

read x
read y
read z

if [ $x -eq $y ] && [ $y -eq $z ];
  then echo "EQUILATERAL"
  elif [ $x -ne $y ] && [ $x -ne $z ] && [ $y -ne $z ];
    then echo "SCALENE"
    else echo "ISOSCELES"
fi
