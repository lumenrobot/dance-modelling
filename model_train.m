%% 	--------------------------------------------------------------
%%	Load segmented gesture and quantization of observation symbol
%%	--------------------------------------------------------------
fprintf('Now %s.\n', datestr(now));
% load('gesture_segmented.mat');
% load('model_trained2.mat');
% possible_sym = getPossibleSym(3,3,5,5,5,5,3,3);
% [data_angle, data_quant, data_sym] = getQuantData(D, possible_sym);
gesture_name = 'D';
data_sym = D_data_sym;

%% 	--------------------------------------------------------------
%% 	Dividing the Data
%%	80% data for training, 20% data for testing
%% 	--------------------------------------------------------------
data_sym_train = {}; data_sym_test = {}; tst = 1; trn = 1;
for i = 1:length(data_sym);
	if mod(i,5)==0
		data_sym_test{tst} = data_sym{i};
		tst = tst + 1;
	% else
		% data_sym_train{trn} = data_sym{i};	% train with 80% data
		% trn = trn + 1;
	end;
end;
data_sym_train = data_sym; % train with 100% data

%% 	--------------------------------------------------------------
%% 	Initialization
%% 	--------------------------------------------------------------
num_state 	= 5;						% number of state
num_symbol 	= length(possible_sym);		% number of discrete symbol
num_LR 		= 2; 						% degree of play in the left-to-right HMM transition matrix 
rec_threshold = 0; 						% set below
prior1 = [1;0;0;0;0];
trans1 = prior_transition_matrix(num_state,num_LR);
emis1 = mk_stochastic(rand(num_state,num_symbol));

%% 	--------------------------------------------------------------
%%	Training
%% 	--------------------------------------------------------------
[LL_train, prior2, trans2, emis2] = ...
	dhmm_em(data_sym_train, prior1, trans1, emis1, 'thresh', 0.00001); % Bayes Net Toolbox
	
% [emis2, trans2, prior2, LL_train] = ...
	% dhmm_numeric(data_sym_train, trans1, (possible_sym(:,1)), num_state, 1000, .00001); % Creative Distraction
	
%% 	--------------------------------------------------------------
%%	Thresholding
%% 	--------------------------------------------------------------
LL_thresh = [];
for i = 1:length(data_sym_train)
	% lik = dhmm_logprob(data_sym_train{i}, prior2, trans2, emis2); % Bayes Net Toolbox
	lik = pr_hmm(data_sym_train{i}, trans2, emis2, prior2); % Creative Distraction
	LL_thresh = [LL_thresh; lik];
end	
% rec_threshold = 2*sum(LL_thresh)/length(LL_thresh);
rec_threshold = min(LL_thresh);

%% 	--------------------------------------------------------------
%%	Testing
%% 	--------------------------------------------------------------
LL_test = []; found = 0; error = 0;
for i = 1:length(data_sym_test)
	% loglik = dhmm_logprob(data_sym_test{i}, prior2, trans2, emis2); % Bayes Net Toolbox
	loglik = pr_hmm(data_sym_test{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		found = found + 1;
	end;
	if (loglik == -Inf)
		error = error + 1;
	end;
	LL_test = [LL_test; loglik];
end;

fprintf('-------------------------------------\n');
fprintf('Gesture %s. Using %d states\n', gesture_name, num_state);
fprintf('Data training 	= %d.\n', length(data_sym_train));
fprintf('Data testing  	= %d.\n', length(data_sym_test));
fprintf('Found 			= %d.\n', found);
fprintf('Error			= %d.\n', error);
fprintf('Recognition Rate = %6.2f percent.\n', 100*found/length(data_sym_test));
fprintf('Now %s.\n', datestr(now));


