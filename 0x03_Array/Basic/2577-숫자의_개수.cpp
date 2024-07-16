#include <iostream>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a,b,c;
    std::cin >> a >> b >> c ;
    int result = a*b*c;

    int arr[10] = {0};
    std::string str = std::to_string(result);
    // std::cout << str <<"\n" ;
    for(char c:str){
        arr[c-'0']++;
    }
    // std::cout << arr[0] << "\n";
    for(int i:arr){
        std::cout << i << "\n";
    }
}