#!/bin/sh

read c

if [ "$c" == "y" ] || [ "$c" == "Y" ];
  then echo "YES"
  elif [ "$c" == "n" ] || [ "$c" == "N" ];
    then echo "NO"
    else echo "$c"
fi
