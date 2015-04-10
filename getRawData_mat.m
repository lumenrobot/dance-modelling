%% 	getRawData_withImu.m
%% 	(1) Get raw data, result of capturing using nidgui.m, with .mat format
%%	(2)	Time stamp conversion
%%	Update 26/6/2014
%%	Update 2/7/2014
%%	Update 8/7/2014

%load('capture_PosFront1.mat');
function [phrase] = getRawData_mat(Joint)

CHip = Joint{1};	% Torso
Spine = Joint{2};	% Torso
CShld = Joint{3};	% Torso
Head = Joint{4};
LShld = Joint{5};	% Torso
LElbw = Joint{6};
LWrst = Joint{7};
RShld = Joint{9};	% Torso
RElbw = Joint{10};
RWrst = Joint{11};
LHip = Joint{13};	% Torso
RHip = Joint{17};	% Torso

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

lg = length(tcapt);
%% 	1	234		567		8910	111213	141516	171819	202122	232425	262728	293031	323334]
%%	t	Spine	CHip	RHip	LHip	CShld	RShld	RElbw	RWrst	LShld	LElbw	LWrst
phrase = [tcapt(1:lg) Spine(1:lg,:) CHip(1:lg,:) RHip(1:lg,:) LHip(1:lg,:) CShld(1:lg,:) RShld(1:lg,:) RElbw(1:lg,:) RWrst(1:lg,:) LShld(1:lg,:) LElbw(1:lg,:) LWrst(1:lg,:)];


