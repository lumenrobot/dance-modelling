trshld = 0.5; 
% untuk perhitungan selanjutnya
awal = akhir;

%% Check
while floor(tcapt(awal)+2-trshld) > floor(tcapt(akhir)-trshld) 
	akhir = akhir+1;
end
	
%%%
LWrst1 = []; RWrst1 = [];
for i=awal:akhir
	RWrst1 = [RWrst1; RWrst(i,:)];
	LWrst1 = [LWrst1; LWrst(i,:)];
end
% % plot3(RWrst1(1,3), RWrst1(1,1), RWrst1(1,2), 'or'); hold on;
% % plot3(RWrst1(:,3), RWrst1(:,1), RWrst1(:,2), 'r'); hold on;
% % plot3(LWrst1(1,3), LWrst1(1,1), LWrst1(1,2), 'ob'); hold on;
% % plot3(LWrst1(:,3), LWrst1(:,1), LWrst1(:,2), 'b'); hold off;
% % xlabel('Z'); ylabel('X'); zlabel('Y');

plot(RWrst1(1,1), RWrst1(1,2), 'or'); hold on;
plot(RWrst1(:,1), RWrst1(:,2), 'r'); hold on;
plot(LWrst1(1,1), LWrst1(1,2), 'ob'); hold on;
plot(LWrst1(:,1), LWrst1(:,2), 'b'); hold off;
xlabel('X'); ylabel('Y');