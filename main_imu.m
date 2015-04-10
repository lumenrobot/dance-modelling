% -------------------------------------
% Bismillahirrahmanirrrahiim
% Capture_Imu
% -------------------------------------
clear all; clc;
CaptImuFile = 'D:\S2 - Tesis\Capture\capture.txt';

% ----- Start Realterm as a server
hrealterm = actxserver('realterm.realtermintf'); 

% ----- List all properties and method of realterm
% fprintf(1,'\nProperties of Realterm\n\n');
% get(hrealterm);		% Properties
% invoke(hrealterm);	% Method

% ----- Set value and capture
hrealterm.baud		=	57600;
hrealterm.Port 		= 	'5'; 	% set port 5
hrealterm.PortOpen	=	1;		% open the comm port
hrealterm.CaptureFile	= CaptImuFile;
invoke(hrealterm, 'timestamp', '3'); % Matlab stamp
invoke(hrealterm,'startcapture'); %start capture

% ----- Capture until user type return
fprintf(1,'\n\nType RETURN to close realterm\n')
keyboard
invoke(hrealterm,'stopcapture');
hrealterm.PortOpen	=	0;		% close the comm port
invoke(hrealterm,'close'); 
delete(hrealterm);

% ----- Plotting