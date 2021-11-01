#include <iostream>

int main(){
int n1 {0}, n2 {0}, n3 {0};
std::cin >> n1 >> n2 >> n3;
int m1 {0}, m2{0};
m1 = std::max(n1-n2,n2);
m2 = std::max(n1-n3,n3);
std::cout << 4*m1*m2 <<std::endl;
}