% getQuantData.m
% 0. Input = Array of raw gesture data which has been segmented and classified
% 1. Build array of 8 principal angle for each gesture	(angle_data)
% 2. Build array of discrete symbol for each gesture	(discrete_sym)
% Last update 9/7/2014

function [data_angle, data_quant, data_sym] = getQuantData(data, possible_sym);

if iscell(data)
	data_size = size(data);
	data_angle = {};
	data_quant = {};
	data_sym = {};
	for i = 1:data_size(2)
		datum = data{i};
		datum_size = size(datum);
		datum_angle = [];
		datum_quant	= [];
		datum_sym	= [];
		for j = 1:datum_size(1)
			% 	1	234		567		8910	111213	141516	171819	202122	232425	262728	293031	323334]
			%	t	Spine	CHip	RHip	LHip	CShld	RShld	RElbw	RWrst	LShld	LElbw	LWrst
			%	getAnglePCA(Spine,CHip,RHip,LHip,CShld,RShld,RElbw,RWrst,LShld,LElbw,LWrst)
			[angle, quant] = getQuantAngle(datum(j,2:4),datum(j,5:7),datum(j,8:10),datum(j,11:13),datum(j,14:16),datum(j,17:19),datum(j,20:22),datum(j,23:25),datum(j,26:28),datum(j,29:31),datum(j,32:34));
			datum_angle = [datum_angle; angle];
			datum_quant = [datum_quant; quant];
			for k = 1:length(possible_sym)
				if quant == possible_sym(k,2)
					datum_sym = [datum_sym; possible_sym(k,1)];
				end;
			end;
		end;
		data_angle{i} = datum_angle;
		data_quant{i} = datum_quant;
		data_sym{i} = datum_sym;
	end;
else
	datum = data;
	datum_size = size(datum);
	datum_angle = [];
	datum_quant	= [];
	datum_sym	= [];
	for j = 1:datum_size(1)
		% 	1	234		567		8910	111213	141516	171819	202122	232425	262728	293031	323334]
		%	t	Spine	CHip	RHip	LHip	CShld	RShld	RElbw	RWrst	LShld	LElbw	LWrst
		%	getAnglePCA(Spine,CHip,RHip,LHip,CShld,RShld,RElbw,RWrst,LShld,LElbw,LWrst)
		[angle, quant] = getQuantAngle(datum(j,2:4),datum(j,5:7),datum(j,8:10),datum(j,11:13),datum(j,14:16),datum(j,17:19),datum(j,20:22),datum(j,23:25),datum(j,26:28),datum(j,29:31),datum(j,32:34));
		datum_angle = [datum_angle; angle];
		datum_quant = [datum_quant; quant];
		for k = 1:length(possible_sym)
			if quant == possible_sym(k,2)
				datum_sym = [datum_sym; possible_sym(k,1)];
			end;
		end;
	end;
	data_angle = datum_angle;
	data_quant = datum_quant;
	data_sym = datum_sym;
end



