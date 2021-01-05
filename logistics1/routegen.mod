###
###    AMPL Model: ���[�g�������W���[��
###

### ���[�g�����p�����[�^�[  & OBJ �R�X�g
let Routes := {1..500000};               # ���[�g�̐����I�[�o�[����Α傫������

### ���[�g����

## ������
for {k in Routes} {
   let Route_No_Sites[k] := 0;
   let Route_Sites     [k] := {};
   let Route_SC       [k] := 0;
   let Route_Dist      [k] := 0;
   let Route_Cost     [k] := 0;
   };

print "-> ���[�g�����J�n: SC����" & card(SC_Sites) & " �P���A" & "�ő勗�� " & Max_Neibor & " km�A�ő�SC�� " & Max_SC & " �ł��B";

## ���[�g�̐���
let r:= 1;
let big_value := avg_speed * wrk_hours * big_capac / big_cost / 2;
let small_value := avg_speed * wrk_hours * small_capac / small_cost;

for {i in SC_Sites} {

   # 0�J�����[�g
   let Route_SC [r] := i;

   # �����̎ԑ䐔�T�Z
   for {q in AFC_Sites} {

         let Route_Cost[r] := dist[q, i] * demand[q, i] /big_value; 
        }
 
   # ���̃��[�g��
   let r := r + 1;
   };
let r0 := r;

let r1 := 0;                                    ## �������[�g�̐������邽�� 
let r2 := 0;                                    ## �O�p���[�g�̐������邽��
let r3 := 0;                                    ## �l�p���[�g�̐������邽��

for {i in SC_Sites} {

   if i mod 10 = 0 then
      print "-> "& "����" &  i & "�Ԗڂ�SC���ŁA���[�g���� " & r & " (�_ "& r0 & "�A���� " & r1& "�A�O�p " & r2 & "�A�l�p " & r3 & ")";

   # SC i �ɑ΂��āA���[�g�ɓ���ߗ׌��T�C�g���W�߂�
   let Neibor := {};
   for {j in JP_Sites: i != j && dist[i,j] <= Max_Neibor} {
       let Neibor := Neibor union {j};
       };

   # SC i �ɑ΂��āA���[�g�ɓ���g��ߗ׌��T�C�g���W�߂�
   let ExNeibor := {};
   for {j in JP_Sites: i != j && dist[i,j] <= Max_Neibor} {
       let ExNeibor := ExNeibor union {j};
       };

   ##### 1�J�����[�g�iSC i �ȊO�ɂP����j�A�Q�l�̂��߂ɋL�q���Ă���j
   for {j in Neibor} {
      let Route_SC       [r] := i;
      let Route_No_Sites[r] := 1;
      let Route_Sites     [r] := {j};
      let Route_Dist      [r] := dist[i, j] + dist[j, i];
      let total := 0;
      for {q in AFC_Sites} {

         # �T�C�gj �̎��v��o�^�ASC i �̎��v���ǉ�����
         let total := total + demand[q, j];

         # �����̎ԑ䐔�T�Z
         let Route_Cost[r] :=  (demand[q, j]+demand[q, i]) /big_value * dist[q, i] ; 
        }

      #�@���[�g�̗A���R�X�g�T�Z
      let Route_Cost [r] := Route_Cost[r] + total/small_value*Route_Dist[r];
      
      # ���̃��[�g��
      let r := r + 1;
      let r1 := r1 + 1;
      };

   ##### 2�J���i�O�p�j���[�g�iSC i �ȊO�ɂQ���� j & k )
   for {j in Neibor, k in Neibor: j < k && dist[j,k] <= Max_Neibor/2.0 } {                    # originally /2.0 }
      let Route_SC       [r] := i;
      let Route_No_Sites [r] := 2;
      let Route_Sites    [r] := {j} union {k};
      let Route_Dist     [r] := dist[i, j] + dist[j, k] + dist[k, i];
      let total := 0;
      for {q in AFC_Sites} {
         let total := total + demand[q, j] + demand[q, k];

         # �����̎ԑ䐔�T�Z
         let Route_Cost[r] := (demand[q, j]+demand[q, k]+demand[q, i]) /big_value * dist[q, i] ; 
         } 

      #�@���[�g�̗A���R�X�g�T�Z
      let Route_Cost [r] := Route_Cost[r] + total / small_value * Route_Dist[r];

      # ���̃��[�g
      let r := r +1;
      let r2 := r2 + 1;

      ##### �R�����i�l�p�j���[�g�i===> ���������L�����镔���ł��邪�A�Q�������[�g�ɒǉ����Đ�������ƌ������ǂ��Ȃ�j
      if r < 0 then
      for {m in ExNeibor: m != j && m != k && dist[j,m] <= Max_Neibor/2.0 && dist[k,m] <= Max_Neibor/2.0} {
         let Route_SC       [r] := i;
         let Route_No_Sites [r] := 3;
         let Route_Sites    [r] := {j} union {k} union {m};
         let Route_Dist     [r] := dist[i, j] + dist[j, m] + dist[m, k] + dist[k, i];
         let total := 0;
         for {q in AFC_Sites} {
            let total := total + demand[q, j] + demand[q, m] + demand[q, k];

            # �����̎ԑ䐔�T�Z
            let Route_Cost[r] := (demand[q, j]+demand[q, m]+demand[q, k]+demand[q, i]) /big_value * dist[q, i] ; 
            }        

         #�@���[�g�̗A���R�X�g�T�Z
         let Route_Cost [r] := Route_Cost[r] + total / small_value * Route_Dist[r];

         let r := r + 1;
         let r3 := r3 + 1;
         };
      };
   };

# �I�����b�Z�[�W
print "";
print "-> �S�̂�"& r & "�̃��[�g�𐶐����A�œK���̏������ł��܂����B";





