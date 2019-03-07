t = -3:(6/1000):3;

y1 = sin(pi.*t).*cos(pi.*t);
y2 = sin(pi.*t+1).*cos(pi.*t+1);
plot(t, y1, 'b-', t, y2, 'ro');