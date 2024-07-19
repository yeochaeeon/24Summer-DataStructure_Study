#include <iostream>
#include <list>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n ;
    std::cin >> n;
    
    while(n--){
        std::list<char> pw = {};
        auto cursor = pw.begin();
        
        std::string str;
        std::cin >> str;
        for(char c:str){
            if ( c == '<'){
                if(cursor != pw.begin()){
                    cursor--;
                }
            }
            else if (c == '>'){
                if(cursor != pw.end()){
                    cursor++;
                }
            }
            else if (c == '-'){
                if(cursor != pw.begin()){
                    cursor = pw.erase(--cursor);
                }
            }
            else {
                pw.insert(cursor,c);
                // cursor++;
            }
        }
        for(char c:pw) std::cout <<c;
        std::cout << "\n";
    }
    return 0;
}
// 0123456