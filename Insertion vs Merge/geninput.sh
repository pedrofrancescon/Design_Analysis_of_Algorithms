#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 size";
	exit 1;
fi

if ! [[ $1 =~ ^[0-9]+$ ]]; then
	echo "Input argument must be an integer.";
	exit 1;
fi

./gennumbers $1 > temp.txt;

sort -n temp.txt > stemp.txt;
awk -v nr=$1 '{if (NR < nr) printf("%d ", $1); else printf("%d\n", $1);}' temp.txt > input.txt
awk -v nr=$1 '{if (NR < nr) printf("%d ", $1); else printf("%d\n", $1);}' stemp.txt > output.txt;

rm temp.txt;
rm stemp.txt;
