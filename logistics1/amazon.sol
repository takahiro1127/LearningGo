###
###    AMPL Model: Distribution Problem for eCommerce
###


### SOPT�̃I�v�V�����Ǝ��s
print "�܂��A���[�g�ϐ��̐������̓����b�N�X���ADC�ϐ��݂̂̍œK�����s���܂��B";
option sopt_options 'lplog bktsze=20000 srclev=2 iptime=100';
let {j in Routes} X[j].relax := 1;
solve;

print "���ɂ��̌��ʂ���DC���_�͌Œ艻���A���[�g�ϐ��̍œK�����s���܂��B";
option sopt_options 'lplog bktsze=20000 iptime=10';
let {j in Routes} X[j].relax := 0;
fix {i in SC_Sites} Y[i];
solve;

print "�œK�����I�����A���|�[�g�쐬�̏������ł��܂����B";







