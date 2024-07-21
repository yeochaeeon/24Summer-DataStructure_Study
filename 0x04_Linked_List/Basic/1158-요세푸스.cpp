#include <iostream>
#include <list>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N,K;
    std::cin >> N >> K;
    std::list<int> init = {}; 
    for(int i = 1 ; i <= N; i++){init.push_back(i);}
    // for(int i:init) {
    //     std::cout << "init:"<< i << " ";
    // }
    std::list<int> l = {}; 
    // std::cout << "size:" << l.size();
    auto p = init.begin();

    while (l.size() != N) {
        for(int i = 0; i < K-1 ; i++){
            if ( p != init.end() ) p++;
            else { 
                p = init.begin(); 
                p++;
            }
        }
        if ( p == init.end() ) {
            p = init.begin();
            l.push_back(*p);
            p = init.erase(p);
        }
        else {
            l.push_back(*p);
            p = init.erase(p);
        }
    }
    auto it = l.begin();
    std::cout << "<";
    for (int i = 1 ; i <= N ; i++){
        if (i != N) std::cout << *it++ << ", ";
        else std::cout << *it << ">";
    }
}