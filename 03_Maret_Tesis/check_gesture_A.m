function [gesture,id_akhir] = check_gesture_1(data, trshld_time,id_awal,...
									prior_emis,trans,trshld_gesture)
									



%%% Found Start and End Index of a gesture
	id_akhir = id_awal;
	while floor(data(id_awal,1)+1-trshld_time) > floor(data(id_akhir,1)-trshld_time) 
		id_akhir = id_akhir+1;
	end

%%% Count the log-likelihood	
	fprintf('\nTesting 1 sec');
	LL = 0;
	LL = pr_hmm(data(id_awal:id_akhir,2),A_trans,A_emis',A_prior);
	if (LL > trshld)
		fprintf('\nLoglik: %f > %f (threshold) - FOUND A!\n',LL,trshld_gesture);
		gesture = '1';
	else
		fprintf('\nLoglik: %f < %f (threshold) -- NO A.\n',LL,trshld_gesture);
		gesture = '0';
	end
