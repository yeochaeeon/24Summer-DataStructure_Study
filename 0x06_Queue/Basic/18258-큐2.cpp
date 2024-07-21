#include <iostream>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::queue<int> Q;
    int n;
    std::cin >> n;
    while (n--){
        std::string s;
        std::cin >> s;
        int val;
        if (s == "push") {
            std::cin >> val;
            Q.push(val);
        }
        else if ( s == "pop") {
            if( !Q.empty()) {
                std::cout << Q.front() << "\n";
                Q.pop();
            }
            else std::cout << "-1\n" ;
        }
        else if ( s == "size") {
            std::cout << Q.size() << "\n";
        }
        else if (s == "empty") {
            std::cout << Q.empty() << "\n";
        }
        else if (s=="front") {
            if( !Q.empty()) {
                std::cout << Q.front() << "\n";
            }
            else std::cout << "-1\n" ;
        }
        else if (s=="back") {
            if( !Q.empty()) {
                std::cout << Q.back() << "\n";
            }
            else std::cout << "-1\n" ;
        }
    }
}