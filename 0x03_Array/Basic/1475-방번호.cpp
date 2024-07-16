#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string str = std::to_string(n);
    // std::cout << "##" << str << "\n";
    for(char& s:str){
        if( s == '9') s = '6'; 
    }
    // std::cout << "##" << str << "\n";
    std::vector<int> v(9);
    for(char s:str){
        v[s-'0']++;
    }
    // std::cout << v[6] <<"\n";
    v[6] = v[6]/2 + v[6]%2; // 6
    // std::cout << v[6] << "\n";
    int result = *max_element(v.begin(),v.end());
    std::cout << result;

}