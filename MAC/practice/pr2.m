%4_1
A1 = [5 4 1; 6 3 2; 1 1 1]
b1 = [0; 5; -7]
X1 = inv(A1) * b1

%4_2
A2 = [2 -3 0; -6 8 -1; 0 3 4]
b2 = [7; -5; 1]
X2 = A2\b2

%4_3a
A3a = [2 -3 0; -6 8 -1;0 3 4; -4 8 3]
b3a = [7; -5; 1; 3]
X3aps = pinv(A3a) * b3a
X3ast = A3a \ b3a
%4_3b
A3b=[3 -1 1 -2; -4 4 2 1];
b3b=[6; 0];
X3bps = pinv(A3b) * b3b
X3bst = A3b \ b3b


%4_4
A=[3 -1 1 -2;-4 4 2 1];
r=rank(A)
rminor=rank(A(:,[1 2]))
disp('sistemul este compatibil nedeterminat')
syms z t;
Aredus=A(:,[1 2]);
bredus=[6-z+2*t; -2*z-t];
s=inv(Aredus)*bredus
ss=Aredus\bredus
disp('Solutia sistemului dat este:')
x=s(1)
y=s(2)
disp('z,t numere reale oarecare')
