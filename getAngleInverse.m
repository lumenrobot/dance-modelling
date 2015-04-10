function [ArmInverse] = getAngleInverse(RShld,RElbw,RWrst,LShld,LElbw,LWrst)
%% 14 Maret 2014 13:27
%% The function counts the angle of shoulders and elbows
%% Using inverse kinematics, without re-orient the torso
%% Each joint dimension is 1x3

%% Count tilt angle and rotate angle of right shoulder.
Delta = RElbw-RShld;
R = sqrt(((RShld(1)-RElbw(1))^2) + ...
		((RShld(2)-RElbw(2))^2) + ...
		((RShld(3)-RElbw(3))^2));
RShldTilt = (acos(Delta(1)/R)/pi)*180;
RShldRotate = (atan(abs(Delta(3)/Delta(2)))/pi)*180; % ok 15/3/2014

%% Count tilt angle and rotate angle of right elbow.
%% Rotate axis
[RElbw(2) RElbw(3)] = op_rotate(RElbw(2),RElbw(3),RShld(2),RShld(3),-RShldRotate);	%ok
[RElbw(1) RElbw(2)] = op_rotate(RElbw(1),RElbw(2),RShld(1),RShld(2),-RShldTilt);	%ok
[RWrst(2) RWrst(3)] = op_rotate(RWrst(2),RWrst(3),RShld(2),RShld(3),-RShldRotate);	%ok
[RWrst(1) RWrst(2)] = op_rotate(RWrst(1),RWrst(2),RShld(1),RShld(2),-RShldTilt);	%ok
Delta = RWrst-RElbw;
R = sqrt(((RElbw(1)-RWrst(1))^2) + ...
		((RElbw(2)-RWrst(2))^2) + ...
		((RElbw(3)-RWrst(3))^2));
RElbwTilt = (acos(Delta(1)/R)/pi)*180; %ok banget
RElbwRotate = (atan(abs(Delta(3)/Delta(2)))/pi)*180; % -RShldRotate;

%% Count tilt angle and rotate angle of left shoulder.
Delta = LElbw-LShld;
R = sqrt(((LShld(1)-LElbw(1))^2) + ...
		((LShld(2)-LElbw(2))^2) + ...
		((LShld(3)-LElbw(3))^2));
LShldTilt = (acos(-Delta(1)/R)/pi)*180;
LShldRotate = (atan(abs(Delta(3)/Delta(2)))/pi)*180; % ok 15/3/2014

%% Count tilt angle and rotate angle of left elbow.
%% Rotate axis
[LElbw(2) LElbw(3)] = op_rotate(LElbw(2),LElbw(3),LShld(2),LShld(3),-LShldRotate);	%ok
[LElbw(1) LElbw(2)] = op_rotate(LElbw(1),LElbw(2),LShld(1),LShld(2),LShldTilt);	%ok
[LWrst(2) LWrst(3)] = op_rotate(LWrst(2),LWrst(3),LShld(2),LShld(3),-LShldRotate);	%ok
[LWrst(1) LWrst(2)] = op_rotate(LWrst(1),LWrst(2),LShld(1),LShld(2),LShldTilt);	%ok
Delta = LWrst-LElbw;
R = sqrt(((LElbw(1)-LWrst(1))^2) + ...
		((LElbw(2)-LWrst(2))^2) + ...
		((LElbw(3)-LWrst(3))^2));
LElbwTilt = (acos(-Delta(1)/R)/pi)*180;
LElbwRotate = (atan(abs(Delta(3)/Delta(2)))/pi)*180; % ok 15/3/2014

%% Taruh di Tabel
ArmInverse = [LElbwRotate LElbwTilt LShldRotate LShldTilt ...
				RShldTilt RShldRotate RElbwTilt RElbwRotate];


