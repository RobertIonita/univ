function dy=ex3_d_func(t,y)
dy=zeros(3,1);
dy(1)=-2*y(1)+y(2)-2*y(3)+sin(t);
dy(2)=y(1)-2*y(2)+2*y(3)-cos(t);
dy(3)=3*y(1)-3*y(2)+5*y(3);