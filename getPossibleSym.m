% getPossibleSym.m
% Make table of all possible symbol that correspond to all possible dance's pose.
% Update 9/7/2014

function [possible_sym] = getPossibleSym(v1,v2,v3,v4,v5,v6,v7,v8)

pos = [];
for i = 1:v8
	pos = [pos; i];
end;

posi = pos; pos = [];
for i = 1:v7
	for j = 1:length(posi);
		pos = [pos; i*10+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v6
	for j = 1:length(posi);
		pos = [pos; i*10^2+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v5
	for j = 1:length(posi);
		pos = [pos; i*10^3+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v4
	for j = 1:length(posi);
		pos = [pos; i*10^4+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v3
	for j = 1:length(posi);
		pos = [pos; i*10^5+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v2
	for j = 1:length(posi);
		pos = [pos; i*10^6+posi(j)];
	end;
end

posi = pos; pos = [];
for i = 1:v1
	for j = 1:length(posi);
		pos = [pos; i*10^7+posi(j)];
	end;
end

lgth = [1:length(pos)]';
possible_sym = [lgth pos];
