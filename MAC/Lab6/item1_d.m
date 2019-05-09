
x = -5:0.1:10;

h = (x-3).^2 + 5;
g = cos(abs(x));

plot (x, h, x, g)
[x0, y0] = ginput;