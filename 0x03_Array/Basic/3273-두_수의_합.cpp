#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    std::vector<int> input(N);
    for (int i = 0; i < N ; i++){
        std::cin >> input[i];
    }
    int S;
    std::cin >> S;
    int cnt = 0;

    std::vector<int> v(S);
    for(int i:input){
        if (i > S) continue; // 이거 안넣어주면 runtime error
        if(v[S-i] == 1) cnt++; 
        v[i]++;
    }
    std::cout << cnt;

}
// 첫 시도에서 21번 줄을 넣어주지 않아 runtime error 가 발생했었는데 그 이유는 
// 만약 S가 13인 상태에서 
// 주어진 배열(input)의 원소중에 13보다 큰 14와 같은 원소가 존재하면 다음 줄에서 
// v[-1]에 접근하는 상황이 발생하게 되므로
// OutOfBounds 와 관련한 runtime error 가 발생한다.