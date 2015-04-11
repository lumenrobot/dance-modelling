%% Bismillahirrahmanirrahim
%% nidsequence
%% mencek Tari Likok Pulo pada level phrase.
%% Ya Allah mohon pertolongan, tidak bisa tanpaMu Ya ALlah...


%%% Load Recording File
	clear; clc;
	CaptFile = 'capt07.xls';
	Ar = xlsread(CaptFile,1);
	id_start = 634;
	trshld_time = 0.5; 
	
%%% Load gesture model and save each parameter model
	load('model_A3'); 
	A_prior = prior; A_emis = emis; A_trans = trans; 
	A_trshold = gestureRecThreshold;
	load('model_B3'); 
	B_prior = prior; B_emis = emis; B_trans = trans; 
	B_trshold = gestureRecThreshold;
	load('model_C5'); 
	C_prior = prior; C_emis = emis; C_trans = trans; 
	C_trshold = gestureRecThreshold;
	load('model_D5'); 
	D_prior = prior; D_emis = emis; D_trans = trans; 
	D_trshold = gestureRecThreshold;
	load('model_E5'); 
	E_prior = prior; E_emis = emis; E_trans = trans; 
	E_trshold = gestureRecThreshold;

%%% Discretize SYmbol
	RShld = [Ar(:,2) Ar(:,3) Ar(:,4)];
	RElbw = [Ar(:,5) Ar(:,6) Ar(:,7)];
	RWrst = [Ar(:,8) Ar(:,9) Ar(:,10)];
	LShld = [Ar(:,11) Ar(:,12) Ar(:,13)];
	LElbw = [Ar(:,14) Ar(:,15) Ar(:,16)];
	LWrst = [Ar(:,17) Ar(:,18) Ar(:,19)];
	%%
	angle_num = [];
	angle_bin = [];
	angle_bin2dec = [];
	sz = size(Ar);
	for i = 1:sz(1)
		[anglenum anglebin] = checkAngle(RShld(i,:),RElbw(i,:),RWrst(i,:),...
								LShld(i,:),LElbw(i,:),LWrst(i,:));
		angle_num = [angle_num; anglenum];
		angle_bin = [angle_bin; anglebin];
		angle_bin2dec = [angle_bin2dec; bin2dec(anglebin)];
	end

%%% Make an array of [time][ArmBinary] for phrase recognition
	multiple_phrase = [Ar(:,1), angle_bin2dec];
	recog_phrase = []; i =1;
	
%%% Check gesture A
	id_akhir = id_start;
	check_phrase;