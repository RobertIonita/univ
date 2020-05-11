set talk off

use stud.dbf in 1 index stud_inume, stud_icods, stud_inrm
use masini.dbf in 2 index masini_inrm alias ms

set relation to nrm into ms

do while .T.
	clear
	text
		Cautarea se poate face dupa:
		1- Nume student
		2- Cod student
		3- Numar masina
		0- terminare program
	endtext
	wait "Optiunea Dvs: " to option
	do case
		case option = "1"
			set order to 1
			choice = "Nume student"
			field = "nume"
		case option = "2"
			set order to 2
			choice = "Cod student"
			field = "cods"
		case option = "3"
			set order to 3
			choice = "Numar masina"
			field = "nrm"
		case option = "0"
			close all
			return
		otherwise
			? "Optiunea "+option+" este invalida"
			wait "Apasati orice tasta pentru a relua.."
			loop
	endcase
	student = accept(choice+":")
	seek student
	if eof()
		? "Nu exista inregistrari pentru: "+lower(choice)+" = "+student
			wait "Apasati orice tasta pentru a relua.."
		loop
	endif
	do while &field=student
		display
		if eof(2)
			? "Studentul nu are masina"
		else
			? ms->nrm, ms->an_f, ms->cap_c, ms->putere
		endif
		wait "Apasati orice tasta pentru a continua.."
		skip
	enddo
enddo
return