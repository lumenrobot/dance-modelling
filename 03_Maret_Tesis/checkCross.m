function [crs] = checkCross(RJoint,LJoint,LB)
%% 13 Maret 2014 02:24
%% Check whether two joints clapped or crossed
%% RJoint and LJoint dimension is each 1x3
%% LB is Length of Block

crs = '00'; % the joints are not clapped or crossed
%% Check Delta

if (RJoint(1)-LJoint(1)>0) % && abs(Delta(2))<LB && abs(Delta(3))<LB)
	crs = '11'; % cross
elseif (abs(RJoint(1)-LJoint(1))<LB)
	crs = '01'; % clap
end;