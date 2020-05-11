SET TALK OFF
DO WHILE.T. && repeta la infinit ciclul
	CLEAR
	TEXT
		 FUNCTII OFERITE:
		1- Creare structura fisier studenti
		2- Adaugare inregistrari
		3- Modificare inregistrare data prin numar
		4- Modificare sau afisare inreg. data prin NUME student.
		5- Stergere inregistrare
		6- Modificare structura BD
		7- Listare fisier
		8- Compactare fisier - PACK
		9- Revalidare inregistrare marcata
		T- Terminare program
	ENDTEXT
	WAIT TO R
	if .not.R$'123456789Tt'
		? 'FUNCTIA ' + R + ' inexistenta'
		WAIT && asteptare pentru citire mesaj
		LOOP && reluare ciclu
	ENDIF
	DO CASE
		CASE R='1'
			CREATE students && creare initiala DB
			CLEAR
			? ' S-a creat fisierul STUDENTI avind struct'
			DISP STRU && afisare structura
			WAIT
		CASE R='2'
			USE students
			APPEND && adaugare inregistrari de la tastatura
		CASE R='3'
			USE students && deschidere fisier
			N=VAL(ACCEPT('Numarul inregistrarii: '))
			EDIT N && trece în editare inregistrarea N
		CASE R = '4'
			USE students
			VNUME=TRIM( ACCEPT('Numele studentului: '))
			LOCATE FOR NUME = VNUME && cauta inregistrarea
			IF EOF()
				? 'Studentul cu numele ' + VNUME + ' nu exista'
				WAIT
				LOOP
			ENDIF
			EDIT && editare inregistrare gasita
		CASE R='5'
			USE students
			N=VAL(ACCEPT('NR. inregistrare pentru stergere: '))
			DELETE RECORD N && stergere inregistrare
		CASE R='6'
			USE students
			? ' Puteti modifica structura BD'
			MODI STRU
		CASE R='7'
			USE students
			LIST && listare fisier
		CASE R='8'
			USE students
			? ' Se elimina inregistrarile marcate pentru stergere'
			PACK
			WAIT
			? ' Noul fisier este:'
			LIST && listare noul fisier
		CASE R='9'
			USE students
			N=VAL(ACCEPT( 'Nr. articol ce se revalideaza: '))
			RECALL RECORD N
		CASE R $ 'Tt'
			USE
			RETURN && terminare program
	ENDCASE
ENDDO && reluare ciclu