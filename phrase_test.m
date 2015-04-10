% 	test_phrase.m
% 	Update 21 Juli 2014
% 	Menguji phrase Assalamualaikum, using sliding window

%%	Initilization
	id_first = 2;
	id_last = 2;
	thresh = 0.5;
	load('phrase_captured.mat')
	raw_data = Asslm_20;

%%	Conversion and Get Essential Data
	phrase = getRawData_mat(raw_data);
	% phrase(1810:2001,1) = phrase(1810:2001,1) +3600;
	phrase(1621:2111,1) = phrase(1621:2111,1) +3600;
	
%%	Segmentation, Quantization then Testing
	found = [];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	% [id_first id_last] = segment_2 (phrase, id_last, thresh);
	% found = [found; gesture_test_rt(phrase(id_first:id_last,:))];

	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%O
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	1
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	2
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	3
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	4
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	5
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	6
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%E	7
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%A
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_1 (phrase, id_last, thresh);		%B
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%C
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	[id_first id_last] = segment_2 (phrase, id_last, thresh);		%D
	found = [found; gesture_test_rt(phrase(id_first:id_last,:))];
	
