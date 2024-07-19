#include <iostream>
#include <list>

int main(){
    // std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::list<char> l;
    char c; 
    std::list<char>::iterator cursor;
    std::string str; std::cin >> str; 
    for(char c:str){
        l.push_back(c);
    }
    cursor = l.end();
    int n; std::cin >> n;

    for (int i = 0 ; i < n; i++){
        char choice;
        std::cin >> choice;

        if (choice == 'L') {
            if (cursor != l.begin()) cursor--;
        }
        else if (choice == 'D') {
            if (cursor != l.end()) cursor++;
        }
        else if (choice == 'B') {
            if (cursor != l.begin()){
                // auto delIt = --cursor;
                cursor = l.erase(--cursor); 
                // erase함수를 쓸 때에는 반환 값을 꼭 사용해주어야
            }
        }
        else if (choice == 'P'){
            char newChar;
            std::cin >> newChar;
            l.insert(cursor,newChar);
        }
    }
    for (char c:l){
        std::cout << c;
    }
}