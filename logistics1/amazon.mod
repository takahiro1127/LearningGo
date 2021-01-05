###
###    AMPL Model: ネット販売物流モデル
###

###    Set Definition

set JP_Sites;          ##　カバーすべき拠点カ所　(1..n)
set SC_Sites;         ##  SC候補地、JP_Sitesの一部
set AFC_Sites;       ##  AFC サイト (n+1, n+2, n+3)
set ALL_Sites;        ##  全てのサイト、JP_Sites + AFC
set Routes;           ##  ルート番号
set Neibor;            ##  近隣集合(Max_Neiborで定義される範囲)
set ExNeibor;         ## 拡大近隣集合

###    Parameter Definition

param dist {ALL_Sites, ALL_Sites};      ##  ２点間の距離
param demand {AFC_Sites, JP_Sites};  ##  ＪＰサイトでの需要、AFCからの輸送実績
param Max_Dist > 0;                       ##  ルートの最大距離
param Max_Neibor > 0;                    ##  ルート上のサイトとSCの最大許容距離
param r >= 0;                               ##  ルート番号のインデックス
param n >= 0;                               ##  JPサイトのインデックス
param total >= 0;                           ## 輸送量合計の計算で使用
param r0 >= 0;                              ## 点ルート集計で使用
param r1 >= 0;                              ## 直線ル―ト集計で使用
param r2 >= 0;                              ## 三角ルート集計で使用
param r3 >= 0;                              ## 四角ルート集計で使用

param avg_speed >= 0;                   ## 平均時速
param wrk_hours >= 0;                   ## 車両稼働時間
param big_capac >= 0;                   ## 幹線車両キャパシティー
param small_capac >= 0;                ## ルート車両キャパシティー
param big_cost >= 0;                     ## 大型車１日単価
param small_cost >= 0;                  ## 中型車１日単価
param big_value >= 0;                    ## 幹線車両台数計算用
param small_value >= 0;                 ## ルート台数計算用

param Route_SC        {Routes};       ## ルートのSC
param Route_Dist       {Routes};       ## ルートの総距離
param Route_No_Sites {Routes};       ## ルートに含まれるサイト数
param Route_Cost      {Routes};       ## ルートのコスト
set   Route_Sites      {Routes};       ## ルートに含まれるサイト集合

param Fix_Cost >= 0;                     ## SCの固定コスト
param Max_SC >= 0;                       ## 最大SC数

###    Variable Definition

var X {Routes} integer, >= 0, <= 1.0;     # ルート選択、0 or 1
var Y {SC_Sites} integer, >= 0, <= 1.0;   # SC選択、0 or 1

###   Objective Function

minimize cost: 
sum {j in SC_Sites} Fix_Cost*Y[j] + sum {i in Routes} Route_Cost[i]*X[i];

###   Constraints

## 拠点選択とルートの連携  <=== SC拠点設定の制約式を追加する
SC_route {k in SC_Sites}:
   


## 行き先のルートによるカバー　　<=== JPサイトがすべてカバーされる制約式の追加




## 最大SC数  <=== 最大SC数の制約を入れる





############　参照ファイルを取り入れる

### レポート出力のため
param SC_Flag {JP_Sites};           # 解を見て選ばれたものだけ１とする
param Assign_SC {JP_Sites};        # どのＳＣに割り当てられたか
param Route_No {JP_Sites};         # ルート番号、解をみて順番に着ける
set Sel_Routes;                        # 選ばれたルートに含まれるＪＰサイトの集合
set Sel_SC;                             # 選ばれたSCの集合

### 距離マトリックスを読む
include dist_demand.dat;             # 拠点間距離やＪＰサイトでの需要予測を計算し作成される

### ルートの生成を行う
include maxdist.mod;                 # ルート用最大距離と運送単価設定
include routegen.mod;               # 別途用意されているAMPLルート生成ファイル









