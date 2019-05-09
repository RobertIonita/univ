x=-8:2:4;
y=[30 10 9 6 5 4 4];
p2 = polyfit(x,y,2);
p3 = polyfit(x,y,3);
p6 = polyfit(x,y,6);
vx = [-7 -4.2 -0.75 1 2.25 3];
disp('parabolic: ');
vy2 = polyval(p2, vx)
disp('cubic: ');
vy3 = polyval(p3, vx)
disp('6th order: ');
vy6 = polyval(p6, vx)

vxg=min(x):(max(x)-min(x))/100:max(x);
vy2g=polyval(p2,vxg);
vy3g=polyval(p3,vxg);
vy6g=polyval(p6,vxg);
plot(x, y, 'bd')
hold on
plot(vxg,vy2g,'r',vxg,vy3g, '--g',vxg,vy6g,'k:')
axis([min(x)-1 max(x)+1 ;min([y vy2g vy3g vy6g]) -5 max([y vy2g vy3g vy6g]) +5])
legend('points', 'parabolic', 'cubic', '6th order')
hold off