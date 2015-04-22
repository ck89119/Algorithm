#!/bin/sh

uniq -ic < /dev/fd/0 | sed -e 's/^[ ]*//g'
