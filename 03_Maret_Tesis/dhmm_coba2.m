%% Mencoba menggenerate HMM.
%% Bismillahirrahmanirrahim!

%% Load Recording File
clear; clc;
load('gestC_1sec.mat');
gesture_name = 'C';
gesture_mat = C;		% load record file
% Indices	Name				Number of Symbol			
% Obv{2,2} 	Block - dec2bin		(2^34)
% Obv{3,2}	Block - binary		bin2dec(2^34)
% Obv{4,2}	Block - num		
% Obv{5,2}	Angle - dec2bin		(2^20)
% Obv{6,2}	Angle - binary		bin2dec(2^20)
% Obv{7,2}	Angle - num			
		
%% Initialization
Obv 		= discretize_position_and_angle(gesture_mat);
sym_used	= Obv{5,2};
sym_train	= sym_used(1:50,1);
sym_test	= sym_used(51:100,1);
% sym_train 	= sym_used(1:(floor(length(sym_used)/2)),1);
% sym_test	= sym_used((floor(length(sym_used)/2)+1):length(sym_used),1);
num_state 	= 2;
num_symbol 	= 2^20;
num_LR 		= 2; 	% degree of play in the left-to-right HMM transition matrix 
gestureRecThreshold = 0; % set below
possible_sym = [1:num_symbol];
% poss_sym = dec2bin(poss_sym);

%% Training
%% Set priors
prior = prior_transition_matrix(num_state,num_LR);

%% Train the model
clc; cyc = 100;
[emis,trans,prior,loglik] = ...
	dhmm_numeric(sym_train, prior, possible_sym', num_state, cyc, .00001);
	% OK but it takes very long time, about 4 hours per gesture, subhanallah... T_T