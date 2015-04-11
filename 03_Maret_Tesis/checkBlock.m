function [SymBlk] = checkBlock(Joint,Center,LB)
%% Check where the joint were placed in 7x7x4 block of upper body space
%% Delta of Joint and Center, ok 01:28
%% Joint and Center dimension is each 1x3
%% LB is Length of Block

Delta = Joint-Center;
%% Check Block
if (Delta(1) > 2.5*LB)							Xb ='111';	% 7
elseif(2.5*LB > Delta(1)&& Delta(1) > 1.5*LB)	Xb ='110';	% 6
elseif(1.5*LB > Delta(1)&& Delta(1) > 0.5*LB)	Xb ='101';	% 5
elseif(0.5*LB > Delta(1)&& Delta(1) > -0.5*LB)	Xb ='100';	% 4
elseif(-0.5*LB > Delta(1)&& Delta(1) > -1.5*LB)	Xb ='010';	% 2
elseif(-1.5*LB > Delta(1)&& Delta(1) > -2.5*LB)	Xb ='001';	% 1
elseif(-2.5*LB > Delta(1))						Xb ='000';	% 0
end
if (Delta(2) > 2.5*LB)							Yb ='111';	% 7
elseif(2.5*LB > Delta(2)&& Delta(2) > 1.5*LB)	Yb ='110';	% 6
elseif(1.5*LB > Delta(2)&& Delta(2) > 0.5*LB)	Yb ='101';	% 5
elseif(0.5*LB > Delta(2)&& Delta(2) > -0.5*LB)	Yb ='100';	% 4
elseif(-0.5*LB > Delta(2)&& Delta(2) > -1.5*LB)	Yb ='010';	% 2
elseif(-1.5*LB > Delta(2)&& Delta(2) > -2.5*LB)	Yb ='001';	% 1
elseif(-2.5*LB > Delta(2))						Yb ='000';	% 0
end
if (Delta(3) < -2.5*LB)							Zb ='00';	% 0
elseif(-2.5*LB < Delta(3)&& Delta(2) < -1.5*LB)	Zb ='01';	% 1
elseif(-1.5*LB < Delta(2)&& Delta(2) < -0.5*LB)	Zb ='10';	% 2
elseif(-0.5*LB < Delta(2))						Zb ='11';	% 4
end
SymBlk = [Xb Yb Zb];