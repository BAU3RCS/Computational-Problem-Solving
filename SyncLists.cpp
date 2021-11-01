#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    int len {0};
    cin >> len;

    while (true){

        int list1[len];
        int master[len];
        int list2[len];

        for(int i =0; i<len;i++){
            int c;
            cin >> c;
            master[i] = c;
            list1[i] = c;
        }

        for(int i =0; i<len;i++){
            int c;
            cin >> c;
            list2[i] = c;
        }

        sort(list1,list1+len);
        sort(list2,list2+len);

        map<int, int> mapkey;

        for(int i =0; i<len;i++){
            mapkey.insert(pair<int, int>(list1[i], list2[i]));
        }

        for(int i=0; i<len;i++){
            cout << mapkey[master[i]] << endl;
        }

        cin >> len;

        if(len==0) break;
        else cout << "\n";
    }

}