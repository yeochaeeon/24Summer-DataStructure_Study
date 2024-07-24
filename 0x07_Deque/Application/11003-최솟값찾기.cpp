#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
int main(){
    int N,L,min;
    std::cin >> N >> L;

    std::deque<int> dq;
    std::vector<int> tmp(L);
    std::vector<int> ans;
    for (int i = 0 ; i < N ; i++){
        int val;
        std::cin >> val;
        dq.push_back(val);
    }
    for (int i = 0 ; i < L-1 ; i++){
        dq.push_front(dq.front());
    }
    while (N--) {
        for (int i = 0 ; i < L ; i++){
            tmp[i] = dq[i];
        }
        sort(tmp.begin(),tmp.end());
        ans.push_back(tmp[0]);
        dq.pop_front();
    }
    for(int i:ans){
        std::cout << i << " ";
    }
}