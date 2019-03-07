t = -10*pi:0.1:10*pi;

y = sin((t.*0.5)-3);
z = cos(t.*0.5);

plot3(y,z,t);