clear, clc
v = [1 0];
opt = optimset('LargeScale', 'Off');
[xmin, fmin, exit, det] = fminunc('p7_8_f', v, opt);
fprintf('\nmin: [%g %f]', xmin);
fprintf('\nminimul: %g\n', fmin);
fprintf('\nalgorithm: %s\n', det.algorithm);