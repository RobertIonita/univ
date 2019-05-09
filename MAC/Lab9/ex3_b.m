y0=[-1;2];
dom=[0,6];
[tn,yn]=ode23('ex3_b_func',dom,y0);
plot(tn,yn(:,1),'b-');