%cerc de centru (0,0) si raza 2
theta = 0:pi/60:2*pi; 
r = 2;
x = r*cos(theta);
y = r*sin(theta);
plot(x,y,'r--')
hold on

x1 = y -1;
y1 = -x + 1;

plot(x1,y1,'b')
axis equal, grid, hold off
