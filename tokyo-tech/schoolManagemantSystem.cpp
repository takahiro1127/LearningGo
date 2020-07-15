//20M14552
//上原隆寛
#include<iostream>
#include <algorithm>
using namespace std;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int personID;
class Lesson {
    public:
    private:
        int id;
        string name;
};
template<typename T, int registerClassCount, int teachingClassCount>
class Person {
    public:
        Person (int settingStatus, string settingName, T) {
            status = settingStatus;
            name = settingName;
            id = personID;
            personID++;
        };

        int calcSalary() {
            if (status == 1) {
                return teachingClasses.length() * 5000;
            } else if (status == 2) {
                return teachingClasses.length() * 10000;
            }
        };

        double calcWorkingHours() {
            if (status == 0) {
                return registerClasses.length() * 1.5;
            } else if (status == 1) {
                return (registerClasses.length() + teachingClasses.length()) * 1.5;
            } else {
                return teachingClasses.length() * 1.5;
            }
        };

        int countRegisterClassess() {
            return registerClasses.length();
        }

    private:
        int id;
        string name;
        //最大数を100と仮置き
        int status;
        //0学生, 1TA, 2 先生
        int classCount;
        Lesson teachingClasses[teachingClassCount];
        Lesson registerClasses[registerClassCount];
};

int calcTotalSalary(Person teachers[]) {
    int count = 0;
    rep(i, teachers.length()) count += teachers[i].calcSalary();
    return count;
}

int registerClassAverage(Person students[]) {
    int count = 0;
    rep(i, students.length()) count += students[i].countRegisterClassess();
    return coount / students.length();
}

