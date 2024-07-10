// 3. N이 제곱수이면 1을, 제곱수가 아니면 0을 반환하는 함수를 작성하라
// N은 10억 이하의 자연수이다.

#include <iostream>
int func3(int N){
    for (int i = 0 ; i * i <= N ; i++){
        if ((i*i == N)) return 1;
    }    
    return 0;
    // 시간복잡도 : 루트 N. O(N^(1/2))
}

int main(){
    std::cout << func3(9) << std::endl; // 출력: 1
    std::cout << func3(693953651) << std::endl; // 출력: 0
}
