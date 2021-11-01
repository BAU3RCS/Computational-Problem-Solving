#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <set>

using namespace std;

bool test(string testee){
    if ((testee.find('1')!=string::npos || testee.find('_')!=string::npos) && testee.find("222")==string::npos && testee.find("333")==string::npos){
        for(int i=0 ;i<size(testee);++i) if (testee[i]=='1') testee[i]='3';
        if(testee.find("333")==string::npos) {
            cout << "Good combination found with " << testee << endl;
            return true;
        }
    }
    return false;
}

int scoring(string word, vector<int> scores){
    int temp {1};
        for(auto iter=cbegin(scores);iter!=cend(scores);++iter){
            if(word[*iter]=='2') temp *= 5;
            else if (word[*iter]=='3') temp *= 20;
        }
        return temp;
}

int recursion(string word, vector<int> scores){
    int comb{0};
    int under = word.find('_');

    cout << "on underscore" << under << endl;

    if(test(word) && word.find('_')==string::npos){
        cout << "returning score" << endl;
        cout << scoring(word,scores) << endl;
        return comb+=scoring(word,scores);
    }

    //
    word[under]='1';
    if(test(word)){
        cout << "recurring" << endl;
        comb+=recursion(word,scores);
    }
    
    //
    word[under]='2';
    if(test(word))
        comb+=recursion(word,scores);

    //
    word[under]='3';
        if(test(word) && word.find('_')!=string::npos)
            comb+=recursion(word,scores);

        else if(test(word)){
            return comb+=scoring(word,scores);
            }

if(test(word) && word.find('_')==string::npos){
            return comb+=scoring(word,scores);
    }
    
    return comb;
}

int main(){
    string str ="";
    vector<int> u {1};


    cout << recursion(str,u) << endl;
}