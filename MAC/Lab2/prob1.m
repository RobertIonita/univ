for i = 1:4
    for j=i:5
        M(i,j) = (i*j)/(i+j-1)
    end
end

for i = 1:4
    for j=i:5
        if i==j
            A(i,j) = 3;
        elseif abs(i-j) == 2
            A(i,j) = -3;
            else 
                A(i,j) = 0;
        end
    end
end