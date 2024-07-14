#include <iostream>
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,x;
    std::cin >> n >> x;
    int* arr = new int[n];
    for (int i = 0 ; i < n ; i++){
        int a;
        std::cin >> a;
        arr[i] = a; 
    }
    for (int i = 0; i < n ;i++){
        if (arr[i] < x) std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}