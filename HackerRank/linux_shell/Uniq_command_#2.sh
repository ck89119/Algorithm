#!/bin/sh

uniq -c /dev/fd/0 | sed -e 's/^[ ]*//g'
