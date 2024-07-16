#include <bits/stdc++.h>

int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int arr[2][26] = {0};
    std::string a,b;

    std::cin >> a >> b;

    for(char c:a){
        arr[0][c-'a']++;
    }
    for(char c:b){
        arr[1][c-'a']++;
    }
    int cnt = 0;
    for(int i = 0 ; i<26; i++){
        cnt = cnt + abs(arr[0][i] - arr[1][i]);
    }
    std::cout << cnt;
}