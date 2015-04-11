% ###########################
% nidgesture, memasukkan sekian data ke array of data stream untuk setiap gesture

%% Initialization
A = {}; a=0; % Array of Gesture A
B = {}; b=0; % Array of Gesture B
C = {}; c=0; % Array of Gesture C
D = {}; d=0; % Array of Gesture D
E = {}; e=0; % Array of Gesture E
N = {}; n=0; % Arraf of Noisy Gesture

%% Input the data stream
a = a+1; A{a} = Ar(awal:akhir,:); nidedit1;
b = b+1; B{b} = Ar(awal:akhir, :); nidedit2;
c = c+1; C{c} = Ar(awal:akhir, :); nidedit2;
d = d+1; D{d} = Ar(awal:akhir, :); nidedit2;
e = e+1; E{e} = Ar(awal:akhir, :); nidedit1;
n = n+1; N{n} = Ar(awal:akhir, :);


a = a+1; A{a}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

b = b+1; B{b}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

c = c+1; C{c}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

d = d+1; D{d}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

e = e+1; E{e}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]

n = n+1; N{n}=[tcapt(awal:akhir) Spine(awal:akhir,:) CHip(awal:akhir,:) RHip(awal:akhir,:) LHip(awal:akhir,:) CShld(awal:akhir,:) RShld(awal:akhir,:) RElbw(awal:akhir,:) RWrst(awal:akhir,:) LShld(awal:akhir,:) LElbw(awal:akhir,:) LWrst(awal:akhir,:)]