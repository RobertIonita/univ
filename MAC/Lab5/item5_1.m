a=[2 -3 3 -10 -8];
disp('Solutiile ecuatiei a: '), sol=roots(a)

rad = roots=([1 2 4 2 0]);
sol=[];
for i=1:length(rad)
    if imag(rad(i))==0 & rad(i)>=1.5
        sol=[sol rad(i)];
    end
end
disp('Solutiile ecuatiei algebrice:')
format short g
sol