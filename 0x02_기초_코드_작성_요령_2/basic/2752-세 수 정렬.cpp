#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[3];
    std::cin >> a[0]>> a[1] >> a[2] ;
    std::vector<int> v;
    for (int i = 0 ; i<3; i++){
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());

    for(int i:v){
        std::cout << i << " ";
    }
}