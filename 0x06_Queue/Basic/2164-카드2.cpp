#include <iostream>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int N;
    std::cin >> N;

    int flag = 0;

    std::queue<int> Q;
    for ( int i = 1; i <= N; i++) {
        Q.push(i);
    }
    while (Q.size() != 1){
        if (flag == 0){
            Q.pop();
            flag = 1;
        }
        else {
            Q.push(Q.front());
            Q.pop();
            flag = 0;
        }
    }
    std::cout << Q.front() ;
}