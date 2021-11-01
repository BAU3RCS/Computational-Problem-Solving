#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool test(string testee){
    if ((testee.find('1')!=string::npos || testee.find('_')!=string::npos) && testee.find("222")==string::npos && testee.find("333")==string::npos){
        for(int i=0 ;i<size(testee);++i) if (testee[i]=='1') testee[i]='3';
        if(testee.find("333")==string::npos) {
            return true;
        }
    }
    return false;
}

long long scoring(string word, vector<int> scores){
    long long temp {1};
        for(auto iter=cbegin(scores);iter!=cend(scores);++iter){
            if(word[*iter]=='2') temp *= 5;
            else if (word[*iter]=='3') temp *= 20;
        }
        return temp;
}


long long recursion(string& word, vector<int>& scores){
    long long comb{0};
    int under = word.find('_');


    if(test(word) && word.find('_')==string::npos){
        return comb+=scoring(word,scores);
    }

    //
    word[under]='1';
    if(test(word)){
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
    vector<int> scores;
    string V = "AEIOU";

    // let 1 = l
    // let 2 = vowels
    // let 3 = consonants

    string word;
    cin >> word;

    int mult {1};


    //convert type to 1 2 3
    for(int i=0; i<word.size();i++){
        if(word[i]=='L') word[i] ='1';
        else if(word[i]=='_') scores.push_back(i);
        else if(V.find(word[i])!=string::npos) word[i]='2';
        else word[i]='3';
    }

    cout << recursion(word, scores)<< endl;
    //works on test cases :/
}