set talk off

clear

//use stud.dbf
//name = accept('Nume student:')
//locate for nume=name
//disp nume, adresa, data_n, bursa
//store cv to cval
//disp cval
//disp at("a", cval)

//Vsec = accept('sectia: ')
//SUM bursa,bursa*0.25,bursa*0.2,bursa*0.04;
//FOR cods=Vsec TO TS,TI,TC,TS
//
//? 'SECTIA:' + VSEC
//? 'TOTAL SALARII= ',TS
//? 'TOTAL IMPOZIT= ',TI
//? 'TOTAL contrib.asig.sociale= ',TC
//? 'total fond somaj= ',ts

//CALCUL CNT(),MAX(bursa),MIN(bursa),AVG(bursa),SUM(bursa);
//FOR cods=Vsec TO NR,SMAX,SMIN,MSAL,TSAL
//? NR, smax, smin, tsal

//for i=0 to 10 step 1
//	disp i
//next i

//go top
//do while .not. eof()
//	if	bursa > 0
//		? bursa,nume
//	endif
//	skip
//enddo

//scan for bursa > 0
//clear
//	? "Nume student :" + NUME
//	? "Adresa:" + ADRESA
//	? "Data nasterii: " + DTOC(DATA_N)
//	?? "(", DAY(DATA_N), CMONTH(DATA_N), YEAR(DATA_N);
//	 ,"-"+ CDOW(DATA_N),")"
//	? "Bursa: "+STR(BURSA,9,2)
//	? "Casatorit ", CAS
//	WAIT
//endscan

//name = accept('Nume student:')
//SET EXACT OFF
//SEEK name
//IF EOF ()
//	? 'Nu exista student cu numele cerut'
//	RETURN
//ENDIF
//DO WHILE name$nume .and. .NOT. EOF()
//	DISP Nume, Adresa
//	SKIP
//ENDDO

//use stud.dbf in 1 index stud_inume alias st
//use masini.dbf in 2 index masini_inrm alias ms
//select 1
//name = accept('Nume student:')
//seek name
//display
//select 2
//seek st->nrm
//? st->nume, st->adresa, nrm, tip
//return



