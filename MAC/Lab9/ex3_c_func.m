function dy = ex3_c_func(x,y)
dy=zeros(3,1);
dy(1)=y(2);
dy(2)=y(3);
dy(3)=y(3)-x.*y(2)+2*y(1).*sin(x)-x.^3;