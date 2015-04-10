% function [found] = gesture_test_rt(data_ordered)
function [lik found gesture_name] = gesture_test_rt(data_ordered)

%%	Quantization
	possible_sym = getPossibleSym(3,3,5,5,5,5,3,3);
	[data_angle, data_quant, data_sym] = getQuantData(data_ordered, possible_sym);

%%	Testing Gesture
	load('model_trained2.mat');
%%	Model O
	trans2 = O_trans2_all;
	emis2 = O_emis2_all;
	prior2 = [1;0;0];
	lik_O = pr_hmm(data_sym,trans2,emis2,prior2);
%%	Model A
	trans2 = A_trans2_all;
	emis2 = A_emis2_all;
	prior2 = [1;0;0];
	lik_A = pr_hmm(data_sym,trans2,emis2,prior2);
%%	Model B
	trans2 = B_trans2_all;
	emis2 = B_emis2_all;
	prior2 = [1;0;0];
	lik_B = pr_hmm(data_sym,trans2,emis2,prior2);
%%	Model C
	trans2 = C_trans2_all;
	emis2 = C_emis2_all;
	prior2 = [1;0;0;0;0];
	lik_C = pr_hmm(data_sym,trans2,emis2,prior2); 
%%	Model D
	trans2 = D_trans2_all;
	emis2 = D_emis2_all;
	prior2 = [1;0;0;0;0];
	lik_D = pr_hmm(data_sym,trans2,emis2,prior2);
%%	Model E
	trans2 = E_trans2_all;
	emis2 = E_emis2_all;
	prior2 = [1;0;0;0;0];
	lik_E = pr_hmm(data_sym,trans2,emis2,prior2); 

%%	Check
	lik = [lik_O lik_A lik_B lik_C lik_D lik_E];
	if (max(lik) == lik_O) && (max(lik)> -219.2924)
		found = [1 0 0 0 0 0 0];
		gesture_name = 'Gesture O';
	elseif (max(lik) == lik_A) && (max(lik)> -238.3310)
		found = [0 1 0 0 0 0 0];
		gesture_name = 'Gesture A';
	elseif (max(lik) == lik_B) && (max(lik)> -236.1416)
		found = [0 0 1 0 0 0 0];
		gesture_name = 'Gesture B';
	elseif (max(lik) == lik_C) && (max(lik)> -386.7459) 
		found = [0 0 0 1 0 0 0];
		gesture_name = 'Gesture C';
	elseif (max(lik) == lik_D) && (max(lik)> -374.8780)
		found = [0 0 0 0 1 0 0];
		gesture_name = 'Gesture D';
	elseif (max(lik) == lik_E) && (max(lik)> -480.9375)
		found = [0 0 0 0 0 1 0];
		gesture_name = 'Gesture E';
	else
		found = [0 0 0 0 0 0 1];
		gesture_name = 'Gesture X';
	end;