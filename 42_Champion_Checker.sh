#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

#Path Champion
DIR="resources/players"

# Check if asm is in current dir and put it where it belong
if [ -f asm ]
then mv asm resources/bin/
fi

# Create directory
if [ -d log ]
then rm -rf log
fi
mkdir log

#delete .cor
rm -f $DIR/*.cor

# Assemble Champions
for champion in $DIR/*.s
do
	name=$(basename "$champion" .s)
	./resources/bin/asm_zaz $champion &> ./log/${name}.zaz.log
	mv $DIR/${name}.cor $DIR/${name}.zaz.cor
	./resources/bin/asm $champion &> ./log/${name}.log
done

# Compare asm output
clear
cols=50
lines=0
for champion in ./log/*.zaz.log
do
	name=$(basename "$champion" .zaz.log)
	grep "Invalid" ./log/$name.zaz.log > /dev/null 2>&1
	zaz=$?
	grep "Error" ./log/$name.log > /dev/null 2>&1
	team=$?
	printf "Champion $name"
	if [[ "$zaz" == "$team" ]] 
		then 
		tput cup $lines $cols
		printf "${GREEN}[OK]${NC}"
	else
		tput cup $lines $cols
		printf "${RED}[FAIL]${NC}"
	fi
	printf "\n"
	lines=$(($lines+1))
done