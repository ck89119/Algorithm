#!/bin/sh

countries=()
while read country
do
  country=$(echo "$country" | sed s/[A-Z]/./1)
  countries=("${countries[@]}" "$country")
done

echo "${countries[@]}"
