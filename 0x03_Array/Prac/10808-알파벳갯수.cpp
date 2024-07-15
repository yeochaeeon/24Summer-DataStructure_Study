#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;

    for(char c = 'a'; c <='z' ; c++){
        int count = 0;
        for(char s:str){
            if(c == s) count++;
        }
        std::cout << count << " ";
    }
}