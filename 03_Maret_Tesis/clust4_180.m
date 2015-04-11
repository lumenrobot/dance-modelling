function [ClusterBit] = clust4_180(theta)

%% Cluster theta to 8 cluster
%% 
%%
theta = fix(theta);
if (theta<0)
	theta = 360+theta;
end;

if 	(-0.5<theta && theta<45.5)		
	ClusterBit = '00';
elseif (45.5<theta && theta<90.5)	
	ClusterBit = '01';
elseif (90.5<theta && theta<135.5) 
	ClusterBit = '10';
elseif( 135.5<theta)
	ClusterBit = '11';
end;

