%% 	getRawData_withImu.m
%% 	(1) Get raw data, result of capturing using nidgui.m, without Imu
%%	(2)	Time stamp conversion
%%	Update 26/6/2014
%%	Update 2/7/2014

CHip = xlsread(CaptJntFile,1);	% Torso
Spine = xlsread(CaptJntFile,2);	% Torso
CShld = xlsread(CaptJntFile,3);	% Torso
Head = xlsread(CaptJntFile,4);
LShld = xlsread(CaptJntFile,5);	% Torso
LElbw = xlsread(CaptJntFile,6);
LWrst = xlsread(CaptJntFile,7);
RShld = xlsread(CaptJntFile,9);	% Torso
RElbw = xlsread(CaptJntFile,10);
RWrst = xlsread(CaptJntFile,11);
LHip = xlsread(CaptJntFile,13);	% Torso
RHip = xlsread(CaptJntFile,17);	% Torso

tcapt = [(RShld(:,5)*60 + RShld(:,6))];
CHip = [-CHip(:,7), CHip(:,8), CHip(:,9)];
Spine = [-Spine(:,7), Spine(:,8), Spine(:,9)];
CShld = [-CShld(:,7), CShld(:,8), CShld(:,9)];
LShld = [-LShld(:,7), LShld(:,8), LShld(:,9)];
LElbw = [-LElbw(:,7), LElbw(:,8), LElbw(:,9)];
LWrst = [-LWrst(:,7), LWrst(:,8), LWrst(:,9)];
RShld = [-RShld(:,7), RShld(:,8), RShld(:,9)];
RElbw = [-RElbw(:,7), RElbw(:,8), RElbw(:,9)];
RWrst = [-RWrst(:,7), RWrst(:,8), RWrst(:,9)];
LHip = [-LHip(:,7), LHip(:,8), LHip(:,9)];
RHip = [-RHip(:,7), RHip(:,8), RHip(:,9)];
