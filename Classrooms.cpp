#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//splits words on space
vector<string> split(const string& timesc){
    int i = timesc.find(' ');
    vector<string> times;
    times.push_back(timesc.substr(0,i));
    times.push_back(timesc.substr(i+1));
    return times;
}

//assumes the vector is sorted by starting time
vector<string> timecheck(const vector<string>& vec){
    vector<string> vec1;
    string m,t;
    int i=0;
    t=split(vec[0])[1];

    while(++i<size(vec)){
        vector<string> current =split(vec[i]);
        m=current[0];
        //cout << i <<m << t << endl;

        if(m<=t){
            vec1.push_back(vec[i]);
            //cout << "hello" << endl;
        }
        else{
            t=current[1];
        }
    }   
    return vec1;
}

int main(){
    //line one "activities classrooms"
    long long acts, numc;
    cin >> acts >> numc;

    vector<string> times;
    string temp1,temp2;
    for(int i=0; i<acts;++i){
        cin >> temp1 >> temp2;
        times.push_back(temp1+" "+temp2);
    }

    vector<string> ctimes;
    //cout<< size(times) <<endl;

    sort(begin(times), end(times));

    //cout << times[0][0] << times[1][0] << endl;

    for(int i=0;i<numc;++i){
        if(size(times)==0) break;
        ctimes=timecheck(times);
        times=ctimes;
        //cout << "loop" << endl;
    }
    cout << acts-size(times) << endl;

    //cout << size(timecheck(times)) << endl;
}