%% 	--------------------------------------------------------------
%%	Load segmented gesture and quantization of observation symbol
%%	--------------------------------------------------------------
fprintf('Now %s.\n', datestr(now));
load('model_trained2.mat');
possible_sym = getPossibleSym(3,3,5,5,5,5,3,3);
gesture_name = 'D'; num_state = D;

%% 	--------------------------------------------------------------
%%	Model
%% 	--------------------------------------------------------------
LL_thresh = D_LL_thresh;
trans2 = D_trans2;
emis2 = D_emis2;
prior2 = [1;0;0;0;0];
rec_threshold = min(D_LL_thresh);

data_sym = D_data_sym;
data_sym_train = {}; data_sym_test = {}; tst = 1; trn = 1;
for i = 1:length(data_sym);
	if mod(i,5)==0
		data_sym_test{tst} = data_sym{i};
		tst = tst + 1;
	else
		data_sym_train{trn} = data_sym{i};
		trn = trn + 1;
	end;
end;


%% 	--------------------------------------------------------------
%%	Testing by other gesture pattern
%% 	--------------------------------------------------------------
D_LL_test_O = []; foundO = 0;
for i = 1:length(O_data_sym)
	loglik = pr_hmm(O_data_sym{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundO = foundO + 1;
	end;
	D_LL_test_O = [D_LL_test_O; loglik];
end;
%% 	--------------------------------------------------------------
D_LL_test_A = []; foundA = 0;
for i = 1:length(A_data_sym)
	loglik = pr_hmm(A_data_sym{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundA = foundA + 1;
	end;
	D_LL_test_A = [D_LL_test_A; loglik];
end;
%% 	--------------------------------------------------------------
D_LL_test_B = []; foundB = 0;
for i = 1:length(B_data_sym)
	loglik = pr_hmm(B_data_sym{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundB = foundB + 1;
	end;
	D_LL_test_B = [D_LL_test_B; loglik];
end;
%% 	--------------------------------------------------------------
D_LL_test_C = []; foundC = 0;
for i = 1:length(C_data_sym)
	loglik = pr_hmm(C_data_sym{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundC = foundC + 1;
	end;
	D_LL_test_C = [D_LL_test_C; loglik];
end;
%% 	--------------------------------------------------------------
D_LL_test_D = []; foundD = 0;
for i = 1:length(D_data_sym)
	loglik = pr_hmm(D_data_sym{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundD = foundD + 1;
	end;
	D_LL_test_D = [D_LL_test_D; loglik];
end;
%% 	--------------------------------------------------------------
D_LL_test_E = []; foundE = 0;
for i = 1:length(data_sym_test)
	loglik = pr_hmm(data_sym_test{i},trans2,emis2,prior2); % Creative Distraction
	if (loglik > rec_threshold) 
		foundE = foundE + 1;
	end;
	D_LL_test_E = [D_LL_test_E; loglik];
end;

fprintf('-------------------------------------\n');
fprintf('Model Gesture %s. Using %d states\n', gesture_name, num_state);
fprintf('Detect O	= %6.2f percent.\n', 100*foundO/length(O_data_sym));
fprintf('Detect A	= %6.2f percent.\n', 100*foundA/length(A_data_sym));
fprintf('Detect B	= %6.2f percent.\n', 100*foundB/length(B_data_sym));
fprintf('Detect C	= %6.2f percent.\n', 100*foundC/length(C_data_sym));
fprintf('Detect D	= %6.2f percent.\n', 100*foundD/length(D_data_sym));
fprintf('Detect E	= %6.2f percent.\n', 100*foundE/length(data_sym_test));
fprintf('Now %s.\n', datestr(now));

plot(D_LL_test_O,'.r'); hold on;
% plot(D_LL_test_O, 'r'); hold on;
plot(D_LL_test_A,'.m'); hold on;
% plot(D_LL_test_A,'m'); hold on;
plot(D_LL_test_B,'.b'); hold on;
% plot(D_LL_test_B,'b'); hold on;
plot(D_LL_test_C,'.c'); hold on;
% plot(D_LL_test_C,'c'); hold on;
plot(D_LL_test_D,'.g'); hold on;
% plot(D_LL_test_D,'g'); hold on;
plot(D_LL_thresh,'.k'); hold off;
% plot(D_LL_thresh,'k'); hold on;

title('Model E');
legend('Gesture O', 'Gesture A', 'Gesture B', 'Gesture C', 'Gesture D', 'Gesture E', 'Location', 'SouthEastOutside');
xlabel('Data'); ylabel('Log-likelihood');
set(gca,'color', [1 1 1]);