% ################################################################################
% ################################################################################
%%% coba fungsi rekursif

% a = a+1;
% if (a < 100)
	% fprintf('rekursif\n');
	% cobarekursif;
% else
	% fprintf ('%f', a);
% end;

num5 = 0;
num4 = 0;
num3 = 0;
num2 = 0;
num1 = 0;
num0 = 0;
for i = 1:477
	if (recog_tab(i,1)==5) num5 = num5 + 1;
	elseif (recog_tab(i,1)==4) num4 = num4 + 1;
	elseif (recog_tab(i,1)==3) num3 = num3 + 1;
	elseif (recog_tab(i,1)==2) num2 = num2 + 1;
	elseif (recog_tab(i,1)==1) num1 = num1 + 1;
	else num0 = num0 + 1;
	end;
end;

% ################################################################################
% ################################################################################
% CaptImuFile = 'capture_2_imu.txt';
% for i=1:20
	% Joint{i} = xlsread(CaptJntFile,i);
% end

% imu = load(CaptImuFile);
% imu(:,1)=imu(:,1)-735652;
% trueimu = [imu(:,1) imu(:,2) imu(:,3) imu(:,4) imu(:,13)];
% Joint{21} = trueimu;

% for i=1:21
	% xlswrite (CaptJntFile, Joint{i}, i);
% end


% ##########################################################
% ##########################################################
%%% Mengingat kembali manipulasi data

% x = [2 4 6];
% y = [2; 4; 6];
% z = [5 6 7; 8 9 0];
% Sdt = [30:35]; 			% Sdt = 30 31 32 34 35
% Sdu = [30:10:70];		% Sdu = 30 40 50 60 70
% Sdv = linspace(30,90,5)	% Sdv = 30 45 60 75 90

% matu = ones(3,4); 	% Semua elemen bernilai satu
% matv = zeros(3,4);	% Semua elemen bernilai nol
% matw = eye(3,4);	% Matriks identitas
% matx = rand(3,4);	% Elemen random

% Maty = z'; 	% Transpos
% u = [x;z]; 		% Menempelkan data pada baris
% v = [u y];		% Menempelkan data pada kolom

% a = (u>7) .*a; % Mengambil elemen yang lebih dari 7
