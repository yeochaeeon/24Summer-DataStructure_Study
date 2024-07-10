// 4. N이하의 수 중에서 가장 큰 2의 거듭제곱 수를 반환하는 함수
// func4(int N)을 작성하라.
// N은 10억 이하의 자연수이다.
#include <iostream>

int func4(int n){
    int a = 1;
    while(2*a <= n ) a*=2;
    return a;
}