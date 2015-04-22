#!/bin/sh

word_list=()
while read word
do
  if [[ "$word" != *"a"* ]]
  then
    word_list=("${word_list[@]}" "$word")
  fi
done

echo "${word_list[@]}"
