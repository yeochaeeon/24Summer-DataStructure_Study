#include <iostream>
#include <stack>

int main(){
    std::stack<char> s;
    std::string str; char c; int ans = 0 ; int stick = 0;  
    std::cin >> str;
    for(char c:str) {
        if (c == '(') { // 열리는 괄호면 일단 push
            s.push(c);
            stick++; 
        } else { // 닫히는 괄호 
            if ( s.top() == '(') { // 레이저
                s.push(c);
                stick--; 
                ans = ans + stick ; 
            } 
            else { // 닫히는 괄호
                s.push(c);
                stick--;
                ans++; 
            }
        }
    }
    std::cout << ans;

}