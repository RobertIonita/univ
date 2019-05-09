
[X,Y] = meshgrid(-9:0.5:8);
Z = -2*(X.^2 + Y.^2);
surf(X,Y,Z), grid;


[X, Y, Z] = cylinder([10, 0], 4), grid;

%surf(X,Y,Z), grid;