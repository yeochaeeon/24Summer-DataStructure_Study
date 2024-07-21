#include <iostream>
#include <stack>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::stack<int> S;
    while (N--){
        int num;
        std::cin >> num;
        if (num != 0) S.push(num);
        else S.pop();
    }

    int sum = 0;
    while (!S.empty()){
        sum += S.top(); 
        S.pop();
    }
    // 최상단 값에만 접근 가능하기에 top,pop을 반복하는 법 이외에는
    // 방법이 없음 
    // 처음에는 늘 하던대로 for문을 돌려고 했지만 당연히 안됨.
    // stack은 최상단 값에만 접근이 가능한 구조임.
    std::cout << sum;
}