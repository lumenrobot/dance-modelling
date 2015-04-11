function [obv] = discretize_position_and_angle(mat_name)
%%
% Discretize Observation Symbols by position and angles, 
% given Array of Observation Symbols
% -------------------------------------------------------

A = mat_name;
%%
obv_block_bin2dec = [];		% make new table of discrete observation symbols dec2bin of blockBin
obv_block_bin = {}; 		% make new array of discrete observation symbols, binary
obv_block_num = {};			% make new array of discrete observation symbols, number of block
obv_angle_bin2dec = [];		% make new table of discrete observation symbols dec2bin of anglebin
obv_angle_bin = {};
obv_angle_num = {};			% make new array of discrete observation symbols, value of angle
%%
szArr = size(A);
for j = 1:szArr(2)
	RShld = [A{j}(:,2) A{j}(:,3) A{j}(:,4)];
	RElbw = [A{j}(:,5) A{j}(:,6) A{j}(:,7)];
	RWrst = [A{j}(:,8) A{j}(:,9) A{j}(:,10)];
	LShld = [A{j}(:,11) A{j}(:,12) A{j}(:,13)];
	LElbw = [A{j}(:,14) A{j}(:,15) A{j}(:,16)];
	LWrst = [A{j}(:,17) A{j}(:,18) A{j}(:,19)];
	%%
	block_num = [];
	block_bin = [];
	block_bin2dec = [];
	angle_num = [];
	angle_bin = [];
	angle_bin2dec = [];
	sz = size(A{j});
	for i = 1:sz(1)
		%% Distance of shoulder, ok
		Dstnc = sqrt(((RShld(i,1)-LShld(i,1))^2) + ...
				((RShld(i,2)-LShld(i,2))^2) + ...
				((RShld(i,3)-LShld(i,3))^2));
		%% Length of Block, ok
		LgthBlk = Dstnc/2;
		%% Center of Shoulder, ok
		Center = (RShld(i,:)+LShld(i,:))/2;
		%% Check where the joint were placed 
		%% in 7x7x4 block of upper body space
		% BlkRWrst = checkBlock(RWrst(i,:), Center, LgthBlk);
		% BlkRElbw = checkBlock(RElbw(i,:), Center, LgthBlk);
		% BlkLWrst = checkBlock(LWrst(i,:), Center, LgthBlk);
		% BlkLElbw = checkBlock(LElbw(i,:), Center, LgthBlk);
		% cc = checkCross(RWrst(i,:), LWrst(i,:), LgthBlk);
		% 03:32, 13 March 2014
		% [cc][RWrst][RElbw][LWrst][LElbw]
		% block_num = [block_num; bin2dec(cc) bin2dec(BlkRWrst) bin2dec(BlkRElbw) ...
					% bin2dec(BlkLWrst) bin2dec(BlkLElbw)];
		% block_bin = [block_bin; cc BlkRWrst BlkRElbw BlkLWrst BlkLElbw];
		% block_bin2dec = [block_bin2dec; bin2dec(block_bin(i,:))];
		%% ArmAngle, 1x8
		%% [RShldTiltAngle][RShldRotAngle][RElbwTiltAngle][RElbwRotAngle]
		%% [LShldTiltAngle][LShldRotAngle][LElbwTiltAngle][LElbwRotAngle]
		[anglenum anglebin] = checkAngle(RShld(i,:),RElbw(i,:),RWrst(i,:),...
								LShld(i,:),LElbw(i,:),LWrst(i,:));
		angle_num = [angle_num; anglenum];
		angle_bin = [angle_bin; anglebin];
		angle_bin2dec = [angle_bin2dec; bin2dec(anglebin)];
	end
	obv_block_bin2dec{j,1} = block_bin2dec;
	obv_block_bin{j,1} = block_bin;
	obv_block_num{j,1} = block_num;
	obv_angle_bin2dec{j,1} = angle_bin2dec;
	obv_angle_bin{j,1} = angle_bin;
	obv_angle_num{j,1} = angle_num;
	newRawData{j,1} = A{1,j};
end

obv = {	'Raw Data', newRawData;
		'Block - dec2bin' obv_block_bin2dec;
		'Block - binary' obv_block_bin;
		'Block - num' obv_block_num;
		'Angle - dec2bin' obv_angle_bin2dec; 
		'Angle - binary' obv_angle_bin;
		'Angle - num' obv_angle_num};	%% OK 16/03/2014