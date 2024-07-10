// 1. 입력받은 수보다 작은 수 중 3의 배수나 5의 배수를 모두 더해 출력하자.

#include <iostream>

int main(){
    int input;
    std::cin >> input;
    int total = 0;
    for (int i = 1 ; i < input ; i++) {
        if (i % 5 == 0 || i % 3 == 0) {
            total = total + i;
        }
    }
    std::cout << total;
}