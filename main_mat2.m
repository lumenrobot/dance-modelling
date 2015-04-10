%%	Initiation
load_system('nid_thesis');		% Invisibly load a simulink model
% open_system('nid_thesis');	% Open a simulink system window
set_param('nid_thesis', 'SimulationCommand', 'start');	% Start simulink simulation
rto = get_param('nid_thesis/NID Skeleton', 'RuntimeObject');
fprintf('Kinect device are ready.\n');
fprintf('Loading the Simulink Model.\n');
fprintf('Starting the Simulink Model.\n');
gesturename = input('Insert gesture name : ', 's');
period = input('Insert capturing period : ');
times = input('Insert capturing times : '); pause(4);
data_capture = {};
lik_all = []; found_all = [];

for k = 1:times
	%%	-------------------------------------------------------------------------------
	%%	Informing user for capturing the data
	fprintf('\n%d) Please Do the %s.   ', k, gesturename);
	fprintf('3..'); pause(1);  fprintf('2..'); pause(1); fprintf('1..\n'); pause(1);
	Joint = {[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[]};
	for (j = 1:period)
		if (rto.OutputPort(1).Data == 1) %% Check Tracking Status
			for i = 1:20
				Joint{i} = [Joint{i}; datevec(now) rto.OutputPort(2).Data(:,i,1) rto.OutputPort(2).Data(:,i,2) rto.OutputPort(2).Data(:,i,3)];
			end
			pause(0.005);
			fprintf('.');
		end
	end
	%%	Get essential data
	data_capture{k} = getRawData_mat(Joint);
	%%	Re-orientation, quantization, testing
	[lik found gesture_name] = gesture_test_rt(data_capture{k});
	lik_all = [lik_all; lik];
	found_all = [found_all; found];
	%%	Informing user
	fprintf('\n');
	fprintf('It is %s.\n', gesture_name);
end;

%%	Stop Simulink
set_param('nid_thesis', 'SimulationCommand', 'stop');

% %%	Checking Trajectory
% for i = 1:length(data_capture)
	% data = data_capture{i};
	% plot(data(:,23), data(:,24), 'r'); hold on;		% RWrst
	% plot(data(1,23), data(1,24), 'or'); hold on;		% RWrst
	% plot(data(:,32), data(:,33), 'b'); hold on;	% LWrst
	% plot(data(1,32), data(1,33), 'ob'); hold off;	% LWrst
	% pause(1);
% end

%%	Report Testing Results
fprintf('Detect as O	= %d	= %6.2f percent.\n', sum(found_all(:,1)), 100*sum(found_all(:,1))/k);
fprintf('Detect as A	= %d	=  %6.2f percent.\n', sum(found_all(:,2)), 100*sum(found_all(:,2))/k);
fprintf('Detect as B	= %d	=  %6.2f percent.\n', sum(found_all(:,3)), 100*sum(found_all(:,3))/k);
fprintf('Detect as C	= %d	=  %6.2f percent.\n', sum(found_all(:,4)), 100*sum(found_all(:,4))/k);
fprintf('Detect as D	= %d	=  %6.2f percent.\n', sum(found_all(:,5)), 100*sum(found_all(:,5))/k);
fprintf('Detect as E	= %d	=  %6.2f percent.\n', sum(found_all(:,6)), 100*sum(found_all(:,6))/k);
fprintf('False	 	= %d	=  %6.2f percent.\n', sum(found_all(:,7)), 100*sum(found_all(:,7))/k);
fprintf('Now %s.\n', datestr(now));