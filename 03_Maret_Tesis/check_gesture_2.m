function [gesture,id_awal,id_akhir] = check_gesture_2(data,trshld_time,id_akhir,...
								prior,emis,trans,trshld_gesture)
									



%%% Found Start and End Index of a gesture
	id_awal = id_akhir;
	while floor(data(id_awal,1)+2-trshld_time) > floor(data(id_akhir,1)-trshld_time) 
		id_akhir = id_akhir+1;
	end

%%% Count the log-likelihood	
	fprintf('\nTesting 2 sec');
	LL = 0;
	LL = pr_hmm(data(id_awal:id_akhir,2),trans,emis',prior);
	if (LL > trshld_gesture)
		fprintf('\nLoglik: %f > trshld = %f - 1_FOUND!\n',LL,trshld_gesture);
		gesture = '1';
	else
		fprintf('\nLoglik: %f < trshld = %f - 1_NO.\n',LL,trshld_gesture);
		gesture = '0';
	end
