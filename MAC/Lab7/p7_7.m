clear,clc
x=-6:0.01:6; 
plot(x,p7_7_f(x))
g = @(x) - p7_7_f(x);

[xmax,fmax]=fminbnd(g,-6,-4);
fprintf('punct de maxim: %g, maximul: %g\n',xmax,-fmax)
[xmin,fmin]=fminbnd('p7_7_f',-2,-1.5);
fprintf('punct de minim: %g, minimul: %g\n',xmin,fmin)
[xmax,fmax]=fminbnd(g,-1,0);
fprintf('punct de maxim: %g, maximul: %g\n',xmax,-fmax)
[xmin,fmin]=fminbnd('p7_7_f',-0.5, 0.5);
fprintf('punct de minim: %g, minimul: %g\n',xmin,fmin)
[xmax,fmax]=fminbnd(g,1.5,3.5);
fprintf('punct de maxim: %g, maximul: %g\n',xmax,-fmax)
[xmin,fmin]=fminbnd('p7_7_f',4, 5);
fprintf('punct de minim: %g, minimul: %g\n',xmin,fmin)