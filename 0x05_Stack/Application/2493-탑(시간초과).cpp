#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;

    std::vector<int> v(N);
    std::vector<int> result(N,0);
    for(int i = 0; i < N; i++){
        int tmp;
        std::cin >> tmp;
        v[i] = tmp;
    }
    for(int i = 1 ; i < N ; i++){
        for( int j = 0 ; j < i; j++){
            if (v[i] < v[j]) result[i] = j+1;
        }
    }
    for(int i:result){
        std::cout << i << " ";
    }
}