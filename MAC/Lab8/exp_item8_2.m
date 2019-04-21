x = [-1.5 0 1 3];
y = [7.8 5 6.3 6.8];
vx = -1.5:0.1:3;
vy_linear = interp1(x,y,vx, 'linear');
vy_spline = spline(x,y,vx);
plot(x,y,'ro',vx,vy_linear, 'g', vx, vy_spline, 'b--')
legend('points', 'linear', 'spline');
