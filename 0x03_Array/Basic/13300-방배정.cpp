#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(std::pair<int,int>a, std::pair<int,int>b){
    if(a.first==b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N,k;
    std::cin >> N >> k;

    std::vector<std::pair<int,int>> v(N);
    for (int i = 0 ; i < N ; i++){
        std::cin >> v[i].first >> v[i].second;
    }
    // sort(v.begin(),v.end(),cmp);
    std::vector<int> girl(6);
    std::vector<int> boy(6);

    for(std::pair i:v){
        if (i.first == 0) girl[i.second-1]++;
        else boy[i.second-1]++;

    }
    int room = 0;
    for(int g:girl){
        int r ;
        if (g%k == 0) r = g/k;
        else r = g/k + 1;

        room = room + r;
    }
    for(int b:boy){
        int r ;
        if (b%k == 0) r = b/k;
        else r = b/k + 1;

        room = room + r;
    }
    std::cout << room;

}