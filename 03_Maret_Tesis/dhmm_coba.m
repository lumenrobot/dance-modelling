%% Mencoba menggenerate HMM.
%% Bismillahirrahmanirrahim!

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Load Recording File
clear; clc;

%% model
load('model_E5');
gesture_name = 'E';

%% yang diuji
load('gestD_1sec.mat');
gesture_mat = D;		% load record file
% Indices	Name				Number of Symbol			
% Obv{2,2} 	Block - bin2dec		(2^34)
% Obv{3,2}	Block - binary		bin2dec(2^34)
% Obv{4,2}	Block - num		
% Obv{5,2}	Angle - bin2dec		(2^20)
% Obv{6,2}	Angle - binary		bin2dec(2^20)
% Obv{7,2}	Angle - num			
		
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Initialization
Obv 		= discretize_position_and_angle(gesture_mat);
sym_used	= Obv{5,2};
% sym_train	= sym_used(40:130,1);	% E
% sym_test	= sym_used(131:220,1); 	% E
% sym_train	= sym_used(35:110,1);	% A
% sym_test	= sym_used(111:185,1); 	% A

sym_test 	= sym_used(1:(ceil(length(sym_used)/2)),1);
sym_train	= sym_used((ceil(length(sym_used)/2)+1):length(sym_used),1);
% sym_test	= sym_train;
num_state 	= 5;
num_symbol 	= 2^10;
num_LR 		= 2; 	% degree of play in the left-to-right HMM transition matrix 
possible_sym = [1:num_symbol];
% poss_sym = dec2bin(poss_sym);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Training
%% Set priors
% prior = prior_transition_matrix(num_state,num_LR);

% Train the model
% clc;
% [emis,trans,prior,loglik] = ...
	% dhmm_numeric(sym_train, prior, possible_sym', num_state, 100, .000001);
%%%	OK but it takes very long time, about 4 hours per gesture, subhanallah... T_T


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Testing using pr_hmm
% p = pr_hmm(o,a,b,pi)
% in	O	= Given observation sequence labeled in numerics
		% A(N,N)= transition probability matrix
		% B(N,M)= Emission matrix
		% pi	= initial probability matrix
% out	P	= probability of given sequence in the given model

% sumLik = 0;
% minLik = Inf;
% for j=1:length(sym_train)
	% lik = pr_hmm(sym_train{j},trans,emis',prior);
	% if (lik < minLik)
		% minLik = lik;
	% end
	% sumLik = sumLik + lik;
% end

% gestureRecThreshold = 2*sumLik/length(sym_train);	

gestureRecThreshold = 0.5*gestureRecThreshold;	

fprintf('\n\n********************************************************************\n');
fprintf('Testing %i sequences for a log likelihood greater than %f\n',length(sym_test),gestureRecThreshold);
fprintf('********************************************************************\n\n');

recs = 0;
tLL = zeros(length(sym_test),1);
for j=1:length(sym_test)
	tLL(j,1) = pr_hmm(sym_test{j},trans,emis',prior);
	if (tLL(j,1) > gestureRecThreshold)
		recs = recs + 1;
		fprintf('Loglik: %f > %f (threshold) -- FOUND %s!\n',tLL(j,1),gestureRecThreshold,gesture_name);
	else
		fprintf('Loglik: %f < %f (threshold) -- NO %s.\n',tLL(j,1),gestureRecThreshold,gesture_name);
	end
end
fprintf('Recognition success rate: %f percent\n',100*recs/length(sym_test));