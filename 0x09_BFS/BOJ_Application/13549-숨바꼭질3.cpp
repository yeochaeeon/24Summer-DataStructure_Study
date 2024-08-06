#include <iostream>
#include <queue>

int dist[100002];
int n,k;

int main(){
    std::fill(dist,dist+100002,-1);
    std::cin >> n >> k;
    dist[n] = 0;
    std::queue<int> q;
    q.push(n);
    while(dist[k] == -1){
        int cur = q.front();q.pop();
        for ( int nxt:{cur*2,cur-1,cur+1} ) { //cur*2 먼저 해야함.
            if ( nxt < 0 || nxt > 100000) continue;
            if ( dist[nxt] != -1 ) continue;

            if (nxt == cur*2) dist[nxt] = dist[cur];
            else dist[nxt] = dist[cur] + 1;

            q.push(nxt);
        }
    }
    std::cout << dist[k];
}