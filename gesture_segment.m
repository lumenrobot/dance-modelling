% ###########################
% nidgesture, memasukkan sekian data ke array of data stream untuk setiap gesture
% using segment1.m, segment2.m, segmentimu.m

%% Initialization
A = {}; a=0; % Array of Gesture A
B = {}; b=0; % Array of Gesture B
C = {}; c=0; % Array of Gesture C
D = {}; d=0; % Array of Gesture D
E = {}; e=0; % Array of Gesture E
O = {}; o=0; % Arraf of Noisy Gesture

%% Input the data stream
%% 	1	234		567		8910	111213	141516	171819	202122	232425	262728	293031	323334]
%%	t	Spine	CHip	RHip	LHip	CShld	RShld	RElbw	RWrst	LShld	LElbw	LWrst

a = a+1; A{a}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

b = b+1; B{b}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

c = c+1; C{c}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

d = d+1; D{d}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

e = e+1; E{e}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

n = n+1; N{n}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]