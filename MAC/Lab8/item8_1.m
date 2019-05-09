x = [0 1 1.2 1.4 1.7 2];
y = [-2.5 0 2 1.7 -4 1];
vx = [0.7 1.3 1.7 2.5 2.9];
vy = interp1(x,y,vx, 'cubic');
disp('Valorile:');
disp(vy);