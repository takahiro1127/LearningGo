###
###    AMPL Model: Distribution Problem for eCommerce
###


### CPLEX�̃I�v�V�����Ǝ��s
option solver cplex;
print "�܂��A���[�g�ϐ��̐������̓����b�N�X���ADC�ϐ��݂̂̍œK�����s���܂��B";
let {j in Routes} X[j].relax := 1;
solve;

print "���ɂ��̌��ʂ���DC���_�͌Œ艻���A���[�g�ϐ��̍œK�����s���܂��B";
let {j in Routes} X[j].relax := 0;
fix {i in SC_Sites} Y[i];
solve;

print "�œK�����I�����A���|�[�g�쐬�̏������ł��܂����B";







