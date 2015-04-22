#!/bin/sh

word_list=()

while read word
do
  word_list=("${word_list[@]}" "$word")
done

word_list=("${word_list[@]}" "${word_list[@]}" "${word_list[@]}")
echo "${word_list[@]}"
