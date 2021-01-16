###
###    AMPL Model: ルート生成モジュール
###

### ルート生成パラメーター  & OBJ コスト
let Routes := {1..500000};               # ルートの数がオーバーすれば大きくする

### ルート生成

## 初期化
for {k in Routes} {
   let Route_No_Sites[k] := 0;
   let Route_Sites     [k] := {};
   let Route_SC       [k] := 0;
   let Route_Dist      [k] := 0;
   let Route_Cost     [k] := 0;
   };

print "-> ルート生成開始: SC候補は" & card(SC_Sites) & " ケ所、" & "最大距離 " & Max_Neibor & " km、最大SC数 " & Max_SC & " です。";

## ルートの生成
let r:= 1;
let big_value := avg_speed * wrk_hours * big_capac / big_cost / 2;
let small_value := avg_speed * wrk_hours * small_capac / small_cost;

for {i in SC_Sites} {

   # 0カ所ルート
   let Route_SC [r] := i;

   # 幹線の車台数概算
   for {q in AFC_Sites} {

         let Route_Cost[r] := dist[q, i] * demand[q, i] /big_value; 
        }
 
   # 次のルートへ
   let r := r + 1;
   };
let r0 := r;

let r1 := 0;                                    ## 直線ルートの数を見るため 
let r2 := 0;                                    ## 三角ルートの数を見るため
let r3 := 0;                                    ## 四角ルートの数を見るため

for {i in SC_Sites} {

   if i mod 10 = 0 then
      print "-> "& "現在" &  i & "番目のSC候補で、ルート数は " & r & " (点 "& r0 & "、直線 " & r1& "、三角 " & r2 & "、四角 " & r3 & ")";

   # SC i に対して、ルートに入る近隣候補サイトを集める
   let Neibor := {};
   for {j in JP_Sites: i != j && dist[i,j] <= Max_Neibor} {
       let Neibor := Neibor union {j};
       };

   # SC i に対して、ルートに入る拡大近隣候補サイトを集める
   let ExNeibor := {};
   for {j in JP_Sites: i != j && dist[i,j] <= Max_Neibor} {
       let ExNeibor := ExNeibor union {j};
       };

   ##### 1カ所ルート（SC i 以外に１か所j、参考のために記述してある）
   for {j in Neibor} {
      let Route_SC       [r] := i;
      let Route_No_Sites[r] := 1;
      let Route_Sites     [r] := {j};
      let Route_Dist      [r] := dist[i, j] + dist[j, i];
      let total := 0;
      for {q in AFC_Sites} {

         # サイトj の需要を登録、SC i の需要も追加する
         let total := total + demand[q, j];

         # 幹線の車台数概算
         let Route_Cost[r] :=  (demand[q, j]+demand[q, i]) /big_value * dist[q, i] ; 
        }

      #　ルートの輸送コスト概算
      let Route_Cost [r] := Route_Cost[r] + total/small_value*Route_Dist[r];
      
      # 次のルートへ
      let r := r + 1;
      let r1 := r1 + 1;
      };

   ##### 2カ所（三角）ルート（SC i 以外に２か所 j & k )
   for {j in Neibor, k in Neibor: j < k && dist[j,k] <= Max_Neibor/2.0 } {                    # originally /2.0 }
      let Route_SC       [r] := i;
      let Route_No_Sites [r] := 2;
      let Route_Sites    [r] := {j} union {k};
      let Route_Dist     [r] := dist[i, j] + dist[j, k] + dist[k, i];
      let total := 0;
      for {q in AFC_Sites} {
         let total := total + demand[q, j] + demand[q, k];

         # 幹線の車台数概算
         let Route_Cost[r] := (demand[q, j]+demand[q, k]+demand[q, i]) /big_value * dist[q, i] ; 
         } 

      #　ルートの輸送コスト概算
      let Route_Cost [r] := Route_Cost[r] + total / small_value * Route_Dist[r];

      # 次のルート
      let r := r +1;
      let r2 := r2 + 1;

      ##### ３ヵ所（四角）ルート（===> これも自ら記入する部分であるが、２か所ルートに追加して生成すると効率が良くなる）
      if r < 0 then
      for {m in ExNeibor: m != j && m != k && dist[j,m] <= Max_Neibor/2.0 && dist[k,m] <= Max_Neibor/2.0} {
         let Route_SC       [r] := i;
         let Route_No_Sites [r] := 3;
         let Route_Sites    [r] := {j} union {k} union {m};
         let Route_Dist     [r] := dist[i, j] + dist[j, m] + dist[m, k] + dist[k, i];
         let total := 0;
         for {q in AFC_Sites} {
            let total := total + demand[q, j] + demand[q, m] + demand[q, k];

            # 幹線の車台数概算
            let Route_Cost[r] := (demand[q, j]+demand[q, m]+demand[q, k]+demand[q, i]) /big_value * dist[q, i] ; 
            }        

         #　ルートの輸送コスト概算
         let Route_Cost [r] := Route_Cost[r] + total / small_value * Route_Dist[r];

         let r := r + 1;
         let r3 := r3 + 1;
         };
      };
   };

# 終了メッセージ
print "";
print "-> 全体で"& r & "個のルートを生成し、最適化の準備ができました。";