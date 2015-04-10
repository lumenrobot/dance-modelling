%% NID IMAQ
%
% Kinect�f�o�C�X����e��̃f�[�^���擾���܂��BSimulink Support for Kinect�̊e�u���b�N���g�p���鎞�́A�Œ�X�e�b�v�ŃV�~�����[�V�����������Ȃ��K�v������܂��B
%
% Copyright 2011-2012 The MathWorks, Inc.

%% ���͐M��
%
% * Angle (int32): Kinect�Z���T�[��Ίp�x[deg]���̓|�[�g�B���̓��̓|�[�g�́A Kinect SDK::Set sensor angle by Input���I�����ꂽ���ɗL���ƂȂ�܂��B
% -27�`27[deg]�͈̔͂��L�����͒l�ł���A����ȊO�̒l�����͂��ꂽ�ꍇ�́A�Ō�̐ݒ�p�x��ێ����܂��B

%% �o�͐M��
%
% * SYNC (uint32): NID Depth/Motion/Image/Skeleton/IR�u���b�N�Ƃ̓����p���ԐM���o�� [msec]�B
% SYNC�o�͐M���͒��ځANID Depth/Motion/Image/Skeleton/IR�u���b�N��SYNC���̓|�[�g�ցA�ڑ�����K�v������܂��B
%
% * Angle (int32): Kinect�Z���T�[��Ίp�x[deg]. �擾���ꂽ�Z���T�[�p�x��-64�`64[deg]�͈̔͂ɂȂ�܂��B
% ���̏o�͐M���́AKinect for Windows SDK���g�p���A���AKinect SDK::Read sensor angle�`�F�b�N�{�b�N�X��ON�ɂ����ꍇ�̂ݗL���ɂȂ�܂��B

%% �u���b�N�p�����[�^
%
% * Adjust view point to Image: NID Depth/Motion/Skeleton�u���b�N�p�擾�f�[�^�̃r���[�|�C���g��NID Image�u���b�N�p�擾�f�[�^
% �̃r���[�|�C���g�ɍ��킹��BNID Image�u���b�N���g�p���Ă���ꍇ�̂݁A���̐ݒ�͗L���ɂȂ�܂��B
%
% * Mirror image: �����C���[�W�f�[�^���擾����B���̐ݒ�͑S�Ẵf�o�C�X�f�[�^�ɔ��f����܂��B 
%
% * Sample time: �T���v�����Ԃ͏�L��Reslution and FPS�p�����[�^�Őݒ肳�ꂽ�A1/FPS[sec] �ȏ�ɐݒ肷��K�v������܂��B
% NID IMAQ�u���b�N�����ł́ANID�f�o�C�X����̈��肵���f�[�^�擾���������邽�߂ɁA�O��̃f�[�^�擾������A�ݒ肳�ꂽ�T���v�����Ԃ��߂���܂őҋ@���܂��B
%
% * OpenNI::Resolution: OpenNI����NID�̉𑜓x(Resolution)�ƍX�V���[�g(FPS: Frame Per Second)�̐ݒ�B
%
% * OpenNI::Need PSI pose for calibration of Skeleton tracking: ���i�g���b�L���O�p�L�����u���[�V�������ɁA��p�|�[�Y(PSI)��K�v�Ƃ��邩�A��p�|�[�Y�����Ŏ����F�������邩��I���ł��܂��B
%
% * Kinect SDK::Set sensor angle by Input: Kinect�Z���T�[��Ίp�x���u���b�N���̓|�[�g����ݒ肷��BKinect�n�[�h�E�F�A�̎d�l�ɂ��A�Z���T�[��Ίp�x�̕ύX�p�x�́A�����I��1�b�Ɉ��ɂȂ�܂��B
%
% * Kinect SDK::Sensor angle:  Kinect�Z���T�[��Ίp�x[deg]�BSensor angle�p�����[�^�l�́A-27�`27 [deg]�͈̔͂ɐݒ肷��K�v������܂��B
%
% * Kinect SDK::Read sensor angle: Kinect�Z���T�[��Ίp�x[deg]��Simulink��Ŏ擾���邽�߂̐ݒ�B
%
% * Kinect SDK::Near mode: Kinect Near Mode�̐ݒ�p�����[�^�BNear mode�ł́A�Z���T�O���̖�40[cm]�܂ł�3D�[�x�𑪒肷�邱�Ƃ��\�ɂȂ�܂��B
%
% * Kinect SDK::Seated mode: Kinect Seated Mode�̐ݒ�p�����[�^�BSeated mode�ł́A�㔼�g�݂̂����i�g���b�L���O�̑ΏۂƂȂ�܂��B
%
% * Kinect SDK::Skeleton smoothing parameters: Smoothing / Correction / Prediction / Jitter Radius / Max Deviation Radius�Ƃ���5�̃p�����[�^�l��ݒ肷�邱�Ƃ��ł��܂��B
% �f�t�H���g�l��[0.5 0.5 0.5 0.05 0.04]�ɂȂ�܂��B(�e�p�����[�^�̐�����Kinect SDK C++ API Reference����̈��p�ɂȂ�܂��B)
%
% - Smoothing: Smoothing parameter in the range [0.0, 1.0] inclusive. A higher value corresponds to more smoothing. Passing 0 causes the raw data to be returned. 
% As the smoothing value is increased responsiveness to the raw data decreases; therefore, increased smoothing leads to increased latency.
%
% - Correction: Correction parameter in the range [0.0, 1.0] inclusive. A higher value corrects toward the raw data more quickly, a lower value corrects more slowly and appears smoother.
%
% - Prediction: The number of frames to predict into the future, which must be greater than or equal to zero. Values greater than 0.5 will likely lead to overshoot when the data changes quickly; 
% dampen the overshoot effect by using a smaller value of Max Deviation Radius.
%
% - Jitter Radius: The jitter-reduction radius, in meters. Any jitter beyond this radius is clamped to the radius.
%
% - The maximum radius (in meters) that filtered positions can deviate from raw data. Filtered values that would exceed this radius from the raw data are clamped at this distance, in the direction of the filtered value.
%
% * Kinect SDK::Infer skeleton joints position: ���i�g���b�L���O���������ɂ��A��肭�s���Ȃ������ꍇ�A�ߋ��̃f�[�^���琄�肷�邩(��ON) �A�ۂ�(=OFF)��ݒ�ł��܂��B

%% NID IMAQ�u���b�N�Ƒ���NID�u���b�N�̐ڑ����@
%
% <<NID_SYNC.png>>
