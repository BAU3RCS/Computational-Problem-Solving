#include <iostream>
#include <vector>
#include <stack>

//sorting
//#include <algorithm>

using namespace std;


int main(){
int sz=0;
vector<int> cards;

cin >> sz;
for (int i=0; i<sz; i++){
    int c;
    cin >>c;
    cards.push_back(c);
    }

    //sort(cards.begin(), cards.end(), [](int a, int b) {return a > b;}); add lambda for comparison --> [](){}
    // some lambda are predfined such as greater<int>

    // array/vector operations: find(cards.begin(), cards.end(), [](auto a){return a < 42;}), 

    stack<int> stk;
    for (auto c : cards){
        if (stk.empty() || ((c + stk.top()) % 2) != 0){
            stk.push(c);
        }
        else{
            stk.pop();
        }

    }

    cout << stk.size() << endl;
}