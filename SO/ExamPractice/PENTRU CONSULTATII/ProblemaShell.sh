recursiva()
{
	for i in $(ls $1)
	do
		if test -d "$1/$i"
		then		
			nrFiles="$(ls -l $1/$i |grep ^- | wc -l)"
			if test $nrFiles -eq 0
			then echo $1/$i " Directory doesn't contain files" 
			fi
			recursiva $1/$i
		fi
	done
}

if test $# -lt 1 || test ! -d $1 
	then echo "Argument invalid. Argumentul trebuie sa fie un director"
	exit
fi

recursiva $1
