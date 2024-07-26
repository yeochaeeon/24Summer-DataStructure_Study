#include <iostream>
#include <string>
#include <stack>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    
    std::stack<char> s;
    std::string str, ans;
    while (std::getline(std::cin, str)) {
        if (str == ".") break;
        bool balanced = true;  // 스택의 균형을 확인하는 플래그
        for(char c : str){
            if (c == '[' || c == '{' || c == '(') {
                s.push(c);
            }
            else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
            else if (c == '}') {
                if (!s.empty() && s.top() == '{') {
                    s.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
            else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
        }
        
        // 스택이 비어 있고 플래그가 true면 균형잡힌 괄호, 아니면 그렇지 않음
        if (balanced && s.empty()) {
            ans = "yes\n";
        } else {
            ans = "no\n";
        }

        // 결과 출력
        std::cout << ans;
        
        // 다음 입력을 위해 스택 초기화
        while (!s.empty()) s.pop();
    }
    return 0;
}
