set talk off
set date to dmy
close all
clear all

use student.dbf in 1 order tag cods alias st
use curs.dbf in 2 order tag codc alias cs
use profesor.dbf in 4 order tag codp alias pr
select cs
set relation to codp into pr
use note.dbf in 3 order tag cods alias nt

select nt
set relation to cods into st, codc into cs

resumeLoop = 'D'

do while resumeLoop$'DdYy'
	clear
	student = accept("Cod student:")
	seek student
	if eof()
		msgbox("Nu exista inregistrare pentru "+student;
		, "Rezultatul cautarii", 48)
		wait "Continuati? (d/n)" to resumeLoop
		loop
	endif
	
	do while nt->cods=student
		? st->cods, st->nume, cs->titlu, nt->nota, pr->nume
		skip
	enddo
	wait "Reia? (d/n)" to resumeLoop
enddo
return