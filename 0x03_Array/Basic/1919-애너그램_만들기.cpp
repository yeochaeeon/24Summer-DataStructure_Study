#include <iostream>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::string str1,str2;
    std::cin >> str1 >> str2 ;

    int occur = 0;
    for (char c:str1){
        for (char& cc:str2){
            // if (cc == '1') continue;
            if (c == cc) { 
                cc = '1'; break;
            }
        }
        std::cout << str2 << "\n";
    }
    for (char c:str2){
        if (c == '1') occur++;
    }
    std::cout << (str2.length()-occur)*2;
}