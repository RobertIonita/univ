A = [1 1 0 0 0]
sol = roots(A)

if imag(sol) == 0
    disp('Solutiile reale sunt: ');
    sol
end