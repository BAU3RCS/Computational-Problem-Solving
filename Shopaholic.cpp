#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long items;
    cin >> items;

    vector<long long> cart;

    for (int i=0; i<items; i++){
        long long c;
        cin >>c;
        cart.push_back(c);
    }

    sort(cart.begin(),cart.end(),greater<long long>());

    long long sum {0};
    for(int i=2; i<=items; i+=3) sum += cart[i];

    cout << sum << endl;
}