#!/bin/bash

read x
read y

if [ $x -lt $y ]
then
  echo "X is lesser than Y"
elif [ $x -eq $y ]
then
  echo "X is equal to Y"
else
  echo "X is greater than Y"
fi
