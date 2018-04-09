//
// Created by Zheng Yuanoung on 2018/4/9.
//  能被4整除且不能被100整除的为闰年 or 被400整除的是闰年
#include <iostream>

using namespace std;
int data[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year, month, day, allDay;
    char _;
    while (cin >> year >> _ >> month >> _ >> day) {
        allDay = 0;
        for (int i = 1; i < month; i++)
            allDay += data[i];

        if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
            allDay = allDay + 1 + day;
        else
            allDay += day;

        cout << allDay << endl;
    }

    return 0;
}