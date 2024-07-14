#include <iostream>

int main (){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int t = 0; t < 3 ; t++) {
        int arr[4] ={0};
        for( int i = 0; i<4 ; i++){
            int a;
            std::cin >> a;
            arr[i] = a;
        }
        int cnt = 0;
        for (int i = 0 ; i < 4 ; i++){
            if (arr[i] == 0) cnt++;
        }
        if (cnt == 1) std::cout << "A\n";
        else if (cnt == 2 ) std::cout << "B\n";
        else if (cnt == 3 ) std::cout << "C\n";
        else if (cnt == 4) std::cout << "D\n";
        else std::cout<< "E\n";
    }
}