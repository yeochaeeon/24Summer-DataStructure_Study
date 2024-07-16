#include <iostream>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;

    for(int i = 0 ; i<N; i++){
        std::string a,b;
        std::cin >> a >> b;
        std::sort(a.begin(),a.end());
        std::sort(b.begin(),b.end());

        if (a == b) std::cout << "Possible\n";
        else std::cout << "Impossible\n";
    }
}