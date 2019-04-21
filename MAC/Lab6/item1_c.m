
x = 3.1:0.1:5;

h = 2.^(-sin(x)) + 4;
g = x.* log(x);

plot (x, h, x, g)
[x0, y0] = ginput;