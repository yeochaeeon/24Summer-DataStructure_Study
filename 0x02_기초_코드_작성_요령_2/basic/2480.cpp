#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> v;
    for(int i = 0; i < 3; i++){
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    int money;
    sort(v.begin(),v.end());
    
    if (v[0] == v[2]) money = 10000+ v[0]*1000;
    else if (v[0] == v[1]) money = 1000+v[0]*100;
    else if (v[1] == v[2]) money = 1000+v[1]*100;
    else money = v[2] * 100;

    std::cout << money;
}