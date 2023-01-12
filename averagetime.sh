#!/bin/bash
#Varun Pavuloori, uja2wd, uja2wd@virginia.edu, 11.3.22


read DICT
read PUZZLE


if [[ `exit` == $DICT ]] ; then
    exit 0
else
    SUM=0
    for i in {1..5} ; do
	echo "Running iteration $i..."
	RUNTIME=`./a.out $DICT $PUZZLE | tail -1`
	SUM=$((SUM+RUNTIME))
    done
fi
AVERAGE=$((SUM/5))
echo "scale=4 ; $AVERAGE" | bc


    
