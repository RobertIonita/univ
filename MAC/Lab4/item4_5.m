alpha=sym('a'); beta=sym('b'); gamma=sym('g');
A=[alpha -beta 1;-gamma 1 beta;1 gamma -alpha];
b=[gamma; alpha; beta];
d=det(A)
factor(d)  
disp('Cazul: alpha~=0 -> sistem compatibil determinat')
s=inv(A)*b
ss=A\b
disp(blanks(2)')
pause
A=subs(A,alpha,0)
disp('Cazul: alpha==0 si gamma~=0 -> sistem incompatibil')
disp(blanks(2)')
pause
disp(['Cazul: alpha==0,beta~=0,gamma==0 -> sistem compatibil '...
    'nedeterminat'])
b=subs(b,gamma,0);
disp('Solutia: (0,y,0) cu y real oarecare')