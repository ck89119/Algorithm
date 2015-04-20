#!/bin/sh

#col_num=`head -n 1 < file.txt | wc -w`

#for((i=1;i<=col_num;i++))
#do
  #echo `cut -d ' ' -f "$i" < file.txt | tr $'\n' $' '`
#done

awk '
  { 
    for (i = 1; i <= NF; ++i)
      a[NR,i] = $i;
  }
  NF > p { p = NF }
  END {
    for (i = 1; i <= p; ++i) {
      str = a[1, i];
      for (j = 2; j <= NR; ++j)
        str = str" "a[j, i];
      print str;
    }
  }
' < file.txt
