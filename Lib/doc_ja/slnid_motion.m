%% NID Motion
%
% Kinect�f�o�C�X����擾�������[�V�����F��ID�f�[�^��Ԃ��܂��B
%
% Copyright 2011-2012 The MathWorks, Inc.

%% ���͐M��
%
% * SYNC (uint32): IMAQ�u���b�N����o�͂���铯���p���ԐM������ [msec]�B

%% �o�͐M��
%
% * Motion (uint16): �e�s�N�Z�����̃��[�V�����F��ID�f�[�^(0 to 15)�B ID = 0�̓��[�V�����F���������Ӗ����܂��B
%
% * Image (uint8): ���[�V�����F��ID�f�[�^��RGB24�C���[�W�B
% �I�u�W�F�N�gID�Ɏ��̊e�F�����蓖�Ă��Ă��܂��B
% Red = 1, Green = 2, Blue = 3, Yellow = 4, Cyan = 5, Magenda = 6, Orange = 7,
% Dark green = 8, Teal = 9, Purple = 10, Olive = 11, Maroon = 12, Silver = 13,
% Navy = 14, Gold = 15.

%% �u���b�N�p�����[�^
%
% * Image output: ���[�V�����F��ID�f�[�^��RGB24�C���[�W�o�͂�ݒ�B
