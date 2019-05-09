x0 = 1;

options=optimset('Tolx',10^(-10));

x =fzero('item1_f',x0,options);

[x,fval,exitflag,output]=fzero('item1_f',x0,options);
x

iter=output.iterations