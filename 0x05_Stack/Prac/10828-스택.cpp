#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    int* stack = new int[N];
    int pos = 0;
    while(N--){
        std::string func;
        std::cin >> func;
        if (func == "push") {
            int n = 0 ; std::cin >> n;
            stack[pos++] = n;
        }
        else if (func == "top") {
            if ( pos != 0 ) std::cout << stack[pos-1] <<"\n";
            else std::cout << -1 << "\n";
        }
        else if (func == "size") {
            std::cout << pos << "\n";
        }
        else if (func == "pop") {
            if ( pos != 0 ) std::cout << stack[(pos--)-1] << "\n"; 
            else std::cout << -1 << "\n";
        }
        else if (func == "empty") {
            pos==0 ? std::cout << 1 <<"\n": std::cout << 0 <<"\n";
        }
    }
}