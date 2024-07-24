#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N,val;
    std::cin >> N;
    int* dq = new int[2*N+1];
    int head = N; int tail = N; 

    while(N--){
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push_back") {
            std::cin >> val;
            dq[tail++] = val;
        } else if (cmd == "push_front") {
            std::cin >> val ;
            dq[--head] = val;
        } else if ( cmd == "pop_front") {
            if( (tail-head) != 0) {
                std::cout << dq[head++] << "\n";
            } else std::cout << -1 << "\n";

        } else if (cmd == "pop_back") {
            if ( (tail-head) != 0) {
                std::cout << dq[--tail] << "\n";
            } else std::cout << -1 << "\n";

        } else if (cmd == "size") {
            std::cout << tail-head << "\n";
        } else if ( cmd == "empty") {
            if ((tail-head) != 0) std::cout << 0 << "\n";
            else std::cout << 1 << "\n";
        } else if ( cmd == "front") {
            if( (tail-head) != 0) {
                std::cout << dq[head] << "\n";
            } else std::cout << -1 << "\n";
        } else if ( cmd == "back") {
            if( (tail-head) != 0) {
                std::cout << dq[tail-1] << "\n";
            } else std::cout << -1 << "\n";
        }
    }
}