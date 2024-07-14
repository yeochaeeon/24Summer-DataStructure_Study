#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long n1,n2;
    std::cin >> n1 >> n2;
    if (( n1 == n2 )){
        std::cout << 0;
        return 0;
    }
    if ( n1 > n2 ) {
        unsigned long long tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    int diff = n2 - n1 - 1;
    std::cout << diff << "\n";
    if (diff <= 1) return 0;
    for (unsigned long long i = n1+1; i < n2; i++){
        std::cout << i << " " ;
    }
}