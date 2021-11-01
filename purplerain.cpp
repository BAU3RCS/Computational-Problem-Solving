#include <iostream>
#include <string>

using namespace std;

int main(){
    string RB;
    cin >> RB;

    int R,B;
    int Rsi{1}, Rei{0}, Rbsum{0}, Rcsum{0};
    int Bsi{1}, Bei{0}, Bbsum{0}, Bcsum{0};


    for(int i = 0; i<size(RB); ++i){

        //sets R and B For current
        R = (RB[i]=='R')? 1 : (-1);
        B = (RB[i]=='B')? 1 : (-1);
 
       // For vector R

       if((Rcsum+=R)==-1){
            Rcsum = 0;
            Rsi = i+2;
       } 

       if(Rcsum > Rbsum){
           Rbsum = Rcsum;
           Rei = i+1;
       }

       // For vector B

       if((Bcsum+=B)==-1){
            Bcsum = 0;
            Bsi = i+2;
       } 

       if(Bcsum > Bbsum){
           Bbsum = Bcsum;
           Bei = i+1;
       }

        /*
        cout << "start/end Blue " << Bsi << " " << Bei << endl;
        cout << "start/end Red " << Rsi << " " << Rei << endl;
        cout << "bmax/rmax " << Bbsum << " " << Rbsum << endl;
        cout << endl;
        */

    }

         if(Rbsum > Bbsum)  cout << Rsi << " " << Rei << endl;
    else if(Rbsum < Bbsum)  cout << Bsi << " " << Bei << endl;
    else if(Rsi < Bsi)      cout << Rsi << " " << Rei << endl;
    else if(Bsi > Rsi)      cout << Bsi << " " << Bei << endl;
    else if(Rei < Bei)      cout << Rsi << " " << Rei << endl;
    else                    cout << Bsi << " " << Bei << endl;               

}