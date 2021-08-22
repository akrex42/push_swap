#!/bin/bash
i=0
while (( $i <= 500 ))
do
  ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
  ./push_swap $ARG | wc -l
  i=$(( i+1 ))
done
i=0
while (( $i <= 500 ))
do
  ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
  ./push_swap $ARG | wc -l
  i=$(( i+1 ))
done
echo -e "ARG=`1234567892736452 1 7`; ./push_swap $ARG" ; ARG="1232384729855 1 7"; ./push_swap $ARG
echo -e "ARG=`1`; ./push_swap $ARG" ; ARG="1"; ./push_swap $ARG
echo -e "ARG=`1 fgfg`; ./push_swap $ARG" ; ARG="1 fgfg"; ./push_swap $ARG
echo -e "ARG=`1 "xzd"`; ./push_swap $ARG" ; ARG="1 'xzd'; ./push_swap $ARG
