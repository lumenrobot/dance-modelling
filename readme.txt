Fungsi semua program yang sudah dibuat --> 20/3/2014

csum(X)			Jumlahin elemen-elemen dalam kolom
cdiv(X,Y)		Elemen kolom matrix X/elemen kolom matrix Y
rsum(X)			Jumlahin elemen-elemen dalam baris
rdiv(X,Y)		Elemen baris matrix X/elemen baris matrix Y

nidgui			Merekam gerakan kinect + imu
nidimu			Merekam gerakan imu
nidplot			Memplot gerakan
nidplot3		Memplot gerakan 3D
nidgest			Memasukkan sekian data ke array of data stream untuk setiap gesture
nidsequence		Mencek Tari Likok Pulo pada level phrase.
nideditdata		Semua edit raw data coba-coba ada di sini
nidedit1		Segmentasi gesture 1 detik
nidedit2		Segmentasi gesture 2 detik

clust			Kuantisasi jadi 8
clust4			Kuantisasi jadi 4
clust4_90		Kuantisasi 90 bagi 4
clust4_180		Kuantisasi 180 bagi 4
clust8_180		Kuantisasi 180 bagi 8
clust8_360		Kuantisasi 360 bagi 8

checkCross			Check whether two joints clapped or crossed
checkBLock			Check where the joint were placed in 7x7x4 block
checkAngle			Count the arm angle using inverse kinematics
check_phrase		Check apakah frasenya benar
check_gesture_1		Ngitung score gesture 1 detik
check_gesture_2		Ngitung score gesture 2 detik
check_gesture_A		Ngitung score u/gesture A
check_gesture_B		Ngitung score u/gesture B
rotate				Rotate (x,y), degree of theta, relative to (xc, yc)
discretize...		Diskritisasi symbol
cobarekursif		coba fungsi rekursif

prior_transition_matrix		Create a prior for the transition matrix
pr_hmm						Menghitung forward probability
dhmm_coba					Training HMM
dhmm_coba2					Training HMM
dhmm_numeric				Training HMM Asli

---------------------------------------------------
Fungsi semua program yang sudah dibuat --> 20/7/2014
getRawData_noImu		Ambil raw data, konversi waktu
getRawData_withImu		Ambil raw data dari file capture, konversi waktu
getRawData_mat			Ambil raw data dari file .mat
getAngleInverse			Get arm angle using inverse kinematics
getQuantAngle			Get arm angle using torso PCA frame and sph.coord
						+ Quantization
getQuantData			Get array of discrete symbol;
getPossibleSym			Make table of all possible symbol

segment1.m				Segmentasi gesture 1 second
segment2.m				Segmentasi gesture 2 second
segment_1.m				Fungsi segmentasi gesture 1 second
segment_2.m				Fungsi segmentasi gesture 2 second
segmentimu.m			Segmentasi gesture yang dibatasi clap sensor

model_test.m			Menguji satu model dengan semua data
model_train.m			Melatih model dengan menggunakan hmm
model_trained.mat		Model HMM yang sudah dilatih dengan 80% data
model_trained_all.mat	Model HMM yang sudah dilatih dengan 100% data

gesture_segment.m			Sintaks yang digunakan waktu ordering data..
gesture_segmented.mat		Semua data2 joint yg sudah disegmentasi dan dikelompokkan
							Yg disegmentasi dgn window dan clapsensor dipisah
gesture_segmented_conc.mat	Semua data2 joint yang sudah disegmentasi dan dikelompokkan
gesture_test.m				Menguji satu gesture dengan semua model
gesture_test_rt.m			Menguji satu gesture dengan semua model (real time)

phrase_captured				Rekaman frase assalamualaikum
phrase_test.m				Menguji phrase assalamualaikum.
phrase_tested.mat			Hasil rekognisi frase Assalamualaikum

orientation_captured.mat		Data rekaman berbagai orientasi
orientation_test.mat			Menguji berbagai posisi (belum tuntas)

main_console		Pengujian realtime, menggunakan console
main_gui			Pengujian realtime, menggunakan gui
main_mat			Merekam data, dimasukkan ke file .mat
						
*******************************************************
