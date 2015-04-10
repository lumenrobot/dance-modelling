%% Main GUI 31 Juli 2014

function main_gui()

% Get files in the specified directory
dirname = 'H:\!_Admin_Akademik\2014_Tesis\project_Matlab\!!Capture\Ass_1';
fnames = dir(dirname);

% Get supported image formats from your pc
imforms = imformats;
imexts = [imforms.ext]';

% Figure out which files in the directory are image files
imgInd = zeros(length(fnames),1);
i = 1;
for k = 1:length(fnames)
    [pathstr,name,ext] = fileparts(fnames(k).name);
    if any(strcmpi(ext(2:end),imexts)) == 1;
        imgInd(i) = k;
        i = i+1;
    end
end
imgInd = imgInd(imgInd~=0);

if isempty(imgInd)
    errordlg('No images found in folder. Try again');
    return
end

% Setting Up GUI
bgcolor = [247 227 213]/256;
fig = figure(...
	'name'			, 'Thousand Hands Revolution v.2', ...
	'tag'			, 'mainFigure', ...
	'numbertitle'	, 'off', ...
	'resize'		, 'off', ...
	'interruptible'	, 'on', ...
	'menubar'		, 'none', ...
	'toolbar'		, 'none', ...
	'units'			, 'normalized', ...
	'color'			, bgcolor, ...
	'defaultaxesunits'              , 'normalized', ...
	'defaultaxesbox'				, 'off', ...
	'defaultaxesxtick'              , [], ...
	'defaultaxesytick'              , [], ...
	'defaultuipanelunits'			, 'pixels', ...
	'defaultuipanelbordertype'		, 'etchedin', ...
	'defaultuipanelfontname'		, 'Georgia', ...
	'defaultuipanelfontweight'		, 'bold', ...
	'defaultuipanelfontunits'		, 'pixels', ...
	'defaultuipanelfontsize'		, 15, ...	
	'defaultuipaneltitleposition'	, 'centertop', ...
	'defaultuipanelbackgroundcolor'	, bgcolor, ...	
	'defaultuicontrolunits'         , 'normalized', ...
	'defaultuicontrolbackgroundcolor', bgcolor, ...	
	'defaultuicontrolfontunits'     , 'pixels', ...
	'defaultuicontrolfontsize'      , 12, ...
	'defaultuicontrolfontname'      , 'Georgia', ...
	'defaultuicontrolinterruptible' , 'off');
	
upax1 = uipanel('tag'	, 'framePrevPose', ...
	'title'				, 'Pose Sekarang', ...
	'parent'			, fig);
	
upax2 = uipanel('tag'	, 'frameNextPose', ...
	'title'				, 'Pose Selanjutnya', ...
	'parent'			, fig);	
	
upax3 = uipanel('tag'	, 'frameUserPose', ...
	'title'				, 'Pose Anda', ...
	'parent'			, fig);		
	
up1 = uipanel('tag'		, 'frameType', ...
	'title'				, 'Tipe Pengujian', ...
	'parent'			, fig);

up2 = uipanel('tag'		, 'frameResult', ...
	'parent'			, fig);
	
up3 = uipanel('tag'		, 'frameStart', ...
	'title'				, 'Mulai Pengujian', ...
	'parent'			, fig);
	
ax1 = axes('tag'		, 'axesPrevPose', ...
	'parent'			, upax1, ...
	'handlevisibility'	, 'callback');
	
ax2 = axes('tag'		, 'axesNextPose', ...
	'parent'			, upax2, ...
	'handlevisibility'	, 'callback');
	
ax3 = axes('tag'		, 'axesUserPose', ...
	'parent'			, upax3, ...
	'handlevisibility'	, 'callback');	
	
lb1 = uicontrol('tag'	, 'chooseTimeType', ...
	'style'				, 'listbox', ...
	'parent'			, up1, ...
	'string'			, {'Periode Tetap';'Periode Semakin Cepat'});
			
lb2 = uicontrol('tag'	, 'chooseTestType', ...
	'style'				, 'listbox', ...
	'parent'			, up1, ...
	'string'			, {'Uji Masing-masing Gesture Berurut';'Uji Gesture Secara Acak';'Uji Frase Assalamualaikum'});

tx0 = uicontrol('tag'	, 'instruction', ...
	'style'				, 'text', ...
	'string'			, 'Pilihlah tipe pengujian.', ...
	'parent'			, up2, ...
	'fontsize'			, 20);
	
tx1 = uicontrol('tag'	, 'timeWarning', ...
	'style'				, 'text', ...
	'parent'			, up2, ...
	'fontsize'			, 20);	
	
tx2 = uicontrol('tag'	, 'detectedGesture', ...
	'style'				, 'text', ...
	'parent'			, up2, ...
	'fontsize'			, 20);

tx3 = uicontrol('tag'	, 'trueOrFalse', ...
	'style'				, 'text', ...
	'parent'			, up2, ...
	'fontsize'			, 30, ...
	'fontweight'		, 'bold');	

pb1 = uicontrol('tag'	, 'startButton', ...
	'style'				, 'toggle', ...
	'parent'			, up3, ...
	'string'			, 'Mulai', ...
	'callback'			, @start);	


%% 	--------------------------------------
%%	Set Position


set(0,'units','pixels');
ssize = get(0,'screensize');
isize = [296 384];
obj	= guihandles(fig);
set (obj.mainFigure		, 'position', [0.075 0.075 0.85 0.85]);
set (obj.frameNextPose	, 'position', [0.425*ssize(3)-1.5*isize(1) 0.55*ssize(4)-0.5*isize(2) isize(1) isize(2)+15]);
set (obj.axesNextPose	, 'position', [0 0 1 1]);
set (obj.framePrevPose	, 'position', [0.425*ssize(3)-0.5*isize(1) 0.55*ssize(4)-0.5*isize(2) isize(1) isize(2)+15]);
set (obj.axesPrevPose	, 'position', [0 0 1 1]);
set (obj.frameUserPose	, 'position', [0.425*ssize(3)+0.5*isize(1) 0.55*ssize(4)-0.5*isize(2) isize(1) isize(2)+15]);
set (obj.axesUserPose	, 'position', [0 0 1 1]);
set (obj.frameType		, 'position', [0.425*ssize(3)-1.5*isize(1) 0.3*ssize(4)-0.5*isize(2) isize(1) 160]);
set (obj.frameResult	, 'position', [0.425*ssize(3)-0.5*isize(1) 0.3*ssize(4)-0.5*isize(2) isize(1) 190]);
set (obj.frameStart		, 'position', [0.425*ssize(3)+0.5*isize(1) 0.3*ssize(4)-0.5*isize(2) isize(1) 160]);
set (obj.chooseTimeType	, 'position', [0.1 0.55 0.8 0.35]);
set (obj.chooseTestType	, 'position', [0.1 0.1 0.8 0.35]);
set (obj.instruction	, 'position', [0.1 0.6 0.8 0.2]);
set (obj.timeWarning	, 'position', [0.1 0.35 0.8 0.2]);
set (obj.detectedGesture, 'position', [0.1 0.1 0.4 0.2]);
set (obj.trueOrFalse	, 'position', [0.5 0.1 0.4 0.2]);
set (obj.startButton	, 'position', [0.2 0.3 0.6 0.4]);

%% 	--------------------------------------
%%	Callbacks
function start(fig, evnt)
	obj		= guihandles(gcf);
	vl = get (obj.startButton, 'value'); 
	if vl == 1
		set (obj.startButton, 'string', 'Berhenti');
		load_system('nid_thesis2');		% Invisibly load a simulink model
		% open_system('nid_thesis2');	% Open a simulink system window
		set_param('nid_thesis2', 'SimulationCommand', 'start');	% Start simulink simulation
		set_param('nid_thesis2', 'StartFcn', 'localAddEventListener');
		rto = get_param('nid_thesis2/NID Skeleton', 'RuntimeObject');
		set (obj.instruction	, 'string', 'Kinect device are ready.'); pause(1);
		set (obj.instruction	, 'string', 'Loading the Simulink.'); pause(1);
		set (obj.instruction	, 'string', 'Starting the Simulink.'); pause(1);
		set (obj.instruction	, 'string', 'Starting the Simulink..'); pause(1);
		set (obj.instruction	, 'string', 'Starting the Simulink...'); pause(1);
		set (obj.instruction	, 'string', 'Starting the Simulink....'); pause(1);
		timeType = get(obj.chooseTimeType, 'value'); 
		testType = get(obj.chooseTestType, 'value'); 
		
		if testType == 2		% Acak
				t = 30;
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1)
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
		
		elseif testType == 1	% Berurutan
			if timeType == 1
				t = 30;
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
			elseif timeType == 2
				t = 30;
				gesture_check(obj, rto, 'Gesture O', t, 1);
				gesture_check(obj, rto, 'Gesture O', t-2, 1);
				gesture_check(obj, rto, 'Gesture O', t-4, 1);
				gesture_check(obj, rto, 'Gesture O', t-6, 1);
				gesture_check(obj, rto, 'Gesture O', t-8, 1);
				gesture_check(obj, rto, 'Gesture A', t, 1);
				gesture_check(obj, rto, 'Gesture A', t-2, 1);
				gesture_check(obj, rto, 'Gesture A', t-4, 1);
				gesture_check(obj, rto, 'Gesture A', t-6, 1);
				gesture_check(obj, rto, 'Gesture A', t-8, 1);
				gesture_check(obj, rto, 'Gesture B', t, 1);
				gesture_check(obj, rto, 'Gesture B', t-2, 1);
				gesture_check(obj, rto, 'Gesture B', t-4, 1);
				gesture_check(obj, rto, 'Gesture B', t-6, 1);
				gesture_check(obj, rto, 'Gesture B', t-8, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t-4, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t-8, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t-12, 1);
				gesture_check(obj, rto, 'Gesture C', 2*t-14, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t-4, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t-8, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t-12, 1);
				gesture_check(obj, rto, 'Gesture D', 2*t-16, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t-4, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t-8, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t-12, 1);
				gesture_check(obj, rto, 'Gesture E', 2*t-16, 1);
			end
		elseif testType == 3	% Pengujian Frase
			if timeType == 1
				set (obj.instruction	, 'string', 'Frase Assalamualaikum'); pause (1);
				set (obj.timeWarning	, 'string', '3..'); pause (1);
				set (obj.timeWarning	, 'string', '3.. 2..'); pause (1);
				set (obj.timeWarning	, 'string', '3.. 2.. 1..'); pause (1);
				t = 30;
				gesture_check(obj, rto, 'Gesture O', t, 0);
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
				gesture_check(obj, rto, 'Gesture E', 2*t, 0); %
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', 2*t, 0);
				gesture_check(obj, rto, 'Gesture D', 2*t, 0);
			elseif timeType == 2
				t = 30;
				gesture_check(obj, rto, 'Gesture O', t, 0);
				gesture_check(obj, rto, 'Gesture A', t, 0);
				gesture_check(obj, rto, 'Gesture B', t, 0);
				gesture_check(obj, rto, 'Gesture C', t, 0);
				gesture_check(obj, rto, 'Gesture D', t, 0);
				gesture_check(obj, rto, 'Gesture E', t, 0); %
				gesture_check(obj, rto, 'Gesture A', t-1, 0);
				gesture_check(obj, rto, 'Gesture B', t-1, 0);
				gesture_check(obj, rto, 'Gesture C', t-2, 0);
				gesture_check(obj, rto, 'Gesture D', t-2, 0);
				gesture_check(obj, rto, 'Gesture E', t-2, 0); %
				gesture_check(obj, rto, 'Gesture A', t-2, 0);
				gesture_check(obj, rto, 'Gesture B', t-2, 0);
				gesture_check(obj, rto, 'Gesture C', t-4, 0);
				gesture_check(obj, rto, 'Gesture D', t-4, 0);
				gesture_check(obj, rto, 'Gesture E', t-4, 0); %
				gesture_check(obj, rto, 'Gesture A', t-3, 0);
				gesture_check(obj, rto, 'Gesture B', t-3, 0);
				gesture_check(obj, rto, 'Gesture C', t-6, 0);
				gesture_check(obj, rto, 'Gesture D', t-6, 0);
				gesture_check(obj, rto, 'Gesture E', t-6, 0); %
				gesture_check(obj, rto, 'Gesture A', t-4, 0);
				gesture_check(obj, rto, 'Gesture B', t-4, 0);
				gesture_check(obj, rto, 'Gesture C', t-8, 0);
				gesture_check(obj, rto, 'Gesture D', t-8, 0);
				gesture_check(obj, rto, 'Gesture E', t-8, 0); %
				gesture_check(obj, rto, 'Gesture A', t-5, 0);
				gesture_check(obj, rto, 'Gesture B', t-5, 0);
				gesture_check(obj, rto, 'Gesture C', t-10, 0);
				gesture_check(obj, rto, 'Gesture D', t-10, 0);
				gesture_check(obj, rto, 'Gesture E', t-10, 0); %
				gesture_check(obj, rto, 'Gesture A', t-6, 0);
				gesture_check(obj, rto, 'Gesture B', t-6, 0);
				gesture_check(obj, rto, 'Gesture C', t-12, 0);
				gesture_check(obj, rto, 'Gesture D', t-12, 0);
				gesture_check(obj, rto, 'Gesture E', t-12, 0); %
				gesture_check(obj, rto, 'Gesture A', t-8, 0);
				gesture_check(obj, rto, 'Gesture B', t-8, 0);
				gesture_check(obj, rto, 'Gesture C', t-16, 0);
				gesture_check(obj, rto, 'Gesture D', t-16, 0);
			end;
		end;
		
		
	else
		set (obj.startButton	, 'string', 'Mulai');
		set (obj.instruction	, 'string', 'Pengujian dihentikan.');
		set_param('nid_thesis2'	, 'SimulationCommand', 'stop');
	end;
	

	
	

function gesture_check (obj, rto, gesture_name, period, isDelay)
	dirname = 'D:\S2_Tesis\project_Matlab\!!Capture\Ass_1';
	fnames = dir(dirname);
	set (obj.instruction	, 'string', gesture_name);
	if gesture_name == 'Gesture O'
		prevPose = imread([dirname,filesep,fnames(3).name]);
		nextPose = imread([dirname,filesep,fnames(4).name]);
	elseif gesture_name == 'Gesture A'
		prevPose = imread([dirname,filesep,fnames(4).name]);
		nextPose = imread([dirname,filesep,fnames(5).name]);
	elseif gesture_name == 'Gesture B'
		prevPose = imread([dirname,filesep,fnames(5).name]);
		nextPose = imread([dirname,filesep,fnames(6).name]);
	elseif gesture_name == 'Gesture C'
		prevPose = imread([dirname,filesep,fnames(6).name]);
		nextPose = imread([dirname,filesep,fnames(7).name]);
	elseif gesture_name == 'Gesture D'
		prevPose = imread([dirname,filesep,fnames(8).name]);
		nextPose = imread([dirname,filesep,fnames(9).name]);
	elseif gesture_name == 'Gesture E'
		prevPose = imread([dirname,filesep,fnames(10).name]);
		nextPose = imread([dirname,filesep,fnames(11).name]);
	end;
	image(prevPose, 'parent', obj.axesPrevPose);
	image(nextPose, 'parent', obj.axesNextPose);
	
	if isDelay == 1
		set (obj.timeWarning	, 'string', '3..'); pause (1);
		set (obj.timeWarning	, 'string', '3.. 2..'); pause (1);
		set (obj.timeWarning	, 'string', '3.. 2.. 1..'); pause (1);
	end;
	Joint = {[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[];[]};
	for (j = 1:period)
		if (rto.OutputPort(1).Data == 1) %% Check Tracking Status
			for i = 1:20
				Joint{i} = [Joint{i}; datevec(now) rto.OutputPort(2).Data(:,i,1) rto.OutputPort(2).Data(:,i,2) rto.OutputPort(2).Data(:,i,3)];
			end
			pause(0.004);
			set (obj.timeWarning	, 'string', num2str(j));
			if (j == fix(period/2))
				if gesture_name == 'Gesture C'
					prevPose = imread([dirname,filesep,fnames(7).name]);
					nextPose = imread([dirname,filesep,fnames(8).name]);
				elseif gesture_name == 'Gesture D'
					prevPose = imread([dirname,filesep,fnames(9).name]);
					nextPose = imread([dirname,filesep,fnames(10).name]);
				elseif gesture_name == 'Gesture E'
					prevPose = imread([dirname,filesep,fnames(11).name]);
					nextPose = imread([dirname,filesep,fnames(12).name]);
				end
				image(prevPose, 'parent', obj.axesPrevPose);
				image(nextPose, 'parent', obj.axesNextPose);
			end
		end
	end
	data_capture = getRawData_mat(Joint);
	[lik found gesture_detected] = gesture_test_rt(data_capture);
	set (obj.detectedGesture	, 'string', gesture_detected);
	if gesture_detected == gesture_name
		set (obj.trueOrFalse	, 'string', 'Benar');
	else
		set (obj.trueOrFalse	, 'string', 'Salah');
	end

	
function eventhandle = localAddEventListener
eventhandle = add_exec_event_listener('nid_thesis2/NID Skeleton', ...
                'PostOutputs', @localEventListener);

% The function to be called when event is registered.           
function localEventListener(block, eventdata)
	obj	= guihandles(gcf);
	rto = get_param('nid_thesis2/NID Skeleton', 'RuntimeObject');
	% fprintf('%d\n', rto.OutputPort(2).Data(1,1,1));
	set(obj.axesUserPose, 'XLim', [-1 1], 'YLim', [-1.5 1.5], 'ZLim', [-1.0 2.0]); % Set X/Y/Z limits in meters
	set(obj.axesUserPose, 'Color', [0 0 0], 'XGrid', 'on', 'YGrid', 'on'); % Draw X/Y grid
	cla;
	id =  [12 11 10 9 3 4 3 5 6 7 8 7 6 5 3 9 2 5 2 1 17 18 19 20 19 18 17 1 13 14 15 16]; % Each joint ID is described in help of NID Skeleton block
	jnts = zeros(1, length(id), 3);
	for i = 1:length(id)
		for j = 1:3
			jnts(1,i,j) = rto.OutputPort(2).Data(1,id(i),j);
		end
	end
	line(-jnts(:,:,1), jnts(:,:,2), jnts(:,:,3), 'Color', 'w', 'LineStyle', '-', 'LineWidth', 2, 'Marker', 'none');
	% Skeleton joints at the right side of the body
	id = [9 10 11 12 17 18 19 20]; % Each joint ID is described in help of NID Skeleton block
	jnts = zeros(1, length(id), 3);
	for i = 1:length(id)
		for j = 1:3
			jnts(1,i,j) = rto.OutputPort(2).Data(1,id(i),j);
		end
	end
	line(-jnts(:,:,1), jnts(:,:,2), jnts(:,:,3), 'LineStyle', 'none', 'Marker', 'o', 'MarkerFaceColor', 'g', 'MarkerEdgeColor', 'g', 'MarkerSize', 4);
	% Skeleton joints at the center of the body
	id = [1 2 3 4]; % Each joint ID is described in help of NID Skeleton block
	jnts = zeros(1, length(id), 3);
	for i = 1:length(id)
		for j = 1:3
			jnts(1,i,j) = rto.OutputPort(2).Data(1,id(i),j);
		end
	end
	line(-jnts(:,:,1), jnts(:,:,2), jnts(:,:,3), 'LineStyle', 'none', 'Marker', 'o', 'MarkerFaceColor', 'r', 'MarkerEdgeColor', 'r', 'MarkerSize', 4);
	% Skeleton joints at the left side of the body
	id = [5 6 7 8 13 14 15 16]; % Each joint ID is described in help of NID Skeleton block
	jnts = zeros(1, length(id), 3);
	for i = 1:length(id)
		for j = 1:3
			jnts(1,i,j) = rto.OutputPort(2).Data(1,id(i),j);
		end
	end
	line(-jnts(:,:,1), jnts(:,:,2), jnts(:,:,3), 'LineStyle', 'none', 'Marker', 'o', 'MarkerFaceColor', 'c', 'MarkerEdgeColor', 'c',  'MarkerSize', 4);
%	
