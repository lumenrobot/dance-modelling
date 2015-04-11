function [ClusterBit] = clust4_90(theta)

%% Cluster theta to 8 cluster
%% 
%%
theta = fix(theta);
if (theta<0)
	theta = 360+theta;
end;

if 	(-1<theta && theta<22.5)		
	ClusterBit = '00';
elseif (22.5<theta && theta<45.5)	
	ClusterBit = '01';
elseif (45.5<theta && theta<67.5) 
	ClusterBit = '10';
elseif (67.5<theta)
	ClusterBit = '11';
end

