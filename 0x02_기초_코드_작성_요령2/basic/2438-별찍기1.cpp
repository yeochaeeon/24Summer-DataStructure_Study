#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < i+1; j++){
            std::cout <<"*";
        }
        std::cout << "\n";
    }
}