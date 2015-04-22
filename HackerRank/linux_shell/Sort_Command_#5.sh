#!/bin/sh

sort -t $'\t' -k 2 -nr /dev/fd/0
