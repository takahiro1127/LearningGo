###
###    AMPL Model: �l�b�g�̔��������f��
###

###    Set Definition

set JP_Sites;          ##�@�J�o�[���ׂ����_�J���@(1..n)
set SC_Sites;         ##  SC���n�AJP_Sites�̈ꕔ
set AFC_Sites;       ##  AFC �T�C�g (n+1, n+2, n+3)
set ALL_Sites;        ##  �S�ẴT�C�g�AJP_Sites + AFC
set Routes;           ##  ���[�g�ԍ�
set Neibor;            ##  �ߗ׏W��(Max_Neibor�Œ�`�����͈�)
set ExNeibor;         ## �g��ߗ׏W��

###    Parameter Definition

param dist {ALL_Sites, ALL_Sites};      ##  �Q�_�Ԃ̋���
param demand {AFC_Sites, JP_Sites};  ##  �i�o�T�C�g�ł̎��v�AAFC����̗A������
param Max_Dist > 0;                       ##  ���[�g�̍ő勗��
param Max_Neibor > 0;                    ##  ���[�g��̃T�C�g��SC�̍ő勖�e����
param r >= 0;                               ##  ���[�g�ԍ��̃C���f�b�N�X
param n >= 0;                               ##  JP�T�C�g�̃C���f�b�N�X
param total >= 0;                           ## �A���ʍ��v�̌v�Z�Ŏg�p
param r0 >= 0;                              ## �_���[�g�W�v�Ŏg�p
param r1 >= 0;                              ## �������\�g�W�v�Ŏg�p
param r2 >= 0;                              ## �O�p���[�g�W�v�Ŏg�p
param r3 >= 0;                              ## �l�p���[�g�W�v�Ŏg�p

param avg_speed >= 0;                   ## ���ώ���
param wrk_hours >= 0;                   ## �ԗ��ғ�����
param big_capac >= 0;                   ## �����ԗ��L���p�V�e�B�[
param small_capac >= 0;                ## ���[�g�ԗ��L���p�V�e�B�[
param big_cost >= 0;                     ## ��^�ԂP���P��
param small_cost >= 0;                  ## ���^�ԂP���P��
param big_value >= 0;                    ## �����ԗ��䐔�v�Z�p
param small_value >= 0;                 ## ���[�g�䐔�v�Z�p

param Route_SC        {Routes};       ## ���[�g��SC
param Route_Dist       {Routes};       ## ���[�g�̑�����
param Route_No_Sites {Routes};       ## ���[�g�Ɋ܂܂��T�C�g��
param Route_Cost      {Routes};       ## ���[�g�̃R�X�g
set   Route_Sites      {Routes};       ## ���[�g�Ɋ܂܂��T�C�g�W��

param Fix_Cost >= 0;                     ## SC�̌Œ�R�X�g
param Max_SC >= 0;                       ## �ő�SC��

###    Variable Definition

var X {Routes} integer, >= 0, <= 1.0;     # ���[�g�I���A0 or 1
var Y {SC_Sites} integer, >= 0, <= 1.0;   # SC�I���A0 or 1

###   Objective Function

minimize cost: 
sum {j in SC_Sites} Fix_Cost*Y[j] + sum {i in Routes} Route_Cost[i]*X[i];

###   Constraints

## ���_�I���ƃ��[�g�̘A�g  <=== SC���_�ݒ�̐��񎮂�ǉ�����
SC_route {k in SC_Sites}:
   


## �s����̃��[�g�ɂ��J�o�[�@�@<=== JP�T�C�g�����ׂăJ�o�[����鐧�񎮂̒ǉ�




## �ő�SC��  <=== �ő�SC���̐��������





############�@�Q�ƃt�@�C�����������

### ���|�[�g�o�͂̂���
param SC_Flag {JP_Sites};           # �������đI�΂ꂽ���̂����P�Ƃ���
param Assign_SC {JP_Sites};        # �ǂ̂r�b�Ɋ��蓖�Ă�ꂽ��
param Route_No {JP_Sites};         # ���[�g�ԍ��A�����݂ď��Ԃɒ�����
set Sel_Routes;                        # �I�΂ꂽ���[�g�Ɋ܂܂��i�o�T�C�g�̏W��
set Sel_SC;                             # �I�΂ꂽSC�̏W��

### �����}�g���b�N�X��ǂ�
include dist_demand.dat;             # ���_�ԋ�����i�o�T�C�g�ł̎��v�\�����v�Z���쐬�����

### ���[�g�̐������s��
include maxdist.mod;                 # ���[�g�p�ő勗���Ɖ^���P���ݒ�
include routegen.mod;               # �ʓr�p�ӂ���Ă���AMPL���[�g�����t�@�C��









