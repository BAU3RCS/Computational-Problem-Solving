#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
//MULTISET

using namespace std;

//activity start and end
struct act{
    int start {0};
    int end {0};
};

bool compare(const act& a1, const act& a2){
    if (a1.end == a2.end) return a1.start > a2.start;
    else return a1.end < a2.end;  
}

//assumes the vector is sorted by starting time

int main(){
    //line one "activities classrooms"
    int acts, numc;
    cin >> acts >> numc;

    vector<act> times;
    int temp,tem;
    act acttemp;
    for(int i=0; i<acts;++i){
        cin >>temp >>tem;
        acttemp.start = temp;
        acttemp.end   = tem;
        times.push_back(acttemp);
    }

    sort(begin(times), end(times), compare);


    multiset<int> classes;


    for(int i=0; i<numc;++i){
        classes.insert(0);
    }

    int sol {0};


    for(auto itr=begin(times);itr!=end(times);++itr){
        cout << "\n";
        cout << "new act: " << itr->start << " " << itr->end << "\n";

        auto itr2 = classes.lower_bound(itr->start);

        if(itr2!=begin(classes)){
            --itr2;
            cout << "\n";
            cout << "insert" << endl;
            classes.erase(itr2);
            classes.insert(itr->end);
            ++sol;
        }

    }
    cout << sol << endl;
}