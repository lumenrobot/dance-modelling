%% NID Skeleton
%
% Kinect�f�o�C�X����擾�������i�g���b�L���O�f�[�^��Ԃ��܂��B
%
% Copyright 2011-2012 The MathWorks, Inc.

%% ���͐M��
%
% * SYNC (uint32): IMAQ�u���b�N����o�͂���铯���p���ԐM������ [msec]�B

%% �o�͐M��
%
% * Tracking (int32): ���i�g���b�L���O���̑ΏێҐ��B
%
% * Skeleton (double): ���i��XYZ���W�f�[�^�B���W�́AReal world/Projective�̂����ꂩ�ɐݒ�ł��܂��B
%
% [OpenNI]
%
% 15�ӏ��̍��i��XYZ���W�f�[�^���擾�ł��܂��BXYZ���W�f�[�^��[0 0 0]�̏ꍇ�A���̍��i�͔F������Ă��Ȃ����Ƃ��Ӗ����܂��B
% �e���ʂ̍��i�f�[�^�́A���̍��i�f�[�^�v�f�Ɋi�[����Ă��܂��B
% Head = 1, Neck = 2, Torso = 3, Left shoulder = 4, Left elbow = 5,
% Left hand = 6, Right shoulder = 7, Right elbow = 8, Right hand= 9,
% Left hip = 10, Left knee = 11, Left foot = 12, Right hip = 13, Right knee = 14, Right foot = 15.
%
% ����L��Left, Right�͋���������Ă��܂�(�g���b�L���O����Ă���l�Ԃ̎��_���猩�����E�ł͂Ȃ��ANID���猩�����E�ɂȂ�܂�)
%
% <<SkeletonJoints.jpg>>
%
% [Kinect SDK for Windows]
%
% 20�ӏ��̍��i��XYZ���W�f�[�^���擾�ł��܂��BXYZ���W�f�[�^��[0 0 0]�̏ꍇ�A���̍��i�͔F������Ă��Ȃ����Ƃ��Ӗ����܂��B
% �e���ʂ̍��i�f�[�^�́A���̍��i�f�[�^�v�f�Ɋi�[����Ă��܂��B
% Hip center = 1, Spine = 2, Shoulder center = 3, Head = 4, Shoulder left = 5,
% Elbow left = 6, Wrist left = 7, Hand left = 8, Shoulder right = 9, Elbow right = 10,
% Wrist right = 11, Hand right = 12, Hip left = 13, Knee left = 14, Ankle left = 15,
% Foot left = 16, Hip right = 17, Knee right = 18, Ankle right = 19, Foot right = 20.
%
% <<SkeletonJoint_KinectSDK.png>>
%
% * Image (uint8): ���i�f�[�^��RGB24�C���[�W�B

%% �u���b�N�p�����[�^
%
% * Max number of Skeleton Tracking: ���i�g���b�L���O�Ώێ҂̍ő吔�B2��I�������ꍇ�ASkeleton output��������ǉ�����܂��B
%
% * Real world coordinates (Default: Projective): 15�ӏ��̍��i�f�[�^�̏o�͂ɑ΂��āAReal world  (X, Y, Z [m]) �܂��́AProjective (X,Y [pixel], Z [m]) XYZ���W��I���B
%
% Projective XYZ���W:
%
% <<ProjectiveXYZ.png>>
%
% Real world XYZ���W:
%
% <<RealWorldXYZ.png>>
%
% * Image output: ���i�f�[�^��RGB24�C���[�W�o�͂�ݒ�B

%% ���i�g���b�L���O�p�L�����u���[�V���� (OpenNI�̂ݗL��)
%
% �����i�g���b�L���O�p�L�����u���[�V�����́AIMAQ�u���b�N��Need PSI pose for calibration of Skeleton tracking��ON�ɂ��Ă��邩�A���i�g���b�L���O�̎����F���@�\���T�|�[�g���Ă��Ȃ��o�[�W������
% OpenNI���g�p���Ă���ꍇ�ɕK�v�ɂȂ�܂��B
%
% * �V�~�����[�V�������J�n���܂��B
%
% * �l��NID�̑���͈͓��œ����ƔF������A�l�̌`���\������܂��B
%
% * ���i�g���b�L���O�̃L�����u���[�V�����̂��߁APSI�|�[�Y�ƌĂ΂���p�̃|�[�Y��NID�̑O�łƂ�܂��B
%
% <<PsiPose.jpg>>
%
% * �L�����u���[�V��������������܂ŁAPSI�|�[�Y�̂܂ܓ����Ȃ��ł��������B�L�����u���[�V�������͐l�̌`�͔��F�ɕς��A��������ƌ��̐F�ɖ߂�܂��B
%
% * ���i�g���b�L���O�������Ȃ��Ă���Œ��́A�l�̌`�̏�Ɂ{�}�[�N���\������܂��B�{���\������Ă���ӏ���NID�ɂ���ăg���b�L���O����Ă��鍜�i���ʂɂȂ�܂��B
