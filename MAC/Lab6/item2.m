x0 = -1);

options=optimset('Tolx',10^(-6));

[x,fval,exitflag,output]=fzero('item2_f',x0,options)


iter=output.iterations