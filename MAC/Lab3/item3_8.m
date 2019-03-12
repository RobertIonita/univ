x = -3:0.2:3;
y = -3:0.2:3;
[x, y] = meshgrid(x, y);
z = x.^3 - 3.*x .* y.^2;
plot3(x, y, z);