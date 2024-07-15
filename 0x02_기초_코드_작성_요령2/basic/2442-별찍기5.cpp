#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for( int i = 0; i < n; i++){
        for(int k = 0; k < ((2*n-1)-(2*i+1))/2 ; k++){
            std::cout << " ";
        }
        for(int j = 0 ; j < (2*i+1); j++){
            std::cout << "*";
        }
        // for(int k = 0; k < ((2*n-1)-(2*i+1))/2 ; k++){
        //     std::cout << " ";
        // }
        std::cout << "\n";
    }
}