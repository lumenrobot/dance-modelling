% 	phrase_plot.m
% 	Update 21 Juli 2014
% 	Memplot hasil pengujian phrase Assalamualaikum

%%	Initilization
	load('phrase_tested.mat');
	w = 7;	% Line width

%%	Plot

	for i = 1:20
		found = fnd2{i};
		found = found*i;
		plot(found(:,1), '+r', 'LineWidth',w); hold on; %O
		plot(found(:,2), '+m', 'LineWidth',w); hold on;	%A
		plot(found(:,3), '+b', 'LineWidth',w); hold on; %B
		plot(found(:,4), '+c', 'LineWidth',w); hold on;	%C
		plot(found(:,5), '+g', 'LineWidth',w); hold on; %D
		plot(found(:,6), '+k', 'LineWidth',w); hold on;	%E
		plot(found(:,7), '+y', 'LineWidth',w); hold on;	%false
	end;
	
	fnd_ideal = fnd_ideal-3;
	
	plot(fnd_ideal(:,1), '+r', 'LineWidth',w); hold on; %O
	plot(fnd_ideal(:,2), '+m', 'LineWidth',w); hold on;	%A
	plot(fnd_ideal(:,3), '+b', 'LineWidth',w); hold on; %B
	plot(fnd_ideal(:,4), '+c', 'LineWidth',w); hold on;	%C
	plot(fnd_ideal(:,5), '+g', 'LineWidth',w); hold on; %D
	plot(fnd_ideal(:,6), '+k', 'LineWidth',w); hold on;	%E
	plot(fnd_ideal(:,7), '+y', 'LineWidth',w); hold on;	%false
	
	plot(21);
	plot(-2);

legend('Gesture O', 'Gesture A', 'Gesture B', 'Gesture C', 'Gesture D', 'Gesture E', 'False Gesture', 'Location', 'BestOutside');
title('Pengujian 20 Frase Assalamualaikum');
ylabel('Hasil Rekognisi Frase'); xlabel('Time');


% true = 0; false = 0; found = fnd2{1};
% for i=1:length(fnd_ideal)
	% if found(i+1,:)==fnd_ideal(i,:)
		% true = true+1;
	% else
		% false = false+1;
	% end;
% end;
% fprintf('\nTrue = %d, False = %d, Rate = %6.2f.\n', true, false, (100*true)/(true+false));
