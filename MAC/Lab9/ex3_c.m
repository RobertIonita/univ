y0=[0.5;-0.5;0.3];
dom=[1,4]
[xn,yn]=ode23('ex3_c_func',dom,y0);
plot(xn,yn(:,1),'r')