%% Bismillahirrahmanirrahim
%% Data Kinect harus kerekam hari ini.
%% Beres 19 Feb

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear; clc;
trec = 09; 		% Rekaman ke 2,3 icun, 4,5,6 santi
tcapt = 500; 	% Lama capture kinect
tday = 735787; 	% 07 Juli 2014
CaptImuFile = sprintf('capture_%d_imu.txt',trec);
CaptJntFile = sprintf('capture_PosLeft%d.mat', trec);
fprintf('=========================================\n');
fprintf('Bismillahirrahmanirrahim, %s.\nRekaman ke %d, %d kali.\n', datestr(tday), trec, tcapt);
fprintf('=========================================\n'); pause(1);

%% Load the simulink model
load_system('nid_thesis');	%% Invisibly load a simulink model
% open_system('nid_thesis');	%% Open a Simulink system window

%% Start Simulink Simulation
set_param('nid_thesis', 'SimulationCommand', 'start');
fprintf(' - The simulink model has been loaded and started.\n'); pause(1);

%% Setting and capture Realterm
% hrealterm = actxserver('realterm.realtermintf'); %% Start Realterm as a server
% hrealterm.baud		=	57600;	% set baudrate
% hrealterm.Port 		= 	'13'; 	% set port 5
% hrealterm.PortOpen	=	1;		% open the comm port
% hrealterm.CaptureFile	= CaptImuFile;
% invoke(hrealterm, 'timestamp', '3'); % Matlab timestamp
% invoke(hrealterm,'startcapture'); % Start realterm capture
% fprintf(' - Realterm has been activated and started to capture.\n'); pause(1);

%% Initiate the variable
rto = get_param('nid_thesis/Skeleton Viewer', 'RuntimeObject');
Joint = {
	[datevec(now) rto.InputPort(2).Data(:,1,1) rto.InputPort(2).Data(:,1,2) rto.InputPort(2).Data(:,1,3)]; % CHip
	[datevec(now) rto.InputPort(2).Data(:,2,1) rto.InputPort(2).Data(:,2,2) rto.InputPort(2).Data(:,2,3)]; % Spine
	[datevec(now) rto.InputPort(2).Data(:,3,1) rto.InputPort(2).Data(:,3,2) rto.InputPort(2).Data(:,3,3)]; % CShld
	[datevec(now) rto.InputPort(2).Data(:,4,1) rto.InputPort(2).Data(:,4,2) rto.InputPort(2).Data(:,4,3)]; % Head
	[datevec(now) rto.InputPort(2).Data(:,5,1) rto.InputPort(2).Data(:,5,2) rto.InputPort(2).Data(:,5,3)]; % LShld
	[datevec(now) rto.InputPort(2).Data(:,6,1) rto.InputPort(2).Data(:,6,2) rto.InputPort(2).Data(:,6,3)]; % LElbw
	[datevec(now) rto.InputPort(2).Data(:,7,1) rto.InputPort(2).Data(:,7,2) rto.InputPort(2).Data(:,7,3)]; % LWrst
	[datevec(now) rto.InputPort(2).Data(:,8,1) rto.InputPort(2).Data(:,8,2) rto.InputPort(2).Data(:,8,3)]; % LHand
	[datevec(now) rto.InputPort(2).Data(:,9,1) rto.InputPort(2).Data(:,9,2) rto.InputPort(2).Data(:,9,3)]; % RShld
	[datevec(now) rto.InputPort(2).Data(:,10,1) rto.InputPort(2).Data(:,10,2) rto.InputPort(2).Data(:,10,3)]; % RElbw
	[datevec(now) rto.InputPort(2).Data(:,11,1) rto.InputPort(2).Data(:,11,2) rto.InputPort(2).Data(:,11,3)]; % RWrst
	[datevec(now) rto.InputPort(2).Data(:,12,1) rto.InputPort(2).Data(:,12,2) rto.InputPort(2).Data(:,12,3)]; % RHand
	[datevec(now) rto.InputPort(2).Data(:,13,1) rto.InputPort(2).Data(:,13,2) rto.InputPort(2).Data(:,13,3)]; % LHip
	[datevec(now) rto.InputPort(2).Data(:,14,1) rto.InputPort(2).Data(:,14,2) rto.InputPort(2).Data(:,14,3)]; % LKnee
	[datevec(now) rto.InputPort(2).Data(:,15,1) rto.InputPort(2).Data(:,15,2) rto.InputPort(2).Data(:,15,3)]; % LAnkle
	[datevec(now) rto.InputPort(2).Data(:,16,1) rto.InputPort(2).Data(:,16,2) rto.InputPort(2).Data(:,16,3)]; % LFoot
	[datevec(now) rto.InputPort(2).Data(:,17,1) rto.InputPort(2).Data(:,17,2) rto.InputPort(2).Data(:,17,3)]; % RHip
	[datevec(now) rto.InputPort(2).Data(:,18,1) rto.InputPort(2).Data(:,18,2) rto.InputPort(2).Data(:,18,3)]; % RKnee
	[datevec(now) rto.InputPort(2).Data(:,19,1) rto.InputPort(2).Data(:,19,2) rto.InputPort(2).Data(:,19,3)]; % RAnkle
	[datevec(now) rto.InputPort(2).Data(:,20,1) rto.InputPort(2).Data(:,20,2) rto.InputPort(2).Data(:,20,3)]} % RFoot

%%
%% Capture from kinect
fprintf(' - Start to capture from kinect %2.0f times after 10 sec.\n', tcapt);
fprintf(' - 10..'); pause(1); fprintf('9..'); pause(1); fprintf(' 8..'); pause(1); 
fprintf('7..'); pause(1); fprintf('6..'); pause(1); fprintf('5..'); pause(1); 
fprintf('4..'); pause(1); fprintf('3..'); pause(1); fprintf('2..'); pause(1);
fprintf('1..\n\n'); pause(1);


%% Capturing Loop
for (j = 1:tcapt)
	if (rto.InputPort(1).Data == 1) %% Check Tracking Status
		for i = 1:20
			Joint{i} = [Joint{i}; datevec(now) rto.InputPort(2).Data(:,i,1) rto.InputPort(2).Data(:,i,2) rto.InputPort(2).Data(:,i,3)];
		end
		pause(0.005);
		fprintf('\n%d',j);
	end
end
fprintf('\n - Gestures have been captured :) \n'); pause(1);

%% Save to mat/excel file
% for i=1:20
	% xlswrite (CaptJntFile, Joint{i}, i);
% end
 save(CaptJntFile, 'Joint')
fprintf(' - All data has been saved to mat file :) \n'); pause(1);

%% Stop Simulink Simulation
% set_param(modelName, 'SimulationCommand', 'continue');
% set_param(modelName, 'SimulationCommand', 'pause');
set_param('nid_thesis', 'SimulationCommand', 'stop');
fprintf(' - Stop the simulink model.\n'); pause(1);

%% Stop Realterm capture
% invoke(hrealterm,'stopcapture');
% hrealterm.PortOpen	=	0;		% close the comm port
% invoke(hrealterm,'close'); 
% delete(hrealterm);
% fprintf(' - Stop the Realterm.\n'); pause(1);
fprintf(' - One recorded dance no.%d has been recorded, alhamdulillah :)\n\n', trec);