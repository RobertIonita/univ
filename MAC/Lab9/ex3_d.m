y0=[0;0.2;-0.1];
dom=[0,3];
[xn,yn]=ode23('ex3_d_func',dom,y0);
plot(xn,yn(:,1),'r',xn,yn(:,2),'r-.',xn,yn(:,3),'r*');