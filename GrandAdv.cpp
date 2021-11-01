#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int games, win{1};
    string cg;
    cin >> games;

    
    for(int i=0;i<games;i++){
        stack<char> bag;
        win=1;
        cin >> cg;
    

        for(int j=0;j<cg.length();j++){
            if(cg[j]=='.'){
                continue;
            }
            else if(cg[j]=='$' ||cg[j]=='|' ||cg[j]=='*'){
                bag.push(cg[j]);
            }
            else if (!bag.empty() && ((cg[j]=='t'&& bag.top()=='|')||(cg[j]=='j' && bag.top()=='*')||(cg[j]=='b' && bag.top()=='$'))){
                bag.pop();
            }
            else{
                win=0;
                break;
            }

        }


        if(win!=1 || !bag.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
  }

}