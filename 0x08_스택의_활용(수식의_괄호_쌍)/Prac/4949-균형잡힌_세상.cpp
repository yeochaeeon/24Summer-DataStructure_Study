#include <iostream>
#include <string>
#include <stack>

int main(){
    std::stack<char> s;
    std::string str,ans;
    while ( std::getline(std::cin,str)) {
        if ( str == ".") break; 
        for(char c:str){
            if ( c == '[' || c == '{' ) {
                s.push(c);
            }
            else if (c == ']' )  {
                if ( s.top() == '[') s.pop();
                else {ans = "no";}
            }
            else if ( c == '}') {
                if ( s.top() == '{') s.pop();
            }
        }
    }
}