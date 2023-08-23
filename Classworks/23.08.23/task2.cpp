#include<iostream>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        int hours(){
            return hour;
        }
        int minutes(){
            return minute;
        }
        int seconds(){
            return second;
        }
        void reset(int h, int m, int s){
            second = s;     
            minute = m;
            hour = h;
            timeChecker();
        }
        void advance(int h, int m, int s){
            second += s;
            minute += m;
            hour += h;
            timeChecker();
        }
        void print (){
            cout <<  hour << " Hours, "<< minute << " Minutes, " << second <<" Seconds"<< endl;
        }
        void timeChecker(){
            if (second>59){
                minute += second/60;
                second = second%60;
            }
            if (minute>59){
                hour += minute/60;
                minute %=60;
            }
            if(hour>23) hour = hour%24;
        }

};

int main(){
    Time t1;
    t1.reset(11,28,30);
    t1.print();
    t1.advance(1,40,60);
    t1.print();
    cout << t1.hours() << ' ' << t1.minutes() << ' ' << t1.seconds() << endl;
    return 0;
}