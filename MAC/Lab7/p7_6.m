x0 = -5;
[xmin, fmin, termin, det] = fminsearch('p7_6_f', x0);

disp(xmin);
disp(fmin);
disp(det.message);