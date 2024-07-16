#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> v(N);

    for (int i = 0; i<N; i++){
        int n;
        std::cin >> n;
        v[i] = n;
    }
    int find;
    std::cin >> find;

    int cnt = 0;
    for(int i:v){
        if( i == find) cnt++;
    }
    std::cout << cnt;
}