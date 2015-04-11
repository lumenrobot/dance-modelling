
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


% ################################################################################
% ################################################################################
% % CHECK and PLOT DATA untuk CLAP SENSOR included
% close; clear; clc;
% CaptFile = 'capt04imu.xls';
% Ar = xlsread(CaptFile,1);
% RWrst = [Ar(:,21) Ar(:,22) Ar(:,23)];
% LWrst = [Ar(:,24) Ar(:,25) Ar(:,26)];

% % mencari cara menemukan start point and end point.
% awal = 1; akhir = 1; cekn = 1; ceks = 1;

%% check tangan menepuk atau tidak
% untuk perhitungan selanjutnya
% awal = akhir + 1;

%% Check
% cekn = awal;
% while Ar(cekn,20) == 0
	% cekn = cekn+1;
% end;
% ceks = cekn+1;
% while Ar(ceks,20) == 1
	% ceks = ceks+1;
% end;
% akhir = ceks-1;

% ##########################################################
% ##########################################################
% CHECK and PLOT DATA untuk time limited
% clear; clc;
% CaptFile = 'capt07.xls';
% Ar = xlsread(CaptFile,1);
% RWrst = [Ar(:,21) Ar(:,22) Ar(:,23)];
% LWrst = [Ar(:,24) Ar(:,25) Ar(:,26)];

% % mencari cara menemukan start point and end point.
% % di setiap detik
% % awal = 1; akhir = 1; cekn = 1; ceks = 1;

% % untuk perhitungan selanjutnya
% awal = akhir + 1;

% %% Check
% while (Ar(awal,1) + 2) > Ar(akhir,1)
	% akhir = akhir+1;
% end
	

% %
% LWrst1 = []; RWrst1 = [];
% for i=awal:akhir
	% RWrst1 = [RWrst1; RWrst(i,:)];
	% LWrst1 = [LWrst1; LWrst(i,:)];
% end
% plot3(RWrst1(1,3), RWrst1(1,1), RWrst1(1,2), 'or'); hold on;
% plot3(RWrst1(:,3), RWrst1(:,1), RWrst1(:,2), 'r'); hold on;
% plot3(LWrst1(1,3), LWrst1(1,1), LWrst1(1,2), 'ob'); hold on;
% plot3(LWrst1(:,3), LWrst1(:,1), LWrst1(:,2), 'b'); hold off;
% xlabel('Z'); ylabel('X'); zlabel('Y');

% ##########################################################
% ##########################################################
% INSERT FEATURES
% clear; clc;
% CaptFile = 'capt02imu.xls';
% Ar = xlsread(CaptFile,1);
% for i=2:5000
	% % distance of shoulder, ok
	% dist = sqrt(((Ar(i,2)-Ar(i,11))^2) + ((Ar(i,3)-Ar(i,12))^2) +...
		% ((Ar(i,4)-Ar(i,13))^2));
	% % center of shoulder		
	% center = [((Ar(i,2)+Ar(i,11))/2) ((Ar(i,3)+Ar(i,12))/2) ((Ar(i,4)+Ar(i,13))/2)];
	% % delta time
	% dtime = Ar(i,1)-Ar(i-1,1);
	% % RWrist and LWrist, ok
	% RWrist = [Ar(i,8) Ar(i,9) Ar(i,10)];
	% LWrist = [Ar(i,17) Ar(i,18) Ar(i,19)];
	% % RWrist Normalized, ok
	% Ar(i,21) = 100*(RWrist(1)-center(1))/dist;
	% Ar(i,22) = 100*(RWrist(2)-center(2))/dist;
	% Ar(i,23) = 100*(RWrist(3)-center(3))/dist;
	% % LWrist Normalized, ok
	% Ar(i,24) = 100*(LWrist(1)-center(1))/dist;
	% Ar(i,25) = 100*(LWrist(2)-center(2))/dist;
	% Ar(i,26) = 100*(LWrist(3)-center(3))/dist;
	% % Selisih RWrist dan LWrist
	% Ar(i,27) = RWrist(1)-LWrist(1);
	% Ar(i,28) = RWrist(2)-LWrist(2);
	% Ar(i,29) = RWrist(3)-LWrist(3);
	% % Velocity of RWrist
	% Ar(i,30) = (Ar(i,8)-Ar(i-1,8))/dtime;
	% Ar(i,31) = (Ar(i,9)-Ar(i-1,9))/dtime;
	% Ar(i,32) = (Ar(i,10)-Ar(i-1,10))/dtime;
	% % Velocity of LWrist
	% Ar(i,33) = (Ar(i,17)-Ar(i-1,17))/dtime;
	% Ar(i,34) = (Ar(i,18)-Ar(i-1,18))/dtime;
	% Ar(i,35) = (Ar(i,19)-Ar(i-1,19))/dtime;
% end
% xlswrite (CaptFile, Ar, 1);

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
