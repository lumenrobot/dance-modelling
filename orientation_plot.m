% 	orientation_plot.m
% 	Update 21 Juli 2014 --> Belum berhasil

% 	Memplot orientasi
% 	1	234		567		8910	111213	141516	171819	202122	232425	262728	293031	323334
%	t	Spine	CHip	RHip	LHip	CShld	RShld	RElbw	RWrst	LShld	LElbw	LWrst

%%	Kinect reference frame
	kinect = getRawData_mat(Front1);
	CShld = kinect(:,14:16);
	RWrst = kinect(:,23:25);
	LWrst = kinect(:,32:34);
	
%% 	Torso reference frame
	% Torso = [CShld; RShld; LShld; Spine; CHip; RHip; LHip];
	RWrst_torso = [];
	LWrst_torso = [];
	for i = 2:length(kinect)
		Torso = [kinect(i,14:16); kinect(i,17:19); kinect(i,26:28); kinect(i,2:4); ...
				kinect(i,5:7); kinect(i,8:10); kinect(i,11:13)];
		
		R_0 = [1 0 0; 0 1 0; 0 0 1];
		R_tegak = [-1 0 0; 0 -1 0; 0 0 -1];
		R_torso = -pca(Torso);
	
		RWrst_torso = [RWrst_torso; ((R_torso)*(RWrst(i,:))')'];
		LWrst_torso = [LWrst_torso; ((R_torso)*(LWrst(i,:))')'];
	end;	

%%	Plot ZXY
	% subplot(1,2,1);
	plot3(RWrst(:,3), RWrst(:,1), RWrst(:,2), 'r'); hold on;
	plot3(LWrst(:,3), LWrst(:,1), LWrst(:,2), 'b'); hold on;
	quiver3(0, 0, 0, R_0(1,3), R_0(1,1), R_0(1,2), 'r'); hold on; 
	quiver3(0, 0, 0, R_0(2,3), R_0(2,1), R_0(2,2), 'g'); hold on; 
	quiver3(0, 0, 0, R_0(3,3), R_0(3,1), R_0(3,2), 'b');
	xlabel('Z'); ylabel('X'); zlabel('Y');

	% subplot(1,2,2);
	plot3(RWrst_torso(:,3), RWrst_torso(:,1), RWrst_torso(:,2), 'm'); hold on;
	plot3(LWrst_torso(:,3), LWrst_torso(:,1), LWrst_torso(:,2), 'c'); hold on;
	% quiver3(CShld(3), CShld(1), CShld(2), R_torso(1,3), R_torso(1,1), R_torso(1,2), 'r');	hold on; 
	% quiver3(CShld(3), CShld(1), CShld(2), R_torso(2,3), R_torso(2,1), R_torso(2,2), 'g');	hold on; 
	% quiver3(CShld(3), CShld(1), CShld(2), R_torso(3,3), R_torso(3,1), R_torso(3,2), 'b');	hold on; 
	xlabel('Z'); ylabel('X'); zlabel('Y');
	
	

