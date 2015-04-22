#!/bin/sh

countries=()
while read country
do
  countries=("${countries[@]}" "$country")
done

echo "${countries[3]}"
