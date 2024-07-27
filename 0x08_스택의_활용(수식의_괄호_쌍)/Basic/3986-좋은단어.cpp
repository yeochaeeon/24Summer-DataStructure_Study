#include <iostream>
#include <stack>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n , cnt = 0 ; 
    std::cin >> n;
    std::string str;
    
    while(n--){
        std::stack<char> s; // while 돌 때 마다 스택 초기화 해줘야 함
        std::cin >> str;
        for(char c:str){
            if (s.size() == 0 ) s.push(c) ;
            else if (s.top() == c) s.pop();
            else s.push(c);
        }
        if (s.empty()) cnt++;
    }
    std::cout << cnt;
}