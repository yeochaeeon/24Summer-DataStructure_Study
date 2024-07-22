#include <iostream>
#include <stack>
#include <vector>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N; 
    std::queue<int> q;
    for (int i = 0; i < N ; i++){
        int tmp;
        std::cin >> tmp;
        q.push(tmp);
    }
    std::stack<int> s; 
    std::vector<int> v; 
    std::vector<char> pp;
    int flag = 1;
    while(v.size() != N){
        if(s.empty()) { 
            s.push(flag++); pp.push_back('+'); 
        }
        while(q.front() != s.top()) {
            if (q.front() < s.top()) {
                std::cout << "NO" ; 
                return 0;
            }
            s.push(flag++); 
            pp.push_back('+'); 
        }
        v.push_back(s.top());
        s.pop();
        pp.push_back('-'); 
        q.pop();
    }
    for(char c:pp){
        std::cout << c << "\n";
    }

}