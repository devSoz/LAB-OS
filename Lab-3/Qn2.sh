#!/bin/sh
echo "Enter an alphabet: "
read alp
ls -a | grep "^$alp"

