#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);;
    std::cin.tie(0);

    std::vector<int> v(9);
    for(int i = 0; i < 9; i++){ //입력받을 때는 범위기반 for문 쓰는거 ㄴㄴ
        std::cin >> v[i];
    }
    // iterator가 반환값인 stl 함수에서 index를 취하는 법
    int idx = max_element(v.begin(),v.end()) - v.begin();
    int max = v[idx];
    // int max = *(max_element(v.begin(),v.end()));
    // int idx = std::find(v.begin(),v.end(),max) - v.begin();
    std::cout << max ;
    std::cout <<"\n"<< idx + 1;
}