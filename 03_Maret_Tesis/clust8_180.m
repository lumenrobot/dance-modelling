function [ClusterBit] = clust8_180(theta)

%% Cluster theta to 8 cluster
%% 
%%
theta = fix(theta);
if (theta<0)
	theta = 360+theta;
end;

if 	(theta>22.5 && theta<45.5)		
	ClusterBit = '001';
elseif (theta>45.5 && theta<67.5)	
	ClusterBit = '010';
elseif (theta>67.5 && theta<90.5) 
	ClusterBit = '011';
elseif (theta>90.5 && theta<112.5) 
	ClusterBit = '111';
elseif (theta>112.5 && theta<135.5) 
	ClusterBit = '110';
elseif (theta>135.5 && theta<157.5) 
	ClusterBit = '101';
elseif (theta>157.5 && theta<180.5) 
	ClusterBit = '100';
else	(theta>-0.5 && theta<22.5)
	ClusterBit = '000';
end;

