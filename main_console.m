% main_console.m
% Pengujian Gesture dan Frase, Realtime, menggunakan Console
% Bismillahirrahmanirrahim
% 22-24 Juli 2014


%%	Initiation
load_system('nid_thesis');		% Invisibly load a simulink model
% open_system('nid_thesis');	% Open a simulink system window
set_param('nid_thesis', 'SimulationCommand', 'start');	% Start simulink simulation
rto = get_param('nid_thesis/Skeleton Viewer', 'RuntimeObject');
fprintf('Kinect device are ready.\n');
fprintf('Loading the Simulink Model.\n');
fprintf('Starting the Simulink Model.\n');
gesturename = input('Insert gesture name : ', 's');
tcapt = input('Insert capturing period : ');
times = input('Insert capturing times : '); pause(4);
data_capture = {};
lik_all = []; found_all = [];

for k = 1:times
	%%	-------------------------------------------------------------------------------
	%%	Informing user for capturing the data
	fprintf('\n%d) Please Do the %s.   ', k, gesturename);
	fprintf('3..'); pause(1);  fprintf('2..'); pause(1); fprintf('1..\n'); pause(1);
	Joint = {[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[]};
	for (j = 1:tcapt)
		if (rto.InputPort(1).Data == 1) %% Check Tracking Status
			for i = 1:20
				Joint{i} = [Joint{i}; datevec(now) rto.InputPort(2).Data(:,i,1) rto.InputPort(2).Data(:,i,2) rto.InputPort(2).Data(:,i,3)];
			end
			pause(0.005);
			fprintf('.');
		end
	end
	%%	Get essential data
	data_capture{k} = getRawData_mat(Joint);
	%%	Re-orientation, quantization, testing
	[lik found gesture_name] = gesture_test_rt(data_capture);
	lik_all = [lik_all; lik];
	found_all = [found_all; found];
	%%	Informing user
	% fprintf('\n');
	fprintf('It is %s.\n', gesture_name);
	plot(data_capture(:,23), data_capture(:,24), 'r'); hold on;		% RWrst
	plot(data_capture(:,32), data_capture(:,33), 'b'); hold off;	% LWrst
	fprintf('\n');
end;

%%	Stop Simulink
set_param('nid_thesis', 'SimulationCommand', 'stop');
fprintf('Gesture C.\n');
fprintf('Detect as O	= %6.2f percent.\n', 100*sum(found_all(:,1))/k);
fprintf('Detect as A	= %6.2f percent.\n', 100*sum(found_all(:,2))/k);
fprintf('Detect as B	= %6.2f percent.\n', 100*sum(found_all(:,3))/k);
fprintf('Detect as C	= %6.2f percent.\n', 100*sum(found_all(:,4))/k);
fprintf('Detect as D	= %6.2f percent.\n', 100*sum(found_all(:,5))/k);
fprintf('Detect as E	= %6.2f percent.\n', 100*sum(found_all(:,6))/k);
fprintf('False	 	= %6.2f percent.\n', 100*sum(found_all(:,7))/k);
fprintf('Now %s.\n', datestr(now));