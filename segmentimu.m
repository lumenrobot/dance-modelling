% % CHECK and PLOT DATA untuk CLAP SENSOR included
% close; clear; clc;
% CaptFile = 'capt04imu.xls';
% Ar = xlsread(CaptFile,1);
% RWrst = [Ar(:,21) Ar(:,22) Ar(:,23)];
% LWrst = [Ar(:,24) Ar(:,25) Ar(:,26)];

% % mencari cara menemukan start point and end point.
% awal = 1; akhir = 1; cekn = 1; ceks = 1;

% check tangan menepuk atau tidak
% untuk perhitungan selanjutnya
awal = akhir + 1;

% Check
cekn = awal;
while tcapt(cekn,2) == 0
	cekn = cekn+1;
end;
ceks = cekn+1;
while tcapt(ceks,2) == 1
	ceks = ceks+1;
end;
akhir = ceks-1;

LWrst1 = []; RWrst1 = [];
for i=awal:akhir
	RWrst1 = [RWrst1; RWrst(i,:)];
	LWrst1 = [LWrst1; LWrst(i,:)];
end
% plot3(RWrst1(1,3), RWrst1(1,1), RWrst1(1,2), 'or'); hold on;
% plot3(RWrst1(:,3), RWrst1(:,1), RWrst1(:,2), 'r'); hold on;
% plot3(LWrst1(1,3), LWrst1(1,1), LWrst1(1,2), 'ob'); hold on;
% plot3(LWrst1(:,3), LWrst1(:,1), LWrst1(:,2), 'b'); hold off;
% xlabel('Z'); ylabel('X'); zlabel('Y');

plot(RWrst1(1,1), RWrst1(1,2), 'or'); hold on;
plot(RWrst1(:,1), RWrst1(:,2), 'r'); hold on;
plot(LWrst1(1,1), LWrst1(1,2), 'ob'); hold on;
plot(LWrst1(:,1), LWrst1(:,2), 'b'); hold off;
xlabel('X'); ylabel('Y');