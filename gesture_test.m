%% 	--------------------------------------------------------------
%%	Load segmented gesture and quantization of observation symbol
%%	--------------------------------------------------------------
fprintf('Now %s.\n', datestr(now));
load('gesture_segmented.mat');
load('model_trained2.mat');
gesture_name = 'O'; data_sym = O_data_sym;
lik = []; found = [];
for i = 1:(length(data_sym))
	%% 	--------------------------------------------------------------
	%%	Model O
	trans2 = O_trans2;
	emis2 = O_emis2;
	prior2 = [1;0;0];
	lik_O = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%% 	--------------------------------------------------------------
	%%	Model A
	trans2 = A_trans2;
	emis2 = A_emis2;
	prior2 = [1;0;0];
	lik_A = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%% 	--------------------------------------------------------------
	%%	Model B
	trans2 = B_trans2;
	emis2 = B_emis2;
	prior2 = [1;0;0];
	lik_B = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%% 	--------------------------------------------------------------
	%%	Model C
	trans2 = C_trans2;
	emis2 = C_emis2;
	prior2 = [1;0;0;0;0];
	lik_C = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%% 	--------------------------------------------------------------
	%%	Model D
	trans2 = D_trans2;
	emis2 = D_emis2;
	prior2 = [1;0;0;0;0];
	lik_D = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%% 	--------------------------------------------------------------
	%%	Model E
	trans2 = E_trans2;
	emis2 = E_emis2;
	prior2 = [1;0;0;0;0];
	lik_E = pr_hmm(data_sym{i},trans2,emis2,prior2);
	%%	--------------------------------------------------------------
	%%	Check, 24 Juli 2014m pakai threshold 80%
	lik = [lik; lik_O lik_A lik_B lik_C lik_D lik_E];
	if (max(lik(i,:)) == lik_O) && (max(lik(i,:))> -212.5823) % all -219.2924
		found = [found; 1 0 0 0 0 0 0];
	elseif (max(lik(i,:)) == lik_A) && (max(lik(i,:))> -230.3885) % all -238.3310
		found = [found; 0 1 0 0 0 0 0];
	elseif (max(lik(i,:)) == lik_B) && (max(lik(i,:))> -239.6458) % all -236.1416
		found = [found; 0 0 1 0 0 0 0];
	elseif (max(lik(i,:)) == lik_C) && (max(lik(i,:))> -380.4238) % all -386.7459
		found = [found; 0 0 0 1 0 0 0];
	elseif (max(lik(i,:)) == lik_D) && (max(lik(i,:))> -379.7770) % all -374.8780
		found = [found; 0 0 0 0 1 0 0];
	elseif (max(lik(i,:)) == lik_E) && (max(lik(i,:))> -438.9605) % all -480.9375
		found = [found; 0 0 0 0 0 1 0];
	else
		found = [found; 0 0 0 0 0 0 1];
	end;
end;

fprintf('-------------------------------------\n');
fprintf('Pola Gesture %s.\n', gesture_name);
sum(found)
fprintf('Detect as O	= %6.2f percent.\n', 100*sum(found(:,1))/length(data_sym));
fprintf('Detect as A	= %6.2f percent.\n', 100*sum(found(:,2))/length(data_sym));
fprintf('Detect as B	= %6.2f percent.\n', 100*sum(found(:,3))/length(data_sym));
fprintf('Detect as C	= %6.2f percent.\n', 100*sum(found(:,4))/length(data_sym));
fprintf('Detect as D	= %6.2f percent.\n', 100*sum(found(:,5))/length(data_sym));
fprintf('Detect as E	= %6.2f percent.\n', 100*sum(found(:,6))/length(data_sym));
fprintf('False	 	= %6.2f percent.\n', 100*sum(found(:,7))/length(data_sym));
fprintf('Now %s.\n', datestr(now));

set(gca,'color', [1 1 1]);
plot(lik(:,1), '.r'); hold on;
plot(lik(:,2), '.m'); hold on;
plot(lik(:,3), '.b'); hold on;
plot(lik(:,4), '.c'); hold on;
plot(lik(:,5), '.g'); hold on;
plot(lik(:,6), '.k'); hold on;

plt = []; plt(1:length(data_sym),1)= -219.2924; plot(plt, 'r');
legend('Model O', 'Model A', 'Model B', 'Model C', 'Model D', 'Model E', 'Min log-lik of O', 'Location', 'BestOutside');
title('Pengujian Pola Gesture O');
xlabel('Data'); ylabel('Log-likelihood'); hold off;