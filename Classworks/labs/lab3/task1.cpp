#include<iostream>
using namespace std;

class Counter{
	private: 
		int count;
        int step = 1;
	public: 
        void setIncrementStep(int step_val){
            step = step_val;
        }
		void resetCount(){
			count = 0;
		}
		void increment(){
			count += step;
		}
		int getCount(){
			return count;
		}
};

int main(){
    Counter c1;
    c1.resetCount();
    cout << c1.getCount()<< endl;
    c1.setIncrementStep(5);
    cout << c1.getCount() << endl;
    c1.increment();
    cout << c1.getCount() << endl;
    return 0;
}