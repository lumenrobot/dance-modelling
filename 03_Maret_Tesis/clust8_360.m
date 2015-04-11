function [ClusterBit] = clust8_360(theta)

%% Cluster theta to 8 cluster
%% 
%%
theta = fix(theta);
if (theta<0)
	theta = 360+theta;
end;

if 	(theta>22.5 && theta<67.5)		
	ClusterBit = '001';
elseif (theta>67.5 && theta<112.5)	
	ClusterBit = '010';
elseif (theta>112.5 && theta<157.5) 
	ClusterBit = '011';
elseif (theta>157.5 && theta<202.5) 
	ClusterBit = '111';
elseif (theta>202.5 && theta<247.5) 
	ClusterBit = '110';
elseif (theta>247.5 && theta<292.5) 
	ClusterBit = '101';
elseif (theta>292.5 && theta<337.5) 
	ClusterBit = '100';
else	(theta>337.5 && theta<22.5)	
	ClusterBit = '000';
end;

