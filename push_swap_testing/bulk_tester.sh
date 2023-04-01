#!/bin/bash
OUTPUT_MOVES="moves.txt"
OUTPUT="bulk_moves${1}.csv"
DIR_MAKE="../push_swap_working/"
TIMES=10

test_loop()
{
	for i in $(seq $5)
	do
		ARG=$(python generator.py $1)
		../push_swap_working/push_swap $ARG | ./checker_linux $ARG | sed -z 's/\n//g' >> $OUTPUT
		echo -n "," >> $OUTPUT
		echo -n $2","$3","$4","$1"," >> $OUTPUT
		touch $OUTPUT_MOVES
		../push_swap_working/push_swap $ARG > $OUTPUT_MOVES
		NUMBER=$(cat $OUTPUT_MOVES | wc -l)
		echo -n ${NUMBER}"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^sa$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^ra$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^rra$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^sb$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^rb$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^rrb$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^pa$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^pb$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^ss$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^rr$" | wc -l)"," >> $OUTPUT
		echo -n $(cat $OUTPUT_MOVES | grep "^rrr$" | wc -l)"," >> $OUTPUT
		echo ${ARG} >> $OUTPUT
	done
	rm -f moves.txt
}

c_compile()
{
	make BCC=$1 SCC=$2 SAC=$3 re -C $DIR_MAKE &>> /dev/null
}

turn()
{
	c_compile $2 $3 $4
	if [ ! -s $OUTPUT ];
	then
		echo "Result,BCC,SCC,SAC,List Size,Number,sa,ra,rra,sb,rb,rrb,pa,pb,ss,rr,rrr,Input," >> $OUTPUT
	fi
	test_loop $1 $2 $3 $4 $5
}

clean()
{
	rm -f data*
	rm -f bulk_moves*
	rm -f moves.txt
	rm -f numbers.txt
}

# edit turn ### to change size of list
# log files are data###.csv and bulk_moves###.csv

run()
{
	for bcc in $(seq 16 16)
	do
		for scc in $(seq 6 6)
		do
			for sac in $(seq 10 10)
			do
				turn $1 $bcc $scc $sac $2
			done
		done
	done
}

clean
if [ $2 ]
then 
	run $1 $2
else
	run $1 10
fi
