#include "Time.h"
#include <time.h>

using namespace std;

Time::Time() {
    setTime(0 , 0 , 0);
}

Time::~Time() {

}

void Time::setTime(int hour, int minute, int second) {
    this-> hour = hour;
    this-> minute = minute;
    this-> second = second;
}

int Time::getTime(string type) {
    if (type == "hour") {
        return hour;
    } else if (type == "minute") {
        return minute;
    } else if (type == "second") {
        return second;
    } else {
        cout<<endl<<"ERROR : No Match Argument ...!"<<endl;
    }
}

int Time::getAutoTime(string type) {
    time_t bin_time;
    struct tm *br_time;

    time(&bin_time);
    br_time = localtime(&bin_time);

    h = br_time -> tm_hour;
    m = br_time -> tm_min;
    s = br_time -> tm_sec;

    if (type == "hour") {
        return h;
    } else if (type == "minute") {
        return m;
    } else if (type == "second") {
        return s;
    } else {
        cout<<endl<<"ERROR : No Match Argument ...!"<<endl;
    }
}

void Time::display() {
    cout<< hour << ":" << minute << ":" << second;
}

/*void Time::displayAutoTime() {
    time_t bin_time;
    struct tm *br_time;

    time(&bin_time);
    br_time = localtime(&bin_time);

    h = br_time -> tm_h;
    m = br_time -> tm_m;
    s = br_time -> tm_s;

    cout<< h << ":" << m << ":" << s;
} */