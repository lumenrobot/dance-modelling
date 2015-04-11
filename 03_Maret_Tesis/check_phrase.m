%%%% check Phrase..
%% check_phrase.m 
%% 20 Mar 2014
%% Ayo Ayo Bismillahirrahmanirrahim

%% Cek  A
	recog = 0;
	[gesture,id_awal,id_akhir] = check_gesture_1(multiple_phrase,trshld_time,id_akhir,A_prior,A_emis,A_trans,A_trshold);
	% if detected A, check B
	if (gesture == '1')
		recog = 1;
		[gesture,id_awal,id_akhir] = check_gesture_1(multiple_phrase,trshld_time,id_akhir,B_prior,B_emis,B_trans,B_trshold);
		
		% if detected B, check C
		if (gesture == '1')
			recog = 2;
			[gesture,id_awal,id_akhir] = check_gesture_2(multiple_phrase,trshld_time,id_akhir,C_prior,C_emis,C_trans,C_trshold);
			
			% if detected C, check D
			if (gesture == '1')
				recog = 3;
				[gesture,id_awal,id_akhir] = check_gesture_2(multiple_phrase,trshld_time,id_akhir,D_prior,D_emis,D_trans,D_trshold);
				
				% if detected D, check E
				if (gesture == '1')
					recog = 4;
					[gesture,id_awal,id_akhir] = check_gesture_2(multiple_phrase,trshld_time,id_akhir,E_prior,E_emis,E_trans,E_trshold);
					
					% if detected E
					if (gesture == '1')
						recog = 5;
						recog_phrase = [recog_phrase; recog];
						i = i+1;
						check_phrase;
					else
						recog_phrase = [recog_phrase; recog];
						i = i+1;
						check_phrase;
					end;
				else
					recog_phrase = [recog_phrase; recog];
					i = i+1;
					check_phrase;
				end;
			else
				recog_phrase = [recog_phrase; recog];
				i = i+1;
				check_phrase;
			end
		else
			recog_phrase = [recog_phrase; recog];
			i = i+1;
			check_phrase;
		end
	else
		recog_phrase = [recog_phrase; recog];
		i = i+1;
		check_phrase;
	end;		