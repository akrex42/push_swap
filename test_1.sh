#!/bin/zsh

RED="\e[31m"
GREEN="\e[32m"
MAGENTA="\e[95m"
CYAN="\e[96m"
ENDCOLOR="\e[0m"
BOLDGREEN="\e[1;${GREEN}"
BOLDRED="\e[1;${RED}"

setopt SH_WORD_SPLIT
echo -e "${BOLDRED} ERROR_MANAGEMENT ${ENDCOLOR}"
echo -e "${RED} MAX_INT ${ENDCOLOR}"
echo -e 'ARG="1234567892736452 1 7" ; ./push_swap $ARG' && ARG="1232384729855 1 7"; ./push_swap $ARG
echo -e "${RED} NON-NUMERIC ${ENDCOLOR}"
echo -e 'ARG="fdfd 1 7" ; ./push_swap $ARG' && ARG="fdfd 1 7"; ./push_swap $ARG
echo -e "${RED} DUPLICATE ${ENDCOLOR}"
echo -e 'ARG="1 1"; ./push_swap $ARG' && ARG="1 1"; ./push_swap $ARG
echo -e "${RED} NO ARG ${ENDCOLOR}"
echo -e "ARG=``; ./push_swap $ARG" && ARG=''; ./push_swap $ARG
echo -e "${BOLDGREEN}IDENTITY TEST${ENDCOLOR}"
echo -e "${GREEN} ZERO INSTRUCTIONS ${ENDCOLOR}"
echo -e './push_swap 42' && ./push_swap 42
echo -e './push_swap 0 1 2 3' && ./push_swap 0 1 2 3
echo -e './push_swap 0 1 2 3 4 5 6 7 8 9' && ./push_swap 0 1 2 3 4 5 6 7 8 9
echo -e "${GREEN} SIMPLE VERSION ${ENDCOLOR}"
echo -e 'ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG' && ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
echo -e 'ARG="2 1 0"; ./push_swap $ARG | wc -l' && ARG="2 1 0"; ./push_swap $ARG | wc -l
echo -e "${GREEN} ANOTHER SIMPLE VERSION ${ENDCOLOR}"
echo -e 'ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG' && ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
echo -e 'ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l' && ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
echo -e "${GREEN} ANOTHER SIMPLE VERSION CYCLE ${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
  ./push_swap $ARG | wc -l | awk '$1 > 12' >> test.txt
  i=$(( i+1 ))
done
echo -e "${GREEN} ANOTHER SIMPLE VERSION CYCLE MY CHECKER ${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
  ./push_swap $ARG | wc -l | awk '$1 > 12' >> test.txt
  i=$(( i+1 ))
done
echo -e "${GREEN} MIDDLE VERSION CYCLE ${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
#   echo $ARG >> test.txt
  ./push_swap $ARG | wc -l | awk '$1 > 699' >> test.txt
#  echo $ARG
  i=$(( i+1 ))
done
echo -e "${GREEN} MIDDLE VERSION CYCLE MY CHECKER${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
#   echo $ARG >> test.txt
  ./push_swap $ARG | wc -l | awk '$1 > 699' >> test.txt
  i=$(( i+1 ))
done
echo -e "${GREEN} ADVANCED VERSION CYCLE ${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
  ./push_swap $ARG | wc -l | awk '$1 > 5499' >> test.txt
  i=$(( i+1 ))
done
echo -e "${GREEN} ADVANCED VERSION CYCLE MY CHECKER${ENDCOLOR}"
i=0
while (( $i <= 50 ))
do
  ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
#  ./push_swap $ARG | wc -l
  ./push_swap $ARG | wc -l | awk '$1 > 5499' >> test.txt
  i=$(( i+1 ))
done
echo -e "${RED} CHECKER ERROR MANAGEMENT ${ENDCOLOR}"
echo -e './checker 4df' && ./checker 4df
echo -e './checker 0 1 2 1' && ./checker 0 1 2 1
echo -e './checker 0 1 2 3 4 5 6 7 8 2147483648' && ./checker 0 1 2 3 4 5 6 7 8 2147483648
echo -e './checker ' && ./checker
echo -e './checker 1 2 3' && ./checker 1 2 3
echo -e './checker 1 2 3' && ./checker 1 2 3
echo -e "${RED} FALSE TESTS ${ENDCOLOR}"
echo -e './checker 0 9 1 8 27 3 6 4 5' && ./checker 0 9 1 8 27 3 6 4 5
echo -e './checker 5 4 8 2 3' && ./checker 5 4 8 2 3
echo -e "${GREEN} RIGHT TESTS ${ENDCOLOR}"
echo -e './checker 0 1 2' && ./checker 0 1 2
echo -e './checker 0 9 1 8 2' && ./checker 0 9 1 8 2
echo -e './checker 2 1 3' && ./checker 2 1 3
