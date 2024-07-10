// 2. 주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의
// 두 원소가 존재하면 1을, 아니면 0을 반환하는 함수를 출력하라.

#include <iostream>

int func2(int arr[], int N){
    for ( int i = 0 ; i < N-1 ; i++){
        for ( int j = i+1; j < N; j++){
            // std::cout << "j == "<<arr[j] << std::endl;
            if ( (arr[i] + arr[j]) == 100) return 1;
        } 
    }
    return 0;
}
int main(){
    int arr1[] = {1,52,48};
    int arr2[] = {50,42};
    int arr3[] = {4,13,63,87};

    std::cout << func2(arr1,3) << func2(arr2,2) << func2(arr3,4) << std::endl;
}