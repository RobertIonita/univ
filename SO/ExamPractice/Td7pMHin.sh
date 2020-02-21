#!/bin/bash

memo=("")
res=0

func () {
	# array cu toate fisierele din directorul curent
	files=($(ls -p $1 | grep -v /))
	
	# iteram prin toate fisierele din directorul curent
	for f in ${files[@]}; do
		e=0
		# iteram prin toate fisierele intalnite pana acum
		for x in ${memo[@]}; do
			# luam dimensiunea fisierului (a 5-a coloana din ls)
			fsize=$(ls -lp $1 | grep $f | awk '{print $5}')
			
			# daca fisierul f exista in memo, adaugam dimensiunea lul la res (rez. final)
			if [ $f == $x ]; then
				res=$(($res+$fsize))
				e=1
			fi
		done
		# daca fisierul f nu exista in memo, il bagam
		if [ $e == 0 ]; then
			memo+=($f)
		fi
	done

	# array cu toate directoarele din directorul curent
	dirs=($(ls -p $1 | grep /))
	# apelam recursiv functia dandu-i ca parametru un nou director
	for d in ${dirs[@]}; do
		func "$1/$d"
	done
}

func $1
printf "Rezultat: $res Bytes\n"