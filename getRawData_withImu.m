%% 	getRawData_withImu.m
%% 	(1) Get raw data, result of capturing using nidgui.m, with Imu
%%	(2)	Time stamp conversion
%%	Update 26/6/2014
%%	Update 2/7/2014

CaptJntFile = 'capture_2_joint_imu';
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
Imu = xlsread(CaptJntFile,21);

%% 	Konversi info waktu dari format vec ke sec
dateImu = datevec(Imu(:,1));
Imu(:,1) = (dateImu(:,5)*60 + dateImu(:,6));
dateJnt = datevec(RShld(:,1));
tcapt = [(dateJnt(:,5)*60 + dateJnt(:,6))];

CHip = [-CHip(:,2), CHip(:,3), CHip(:,4)];
Spine = [-Spine(:,2), Spine(:,3), Spine(:,4)];
CShld = [-CShld(:,2), CShld(:,3), CShld(:,4)];
LShld = [-LShld(:,2), LShld(:,3), LShld(:,4)];
LElbw = [-LElbw(:,2), LElbw(:,3), LElbw(:,4)];
LWrst = [-LWrst(:,2), LWrst(:,3), LWrst(:,4)];
RShld = [-RShld(:,2), RShld(:,3), RShld(:,4)];
RElbw = [-RElbw(:,2), RElbw(:,3), RElbw(:,4)];
RWrst = [-RWrst(:,2), RWrst(:,3), RWrst(:,4)];
LHip = [-LHip(:,2), LHip(:,3), LHip(:,4)];
RHip = [-RHip(:,2), RHip(:,3), RHip(:,4)];

%%	Menaruh Info tepukan, OK 2/7/2014
sizeimu = size(Imu);
sizejnt = size(CHip);
for i=1:sizeimu(1)
	if (Imu(i,5) == 1)
		for j = 1:sizejnt(1);
			if((Imu(i,1)-tcapt(j,1))<0.1 && (tcapt(j,1)-Imu(i,1))<0.1)
				tcapt(j,2) = 1;
			end	
		end
	end
end

