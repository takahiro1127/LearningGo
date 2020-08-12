#include<iostream>
#include <algorithm>
using namespace std;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
//日付クラス
class Date {
    int year;
    int month;
    int day;
}
//証券クラス
class Security {
    public:
        //その証券を持っている量
        int amount;
        //原価
        int cost;
        //持っている証券の単価
        int inner_rate;
};
//日毎のレートを管理するクラス
class DailyRateManager {
    public:
        int rate_id;
        double dailyRate(Date date) {
            //ここはurlを呼んで取ってきたり、クエリを叩いたりして取ってくる
            // return getDataFromSource(Date, rate_id);
            return 100;
        }
        //オーバーロード
        double dailyRate(Date date, int to_rate_id) {
            //ここはurlを呼んで取ってきたり、クエリを叩いたりして取ってくる
            // return getDataFromSource(Date, to_rate_id);
            return 120;
        }
        //他の証券などに変える場合のレートを表す。
        double convertRate(Date date, int to_rate_id) {
            return dailyRate(date) / dailyRate(date, to_rate_id);
        }
        //他の証券に変えた場合の量を返す
        double convert(Date date, int to_rate_id, int amount) {
            return amount * convertRate(date, to_rate_id);
        }
};
//日毎で値段が変わる証券全般を扱うクラス
class DailyRateSecurity, public Security, public DailyRateManager {
    public:
        //その日の損益情報
        int calcProfit(Date date) {
            return amount * dailyRate(Date) - cost;
        }
        //その日にamount量だけ売った場合の損益情報
        int calcProfit(Date date, int sell_amount) {
            return sell_amount * dailyRate(Date) - cost * (sell_amount / amount);
        }
        //新たに証券を追加で買った場合の原価の
        int addSecuriry(int add_amount) {
            amount += add_amount;
            cost += add_amount * dailyRate(Date);
            inner_rate = cost / amount;
        }
}
class Company {
    public:
        int company_id;
        //時価総額
        int total_value;
        int dividend_rate;
        //その他株式会社に関係する情報をcompany classで保持する
        int getDividend(NormalStock stock) {
            return dividend_rate * stock.amount;
        }
        //優先株の時はrateをあげるなど、オーバーロードによって配当の量を変える。
        int getDividend(SpecialStock stock) {
            return dividend_rate * 2 * stock.amount;
        }
}
//株クラス 設計図には株を細かく分けていたが、普通株一つをここでは実装する。
class StockManager, public DailyRateSecurity {
    public:
        //株は会社情報を持つようにする。
        Company company;
        Stock (int company_id) {
            company_id = company_id;
            company = Company(company_id);
        };
        //株特有の動作を記述する
        //例:株主優待を得るなど
        // string getShareholderBenefit() {
        //     return company.getShareHolderBenefit();
        // }
};
//普通株のクラス
class NormalStock, public StockManager {
    public:
        //配当金を手に入れる
        int getDividend() {
            return company.getDividend(this);
        }
}
//優先株のクラス
class SpecialStock, public StockManager {
    public:
        //配当金を手に入れる
        int getDividend() {
            return company.getDividend(this);
        }
}
//口座クラス 証券を持つクラス
class Account {
    public:
        //idとのペアにする方法の方が良い
        Security[] securities;
        //その他口座番号や名前など
        //株を買う場合は、securityに追加して、量を追加するなど
        void buyStock() {
        }
};