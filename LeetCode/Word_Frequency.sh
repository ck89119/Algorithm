#!/bin/sh

awk '
{
  for (i = 1; i <= NF; ++i)
    num[$i]++;
}
END {
  for (i in num) print i " " num[i];
}
' < words.txt | sort -rnk 2
