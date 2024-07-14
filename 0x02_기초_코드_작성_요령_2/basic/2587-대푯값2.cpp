#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    for(int i = 0 ; i < 5 ; i++){
        int n;
        std::cin >> n ;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    int mean;
    int sum = std::accumulate(v.begin(),v.end(),0);
    mean = sum / 5;
    int middle = v[2];
    std::cout << mean << " " << middle ;
}