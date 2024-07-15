#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for(int i = 0 ; i < n; i++ ){
        for(int j = n-i; j > 1 ; j--){
            std::cout << " ";
        }
        for(int k = 0 ; k < i+1; k++){
            std::cout << "*" ;
        }
        std::cout << "\n";
    }
}