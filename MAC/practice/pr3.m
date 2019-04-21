%5_1

c1=[1 -3 -1 3]; 
sol1 = roots(c1);

%5_2

c2 = [4 -13 10];
root2 = roots(c2);

for i=1:length(root2)
    if root2(i) >= 1.5
        sol2(i) = root2(i);
    end
end

%5_3
c3=[1 1 -2 4 11 -45 -50 0];
root3=roots(c3);
j=1;
for i=1:length(root3)
    if real(root3(i))>0
        sol3(j)=root3(i); 
        j=j+1;
    end
end

sol3;