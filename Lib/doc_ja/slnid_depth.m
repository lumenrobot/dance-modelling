%% NID Depth
%
% Kinect�f�o�C�X����擾�����[�x�f�[�^��Ԃ��܂��B
%
% Copyright 2011-2012 The MathWorks, Inc.

%% ���͐M��
%
% * SYNC (uint32): IMAQ�u���b�N����o�͂���铯���p���ԐM������ [msec]�B

%% �o�͐M��
%
% * Depth (double): �e�s�N�Z�����̐[�x�f�[�^ [m]�B�[�x�f�[�^ = 0�́A�[�x�f�[�^�̌v���s���Ӗ����܂��B
%
% * XYZ (double): XYZ���W�f�[�^�B���W�́AReal world/Projective�̂����ꂩ�ɐݒ�ł��܂��B
%
% * X/Y/Z (double): X, Y, Z���Ɨ��������W�f�[�^ [m]�B���W�́AReal world/Projective�̂����ꂩ�ɐݒ�ł��܂��B
%
% * Image (uint8): �[�x�f�[�^��RGB24�C���[�W�B���F�͐[�x�f�[�^�̌v���s���Ӗ����܂��B

%% �u���b�N�p�����[�^
%
% * Output: �[�x�f�[�^�̏o�̓��[�h�ݒ�B
%
% * Real world coordinates (Default: Projective): Real world (X, Y, Z [m]) �܂��́AProjective (X,Y [pixel], Z [m])���W��I���BXYZ�����X/Y/Z�[�x�f�[�^�o�̓��[�h�ɂ̂ݗL���B
%
% Projective XYZ���W:
%
% <<ProjectiveXYZ.png>>
%
% Real world XYZ���W:
%
% <<RealWorldXYZ.png>>
%
% * Image output: �[�x�f�[�^��RGB24�C���[�W�o�͂�ݒ�B
