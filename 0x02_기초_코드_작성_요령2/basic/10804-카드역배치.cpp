#include <iostream>
#include <vector>
int main(){
    std::vector<int> v(20);
    for(int i = 0; i<20;i++){
        v[i] = i+1;
    }

    int idxStart[10],idxLast[10];
    for (int i = 0; i < 10 ; i++){
        std::cin >> idxStart[i] >> idxLast[i];
        idxStart[i] = idxStart[i] - 1;
        idxLast[i] = idxLast[i] - 1;
    }

    for (int i = 0; i < 10; i++){
        int i2 = i;
        int diff = idxLast[i2] - ( idxStart[i] - 1 );
        int n = diff/2; // 몇 번 swap할건지
        for (int j = 0 ; j < n ; j ++){ // n번 swap
            int tmp = v[idxLast[i]];
            v[idxLast[i]] = v[idxStart[i]];
            v[idxStart[i]] = tmp;
            idxLast[i]--; idxStart[i]++;
        }
    }
    for(int i:v){ std::cout << i << " ";}

}