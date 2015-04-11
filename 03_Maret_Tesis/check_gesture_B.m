function [gesture,id_akhir] = check_gesture_AB(data, trshld_time,id_awal,...
									prior,emis,trans,trshld_gesture)
									



%%% Found Start and End Index of a gesture
	id_akhir = id_awal;
	while floor(data(id_awal,1)+1-trshld_time) > floor(data(id_akhir,1)-trshld_time) 
		id_akhir = id_akhir+1;
	end

%%% Count the log-likelihood	
	fprintf('\nTesting A');
	LL = 0;
	LL = pr_hmm(data(id_awal:id_akhir,2),trans,emis',prior);
	if (LL > trshld_gesture)
		fprintf('\nLoglik: %f > %f (threshold) -- FOUND A!\n',LL,trshld_gesture);
		gesture = 'A';
	else
		fprintf('\nLoglik: %f < %f (threshold) -- NO A.\n',LL,trshld_gesture);
		gesture = '0';
	end
