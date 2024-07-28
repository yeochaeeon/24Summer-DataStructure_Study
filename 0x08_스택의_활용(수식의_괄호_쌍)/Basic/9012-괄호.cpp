#include <iostream>
#include <stack>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    while(n--){
        std::stack<char> s;
        std::string str;
        std::cin >> str;
        for(char c:str){
            if (c == '(') {
                s.push(c);
            } else {
                if ( !s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    s.push(c);
                }
            }
        }
        if (s.empty()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}