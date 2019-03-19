clc
A=[-6 8 -1;2 -3 0];
r=rank(A) 
rminor=rank(A(:,[1 2])) 
disp('sistemul este compatibil nedeterminat')
disp(blanks(1)')
syms z t;
Aredus=A(:,[1 2]);
bredus=[6-z+2*t; -2*z-t];
s=inv(Aredus)*bredus
ss=Aredus\bredus
disp(blanks(1)')
pause
disp('Solutia sistemului dat este:')
x=s(1)
y=s(2)
disp('z,t numere reale oarecare')