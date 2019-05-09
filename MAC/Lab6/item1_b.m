x0 = (-3);

options=optimset('Tolx',10^(-6));

[x,fval,exitflag,output]=fzero('item1_b_f',x0,options)


iter=output.iterations