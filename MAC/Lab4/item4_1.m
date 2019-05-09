A = [4 3 -1; -1 1 1; 1 0 3];
if det(A)~=0 % daca sistemul este compatibil determinat
    b=[2; 0; -1]; % vectorul-coloana al termenilor liberi
X = b\A
else
    disp('Sistemul nu este compatibil determinat.')
end