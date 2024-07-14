#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> nine;

    // size 9짜리 배열 받기 
    for(int i = 0; i < 9; i++){
        int n;
        std::cin >> n;
        nine.push_back(n);
    }

    // 배열 요소들의 합을 구해 100과의 차를 구하기 
    int nineTotal = std::accumulate(nine.begin(),nine.end(),0);
    int diff = nineTotal - 100;

    // 2개의 요소의 합이 위에서 구한 diff가 되는 쌍을 찾아 그 쌍의 
    // 두 요소의 인덱스를 idx1,2에 저장하기
    int idx1,idx2;
    for(int i = 0; i < 8 ; i++){
        for (int j = i+1 ; j < 9; j++){
            if((nine[i]+nine[j]) == diff) {
                idx1 = i; idx2 = j;
                break;
            }
        }
    }

    // 찾은 두개의 요소를 삭제하기 
    nine.erase(std::remove_if(nine.begin(),nine.end(),
                [nine,idx1,idx2](int x)
                {return (x == nine[idx1]) || (x == nine[idx2]);}),nine.end());

    // 오름차순으로 정렬하기 
    sort(nine.begin(),nine.end());

    // 출력하기
    for(int i : nine){
        std::cout <<"\n" << i ;
    }

}