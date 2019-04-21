function dy=ex3_b_func(t,y)
dy=zeros(2,1);
dy(2)=y(2)+2.*y(1).*sin(t);