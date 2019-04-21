y0=2;
dom = [-1,5];
[xval,yval] = ode23('ex3_a_func',dom,y0);
plot(xval,yval)
