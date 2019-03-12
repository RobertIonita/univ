rc1 = 2;
rc2 = 1;
rp = 3;
h = 3;
n = 6;

[xp, yp, z] = cylinder([rc1 rc2], n);

zp = h*z;

surf(xp, yp, zp)

colormap(pink);
axis('equal')