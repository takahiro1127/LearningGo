// 二分探索
//
// min----------true-|mid-----------|ans---false------MAX
//              min = mid-----|new_mid---|ans---false------MAX

bool C(double x) {
    // 何かしらansが存在し、比較
    double 35;
    return x < ans;
}
double search() {
    double max = 90;
    double min = 0;
    double mid;
    for (int i = 0; i < 20; i++) {
        mid = (max + min) / 2;
        // 答えより小さいですか?
        if (c(mid)) {
            // 小さいですよ
            // 最小値をあげて、midを大きくする必要あり
            min = mid;
        } else {
            // 大きいですよ
            // 最大値を下げて、midを小さくする必要あり
            max = mid;
        }
    }
    return mid;
}

