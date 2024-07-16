// to_string()함수 안쓰고 푸는 sol
#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a,b,c;
    std::cin >> a >> b >> c ;
    int n = a*b*c;

    int arr[10] = {0};
    while(n>0){
        arr[n%10]++;
        n/=10;
    }
    for(int i = 0; i<10;i++) std::cout << arr[i] << "\n";
}