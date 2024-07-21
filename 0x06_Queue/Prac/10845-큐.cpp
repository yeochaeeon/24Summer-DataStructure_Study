#include <iostream>

const int max = 1000005;
int q[max];
int head = 0 ; int tail = 0;

void push(int n){
    q[tail++] = n;
}
void pop(){
    head++;
}
int size(){
    return tail-head;
}
void front(){
    if (size() != 0) {
        std::cout << q[head] << "\n";
    }
    else std::cout << -1 << "\n";
}
void back(){
    if (size() != 0) {
        std::cout << q[tail-1] << "\n";
    }
    else std::cout << -1 << "\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    while (N--){
        std::string s; 
        std::cin >> s;
        int n;
        if ( s == "push") {
            std::cin >> n;
            push(n);
        }
        else if ( s == "pop") {
            if (size() != 0) {
                std::cout << q[head] << "\n";
                pop();
            }
            else std::cout << -1 << "\n"; 
        }
        else if ( s == "front") {
            front();
        }
        else if( s == "back") {
            back();
        }
        else if ( s == "size") {
            std::cout << size() << "\n";
        }
        else if (s == "empty") {
            size() == 0 ? std::cout <<"1\n" : std::cout << "0\n";
        }
    }
}