clear, clc
v = [0.6, -0.2, -0.1];
[xmin, fmin, exit, det] = fminsearch('p7_9_f', v);
fprintf('\nmin: [%g %f]', xmin);
fprintf('\nminimul: %g\n', fmin);
fprintf('\nalgorithm: %s\n', det.algorithm);