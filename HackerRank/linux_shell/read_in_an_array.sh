#!/bin/sh

#read -a countries

countries=()
while read line
do
  countries=("${countries[@]}" "$line")
done

echo ${countries[@]}
#for country in $countrys
#do
  #echo $country
#done
