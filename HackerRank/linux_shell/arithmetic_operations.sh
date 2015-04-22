#!/bin/sh

read str
printf "%.3f" $(echo "scale = 4;" $str | bc -l)
