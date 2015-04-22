#!/bin/sh

sed "s/thy\b/{&}/g" < /dev/fd/0
