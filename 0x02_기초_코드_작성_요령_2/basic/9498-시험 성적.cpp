#include <iostream>
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    if (n >= 90 ) std::cout << "A";
    else if ( n >= 80) std::cout << "B";
    else if ( n >= 70) std::cout << "C";
    else if ( n >= 60) std::cout << "D";
    else std::cout << "F";
}