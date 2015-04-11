function [ClusterBit] = clust4(theta)

%% Cluster theta to 8 cluster
%% 
%%
theta = fix(theta);
if (theta<0)
	theta = 360+theta;
end;

if 	(theta>0 && theta<45)		
	ClusterBit = '00';
elseif (theta>45 && theta<90)	
	ClusterBit = '01';
elseif (theta>90 && theta<135) 
	ClusterBit = '10';
elseif (theta>135 && theta<180) 
	ClusterBit = '11';
end

