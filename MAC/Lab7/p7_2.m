theta = 0:pi/60:pi*2;
r = sqrt(4);
x = r*cos(theta);
y = r*sin(theta);
plot(x,y, 'r--'), grid;
hold on

x1 = -3:0.1:-1;
y11 = sqrt(x1.^2 - 1);
y12 = -y11;

x2 = sort(-x1);
y21 = sqrt(x2.^2 - 1);
y22 = -y21;

plot(x1, y11, 'b', x1, y12, 'b', x2, y21, 'b', x2, y22, 'b');
hold off
[xcoord, ycoord] = ginput;

disp('solutions:');
for i = 1:length(xcoord)
   sol = fsolve('p7_2_f', [xcoord(i), ycoord(i)]);
end
disp(sol);
