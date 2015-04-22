#!/bin/bash

countries=()
while read line
do
  countries=("${countries[@]}" "$line")
done

for (( i=3; i<=7; i++ ))
do
  #printf "%s " ${countries[i]}
  echo -n "${countries[i]} "
done
