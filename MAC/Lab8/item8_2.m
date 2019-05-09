x=[0 1 2 3 4 5 6];
y=[15 30 75 60 60 40 55];
vx=[0.5 3.2 5.7]; 
P2 = polyfit(x,y,2); %regresie parabolica
P5 = polyfit(x,y,5); %aproximare cele mai mici patrate, polinom gradul 5
disp('Valorile lui f obtinute prin interpolare liniara: ')
vy_linear = interp1(x,y,vx,'linear')

disp('Valorile lui f obtinute prin interpolare Hermite cubica')
vy_Hermite = interp1(x,y,vx, 'cubic')

disp('Valorile lui f obtinute prin interpolare spline cubica')
vy_spline = spline(x,y,vx)

disp('Valorile lui f obtinute prin regresie parabolica')
vy2 = polyval(P2,vx)

disp('Valorile lui f obtinute prin metoda regresiei de gradul 5') 
vy5 = polyval(P5,vx)
plot(x,y,'r')
hold on
plot(vx,vy_linear,'g')
hold on
plot(vx, vy_Hermite, 'k')
hold on
plot(vx, vy_spline, 'b--')
hold on
plot(vx, vy2, 'y-')
hold on
plot(vx, vy5, 'c')
legend('punte', 'interpolare liniara', 'interpolare Hermite', 'interpolare spline','regresie parabolica', 'regresie de gradul 5')
hold off



