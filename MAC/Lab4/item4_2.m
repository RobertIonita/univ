A = [4 3 -1; -1 1 1; 1 0 3; 4 4 3];
b = [2; 0; -1; 1]
if rank(A)==rank([A b]) % daca sistemul este compatibil
    disp('metoda pseudo-inversarii')
    X=pinv(A)*b
    disp('metoda impartirii la stanga')
    X=A\b
else
    disp('Sistemul nu este compatibil.')
end