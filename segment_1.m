function [id_first id_last] = segment_1 (data, id_last, thresh)

%%	Segmentation
	id_first = id_last;
	while floor(data(id_first,1)+1-thresh) > floor(data(id_last,1)-thresh) 
		id_last = id_last+1;
	end
	
	plot(data(id_first:id_last,23),data(id_first:id_last,24), 'r'); hold on;
	plot(data(id_first:id_last,32),data(id_first:id_last,33), 'b'); hold on;
	
