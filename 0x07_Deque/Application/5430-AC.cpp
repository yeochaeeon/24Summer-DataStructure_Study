#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    while(N--){
        std::string cmd,input,ans;
        std::deque<int> dq;
        int size ; char flag = 'f';
        std::cin >> cmd;
        std::cin >> size; 
        std::cin >> input;

        // 대괄호 제거
        input.erase(std::remove(input.begin(), input.end(), '['), input.end());
        input.erase(std::remove(input.begin(), input.end(), ']'), input.end());
        
        std::istringstream ss(input);
        std::string token;
    
        while (std::getline(ss, token, ',')) { // 쉼표를 기준으로 문자열 분리
            std::stringstream tokenStream(token);
            int number;
            if (tokenStream >> number) { // 문자열을 정수로 변환
                dq.push_back(number); // 정수를 덱에 추가
            }
        }
        for(char c:cmd){
            if (c == 'R') {
                if ( flag == 'b') flag = 'f';
                else if ( flag == 'f') flag = 'b';
            }
            else if ( c == 'D') { 
                if (dq.size() == 0) {
                    ans = "error";
                }
                else if ( flag == 'f') dq.pop_front(); 
                else if (flag == 'b') dq.pop_back();
            } 
        }
        if (ans == "error") {
            std::cout << "error\n" ;
        } else {
        // print answer
        std::cout << "[";
        int initSize = dq.size();
        if (flag == 'f' && initSize != 0) {
            for(int i = 0 ; i < initSize-1 ; i++){
                std::cout << dq.front() << ",";
                dq.pop_front();
            }
            std::cout << dq.front();
        }
        else if (flag == 'b'&& initSize != 0) {
            for(int i = 0 ; i < initSize-1 ; i++){
                std::cout << dq.back() << ",";
                dq.pop_back();
            }
            std::cout << dq.front();
        }
        std::cout << "]\n";
        }
    }
}
