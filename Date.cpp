#include "Date.h"

Date::Date() {
    setDate(0 , 0 , 0);
}

Date::~Date() {

}

void Date::gregorianToJalali(int *j_y, int *j_m, int *j_d, int g_y, int g_m, int g_d) {
    int g_days_in_month[12] = {31 , 28 , 31 , 30 , 31 , 30 ,
                               31 , 31 , 30 , 31 , 30 , 31};
    int j_days_in_month[12] = {31 , 31, 31 , 31 , 31 , 31 ,
                               30 , 30 , 30 ,30 , 30 , 29};
    int gy , gm , gd;
    int jy , jm , jd;
    long g_day_no , j_day_no;
    int j_np;
    int i;
    gy = g_y - 1600;
    gm = g_m - 1 ;
    gd = g_d - 1;

    g_day_no = 365 * gy + (gy+3) / 4 - (gy+99) / 100 + (gy+399) / 400;
    for (i = 0 ; i< gm ; ++i){
        g_day_no += g_days_in_month[i];
    }

    if (gm > 1 && ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)))
        ++g_day_no;
    g_day_no += gd;

    j_day_no = g_day_no - 79;
    j_np = j_day_no / 12053;
    j_day_no %= 12053;

    jy = 979 + 33 * j_np + 4 * (j_day_no / 1461);
    j_day_no %= 1461;
    if (j_day_no >= 366) {
        jy += (j_day_no - 1) / 365;
        j_day_no = (j_day_no - 1) % 365;
    }

    for (i = 0;  i<11 && j_day_no>= j_days_in_month[i] ; ++i) {
        j_day_no -= j_days_in_month[i];
    }
    jm = i+1;
    jd = j_day_no + 1;
    *j_y = jy;
    *j_m = jm;
    *j_d = jd;
}

void Date::setDate(int year, int month , int day) {
    this -> year = year;
    this -> month = month;
    this -> day = day;
}

int Date::getDate(string type) {
    if (type == "year") {
        return year;
    } else if (type == "month") {
        return month;
    } else if (type == "day") {
        return day;
    } else {
        cout<<endl<<"ERROR : No Match Argument ...!"<<endl;
    }
}

int Date::getAutoDate(string type) {
    time_t bin_time;
    struct tm *br_time;

    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorianToJalali(&y , &m , &d , 1900 + br_time ->tm_year ,
                      1+ br_time->tm_mon ,
                      br_time-> tm_mday);
    if (type == "year") {
        return year;
    } else if (type == "month") {
        return month;
    } else if (type == "day") {
        return day;
    } else {
        cout<<endl<<"ERROR : No Match Argument ...!"<<endl;
    }
}

void Date::display() {
    const char *j_month_name[13] = {"" , "Farvardin" , "Ordibehesht" , "Khordad" ,
                                    "Tir" , "Mordad" , "Shahrivar" , "Mehr" ,
                                    "Aban" , "Azar" , "Dey" , "Bahman" , "Esfand"
    };
    cout << year << "/" << j_month_name[month] << "/" << day;
}

void Date::displayAutoDate() {
    time_t bin_time;
    struct tm *br_time;
    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorianToJalali(&y , &m , &d , 1900 + br_time-> tm_year ,
                      1 + br_time -> tm_mon,
                      br_time-> tm_mday);
    const char *j_month_name[13] = {"" , "Farvardin" , "Ordibehesht" , "Khordad" ,
                                    "Tir" , "Mordad" , "Shahrivar" , "Mehr" ,
                                    "Aban" , "Azar" , "Dey" , "Bahman" , "Esfand"};
    cout << year << "/" << j_month_name[m] << "/" << day;
}