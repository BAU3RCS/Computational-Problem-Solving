#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool test(string testee){
    if (testee.find('1')!=string::npos && testee.find("222")==string::npos && testee.find("333")==string::npos){
        for(int i=0 ;i<size(testee);++i) if (testee[i]=='1') testee[i]='3';
            if(testee.find("333")==string::npos) {
                return true;
        }
    }
    return false;
}

long long recur(string& word) {
    if(word.find('_')==string::npos){
        return test(word) ? 1 : 0;
    }
    else{ 
        long long sum {0};
        int under = word.find('_');
        word[under] = '1';
        sum+=recur(word);
        word[under] = '2';
        sum+=5*recur(word);
        word[under] = '3';
        sum+=20*recur(word);
        word[under] = '_';
        return sum;
    }
}

/*
long long recur(string& word) {
    if there are no _, return 1 if the word is nice, 0 if not

    otherwise, find the leftmost _.
    fill it in with a 1, call recur on it.  Multiply the result by 1
    fill it in with a 2, call recur on it. Multiply the result by 5
    fill it in with a 3, call recur on it. Multiply the result by 20
    sum those three results.
    restore the _
    return sum
}
*/


int main(){
    vector<int> scores;
    string V = "AEIOU";

    // let 1 = l
    // let 2 = vowels
    // let 3 = consonants

    string word;
    cin >> word;


    //convert type to 1 2 3
    for(int i=0; i<word.size();i++){
        if(word[i]=='L') word[i] ='1';
        else if(word[i]=='_') scores.push_back(i);
        else if(V.find(word[i])!=string::npos) word[i]='2';
        else word[i]='3';
    }

    cout << recur(word)<< endl;
    //works on test cases :/
}