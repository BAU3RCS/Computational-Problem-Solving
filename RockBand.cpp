#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int bm, ss;
    cin >> bm >> ss;

    //
    int songs[ss*bm];
    for(int i=0;i<ss*bm;i++){
        int loader;
        cin >> loader;
        songs[i]=loader;
    }


    //
    vector<int> pd;
    set<int> com;
    int i {0};

    while(true){
        for(int j=0;j<bm;j++){
           pd.push_back(songs[i+ss*j]);
           com.insert(songs[i+ss*j]);
        }
        i++;
        if(size(com)*bm==size(pd)) break;
   }

    //Printing
    cout << i << endl;
    for(auto a : com){
        cout << a << " ";
    }

    cout << endl;

}