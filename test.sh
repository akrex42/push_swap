#!/bin/bash
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
  ./push_swap $ARG | wc -l
  i=$(( i+1 ))
done
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
  ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
  ./push_swap $ARG | wc -l
  i=$(( i+1 ))
done
i=0
while (( $i <= 500 ))
do
  ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
  ./push_swap $ARG | wc -l
  i=$(( i+1 ))
done
