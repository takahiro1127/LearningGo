template<typename T>
inline void callWithMax(cojnst T& a, const T& b) {
    f(a > b ? a : b)
}

char greeting[] = "Hello";
char *p = greeting;
// データもポインタも非const

const char *p = greeting;
// データはconst, ポインタは非const

char *const p = greeting;
// ポインタはconst, データは非const

const char *const p = greeting;
//　データもポインタもconst

// constが*より右にある場合はポインタがconst
// constが*より左にある場合はデータがconst

// 初期化子リスト
class ABEntry{
    public:
        ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones);
    private:
        std::string theName;
        std::string theAddress;
        std::list<PhoneNumber> thePhones;
        int numTimesConsulted;
}

ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones)
: theName(name),
theAddress(address),
thePhones(phones),
numTimesConsulted(0)
{}

// 5章メモ
