% getQuantAngle.m
% 0. Input = joint positions, each dimension is 1x3
% 1. Get torso frame using PCA
% 2. Re-orient joint position of arms relative to torso frame
% 3. Count 8 principal angle of shoulders and elbows (angle_datum) for one pose
% 4. Quantize its 8 principal angle to 8 quantization, each has its codewords
% Last update 5/7/2014

function [armAngle, armQuant] = getQuantAngle(Spine,CHip,RHip,LHip,CShld,RShld,RElbw,RWrst,LShld,LElbw,LWrst)
% function [armAngle] = getQuantAngle(Spine,CHip,RHip,LHip,CShld,RShld,RElbw,RWrst,LShld,LElbw,LWrst)

Torso = [CShld; RShld; LShld; Spine; CHip; RHip; LHip];
UpperBody = [CShld; RShld; RElbw; RWrst; LShld; LElbw; LWrst; Spine; CHip; RHip; LHip];

%% Get torso frame using PCA
R_0 = [1 0 0; 0 1 0; 0 0 1];
R_torso = -pca(Torso);

%% Get R_torso using Gram - Schmidt, (Trial)
% u = Torso(5,:)-Torso(1,:); 	% Get u = CShld - Chip
% r = Torso(2,:)-Torso(3,:);	% Get r = LShld - RShld
% r = r - op_proj(r,u);			% Gram-Schmidt process
% t = cross(u,r);
% R_torso1 = [u;r;t];			% R_torso = {r,u,t}

%% Get Upper Arm spherical coordinate relative to R_torso
upRArm = RElbw - RShld;				% Vector (RS,RE)
upRArm_torso = (R_torso*upRArm')';	% Vector (RS,RE) relative to R_torso
upLArm = LElbw - LShld;				% Vector (LS,LE)
upLArm_torso = (R_torso*upLArm')';	% Vector (LS,LE) relative to R_torso
[azi_RS, ele_RS, r] = cart2sph(upRArm_torso(1), upRArm_torso(3), upRArm_torso(2));
[azi_LS, ele_LS, r] = cart2sph(upLArm_torso(1), upLArm_torso(3), upLArm_torso(2));
% ^ Azimuth and Elevation angle of shoulder 3/7/2014

%% Get Lower Arm spherical coordinate relative to R_RArm or R_RArm
R_r_azi_RS = [cos(azi_RS) 0 sin(azi_RS); 0 1 0; sin(-azi_RS) 0 cos(azi_RS)];
R_t_ele_RS = [cos(-ele_RS) -sin(-ele_RS) 0; sin(-ele_RS) cos(-ele_RS) 0; 0 0 1];
R_RArm = R_r_azi_RS*R_torso;
R_RArm = R_t_ele_RS*R_RArm;			% Tranformation result of R_torso to Right Upper Arm 3/7/2014
R_r_azi_LS = [cos(azi_LS) 0 sin(azi_LS); 0 1 0; sin(-azi_LS) 0 cos(azi_LS)];
R_t_ele_LS = [cos(-ele_LS) -sin(-ele_LS) 0; sin(-ele_LS) cos(-ele_LS) 0; 0 0 1];
R_LArm = R_r_azi_LS*R_torso;
R_LArm = R_t_ele_LS*R_LArm;			% Tranformation result of R_torso to Right Upper Arm 3/7/2014
loRArm = RWrst - RElbw;					% Vector (RE,RW)
loRArm_RArm = (R_RArm*loRArm')';		% Vector (RE,RW) relative to R_RArm
loLArm = LWrst - LElbw;					% Vector (LE,LW)
loLArm_LArm = (R_LArm*loLArm')';		% Vector (LE,LW) relative to R_LArm
[azi_RE, ele_RE, r] = cart2sph(loRArm_RArm(2), loRArm_RArm(3), loRArm_RArm(1));
[azi_LE, ele_LE, r] = cart2sph(loLArm_LArm(2), loLArm_LArm(3), loLArm_LArm(1));
% ^ Azimuth and Elevation angle of elbow 4/7/2014

%% If want to check using inverse kinematics
% R = sqrt((loRArm_RArm(1)^2) + (loRArm_RArm(2)^2) + (loRArm_RArm(3)^2));
% eleRElbw = (asin(loRArm_RArm(1)/R)/pi)*180
% aziRElbw = (atan((loRArm_RArm(3)/loRArm_RArm(2)))/pi)*180
% R = sqrt((loLArm_LArm(1)^2) + (loLArm_LArm(2)^2) + (loLArm_LArm(3)^2));
% eleLElbw = (asin(loLArm_LArm(1)/R)/pi)*180
% aziLElbw = (atan((loLArm_LArm(3)/loLArm_LArm(2)))/pi)*180

%% Check -- Plot(ZXY)
% plot3(Torso(:,3), Torso(:,1), Torso(:,2), '*k');
% plot3(UpperBody (:,3), UpperBody (:,1), UpperBody (:,2), '.k');
% xlabel('Z'); ylabel('X'); zlabel('Y'); set(gca,'color', [1 1 1]);
% hold on; quiver3(0, 0, 0, R_0(1,3)/2, R_0(1,1)/2, R_0(1,2)/2, 'r');				% ok
% hold on; quiver3(0, 0, 0, R_0(2,3)/2, R_0(2,1)/2, R_0(2,2)/2, 'g');				% ok
% hold on; quiver3(0, 0, 0, R_0(3,3)/2, R_0(3,1)/2, R_0(3,2)/2, 'b');				% ok
% hold on; quiver3(RShld(3), RShld(1), RShld(2), R_torso(1,3)/4, R_torso(1,1)/4, R_torso(1,2)/4, 'r');	% ok
% hold on; quiver3(RShld(3), RShld(1), RShld(2), R_torso(2,3)/4, R_torso(2,1)/4, R_torso(2,2)/4, 'g');	% ok
% hold on; quiver3(RShld(3), RShld(1), RShld(2), R_torso(3,3)/4, R_torso(3,1)/4, R_torso(3,2)/4, 'b');	% ok 1/7/2014
% hold on; quiver3(RShld(3), RShld(1), RShld(2), R_RArm(1,3)/4, R_RArm(1,1)/4, R_RArm(1,2)/4, 'k');
% hold on; quiver3(RElbw(3), RElbw(1), RElbw(2), R_RArm(1,3)/4, R_RArm(1,1)/4, R_RArm(1,2)/4, 'r');
% hold on; quiver3(RElbw(3), RElbw(1), RElbw(2), R_RArm(2,3)/4, R_RArm(2,1)/4, R_RArm(2,2)/4, 'g');
% hold on; quiver3(RElbw(3), RElbw(1), RElbw(2), R_RArm(3,3)/4, R_RArm(3,1)/4, R_RArm(3,2)/4, 'b');	% ok 3/7/2014
% hold on; quiver3(LShld(3), LShld(1), LShld(2), R_LArm(1,3)/4, R_LArm(1,1)/4, R_LArm(1,2)/4, 'k');
% hold on; quiver3(LElbw(3), LElbw(1), LElbw(2), R_LArm(1,3)/4, R_LArm(1,1)/4, R_LArm(1,2)/4, 'r');
% hold on; quiver3(LElbw(3), LElbw(1), LElbw(2), R_LArm(2,3)/4, R_LArm(2,1)/4, R_LArm(2,2)/4, 'g');
% hold on; quiver3(LElbw(3), LElbw(1), LElbw(2), R_LArm(3,3)/4, R_LArm(3,1)/4, R_LArm(3,2)/4, 'b');

armAngle = 	[rad2deg(azi_LE) rad2deg(ele_LE) rad2deg(azi_LS) rad2deg(ele_LS) ...
			rad2deg(ele_RS) rad2deg(azi_RS) rad2deg(ele_RE) rad2deg(azi_RE)];

armQuant =	(quantAzi_LE(armAngle(1))*10^7)+(quantEle_E(armAngle(2))*10^6)+...
			(quantAzi_S(armAngle(3))*10^5)+(quantEle_LS(armAngle(4))*10^4)+...
			(quantEle_RS(armAngle(5))*10^3)+(quantAzi_S(armAngle(6))*100)+...
			(quantEle_E(armAngle(7))*10)+quantAzi_RE(armAngle(8));	% ok 5/7/2014

function deg = rad2deg(rad)
	deg = rad*180/pi;
			
function qS = quantAzi_S(deg)	% Azimuth of Shoulder -75 < azi < 180
	if (112.5<=deg && deg<180)
		qS = 1;
	elseif (67.5<=deg && deg<112.5)
		qS = 2;
	elseif (22.5<=deg && deg<67.5) 
		qS = 3;
	elseif (-22.5<=deg && deg<22.5) 	
		qS = 4;
	elseif (-60<=deg && deg<-22.5) || ...
		(-95<=deg && deg<-60)	% tolerance = 35 if angle go out of ROM
		qS = 5;
	end;

function qS = quantEle_RS(deg)	% Elevation of RS 60 > ele > -180
	if 	(-112.5>=deg && deg>-180)
		qS = 1;
	elseif (-67.5>=deg && deg>-112.5)
		qS = 2;
	elseif (-22.5>=deg && deg>-67.5)
		qS = 3;
	elseif (22.5>=deg && deg>-22.5)	
		qS = 4;
	elseif (75>=deg && deg>22.5) || ...
		(95>=deg && deg>75)	% tolerance = 20 if angle go out of ROM
		qS = 5;
	end;

function qS = quantEle_LS(deg)	% Elevation of RS -60 < ele < 180
	if 	(112.5<=deg && deg<180)
		qS = 1;
	elseif (67.5<=deg && deg<112.5)
		qS = 2;
	elseif (22.5<=deg && deg<67.5) 
		qS = 3;
	elseif (-22.5<=deg && deg<22.5) 	
		qS = 4;
	elseif (-75<=deg && deg<-22.5) || ...
		(-95<=deg && deg<-75)	% tolerance = 30 if angle go out of ROM
		qS = 5;
	end;	
		
function qE = quantAzi_RE(deg)	% Azimuth of RE 0 < azi < 160
	% Azimuth degree of elbow considered to be unnegative number,
	% if it's negative then
	deg = abs(deg);
	if 	(0<=deg && deg<55)
		qE = 1;
	elseif (55<=deg && deg<110)
		qE = 2;
	elseif (110<=deg && deg<160) || ...
		(160<=deg && deg<180)	% tolerance = 20 if angle go out of ROM
		qE = 3;
	end;
	
function qE = quantAzi_LE(deg)	% Azimuth of LE 20 < azi < 180
	% Azimuth degree of elbow considered to be unnegative number,
	% if it's negative then
	deg = abs(deg);
	if 	(125<=deg && deg<180)
		qE = 1;
	elseif (70<=deg && deg<125)
		qE = 2;
	elseif (20<=deg && deg<70) || ...
		(0<=deg && deg<20)	% tolerance = 20 if angle go out of ROM
		qE = 3;
	end;
	
function qE = quantEle_E(deg)	% Elevation of Elbow -60 < ele < 90
	if 	(40<=deg && deg<90)
		qE = 1;
	elseif (-10<=deg && deg<40)
		qE = 2;
	elseif (-60<=deg && deg<-10) || ...
		(-90<=deg && deg<-60)	% tolerance = 30 if angle go out of ROM
		qE = 3;
	end;
	