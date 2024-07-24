#include <iostream>
#include <deque>
#include <vector> 

int main(){
    int N, M,cnt = 0;
    std::cin >> N >> M;

    std::deque<std::pair<int,int>> dq(N);
    int* t = new int[M];
    
    for (int i = 0 ; i < N ; i++){
        dq[i].first = i+1;
        dq[i].second = i+1;
    }
    int ii = 0;
    for (int i = 0 ; i < M ; i++){
        std::cin >> t[i];
        ii++; 
    }
    int j = 0;
    while(M--){
        // 제거하고자 하는 원소의 현재 인덱스(위치)탐색 
        int targetIndex = 0;
        for(auto a:dq){
            if (a.first == t[j]) {
                targetIndex = a.second;
                break;
            }
        }
        if ( dq.front().first == t[j]) {
            dq.pop_front(); 

            for(int i = 0 ; i < dq.size() ; i++) {
                dq[i].second = i+1;
            }
            j++; 
        } 
        else {
            if ( (dq.size()+1)/2 >= targetIndex ) {
                while(dq.front().first != t[j]) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    for(int i = 0 ; i < dq.size() ; i++) {
                        dq[i].second = i+1;
                    }
                    cnt++;
                } 
                dq.pop_front();
                for(int i = 0 ; i < dq.size() ; i++) {
                        dq[i].second = i+1;
                }
                j++;
            }
            else {
                while(dq.front().first != t[j]) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    for(int i = 0 ; i < dq.size() ; i++) {
                        dq[i].second = i+1;
                    }
                    cnt++;
                }
                dq.pop_front();
                for(int i = 0 ; i < dq.size() ; i++) {
                        dq[i].second = i+1;
                }
                j++;
            }
        }
    }
    std::cout << cnt;
}