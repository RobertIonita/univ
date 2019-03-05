function [out1, out2, out3] = mymax(in)

%This function calculates the maximum of the
% five numbers given as input
lines = size(in, 1)
cols = size(in, 2)

if cols < 4 || lines < 4
    disp("error");
else
    out1 = in(3, :);
    out2 = in(:, cols);
    out3 = in(lines, :);
     
    in
    
    disp(out1);
    disp(out2);
    disp(out3);
end