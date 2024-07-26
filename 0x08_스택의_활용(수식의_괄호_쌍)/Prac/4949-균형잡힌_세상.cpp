#include <iostream>
#include <string>
#include <stack>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    
    std::stack<char> s;
    std::string str,ans;
    while ( std::getline(std::cin,str) ) {
        if ( str == ".") break; 
        for(char c:str){
            if ( c == '[' || c == '{' || c == '(') {
                s.push(c);
            }
            else if ( c == ']' )  {
                if ( s.size() != 0 && s.top() == '[') s.pop();
                else {
                    ans = "no\n";
                    break;
                }
            }
            else if ( c == '}') {
                if ( s.size() != 0 && s.top() == '{') {
                    s.pop();
                }
                else {
                    ans = "no\n";
                    break;
                }
            }
            else if ( c == ')') {
                if (  s.size() != 0 && s.top() == '(') {
                    s.pop();
                }
                else {
                    ans = "no\n";
                    break;
                }
            }
            if (s.size() == 0) ans = "yes\n";
            else ans = "no\n";
        }
        std::cout << ans ;
        while(!s.empty()) s.pop();
    } 
    return 0;
}