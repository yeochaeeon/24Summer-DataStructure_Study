#include <iostream>
#include <queue>

int dist[100002];
int n,k;
int main(){
    std::cin >> n >> k;
    std::fill(dist,dist+100001,-1);
    dist[n] = 0;
    std::queue<int> q;
    q.push(n);

    while(dist[k] == -1) {
        auto cur = q.front();q.pop();  // n
        for (int nxt : {cur-1,cur+1,cur*2}){
            if ( nxt < 0 || nxt > 100000) continue;
            if ( dist[nxt] != -1 ) continue; 

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }

    }
    std::cout << dist[k];
}