#include <iostream>
#include <queue>
#include <algorithm>

int N,M;
std::string board[102]; 
int dist[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> board[i];
    }
    for(int i = 0; i < N; i++) 
        std::fill(dist[i],dist[i]+M,-1);
    
    std::queue<std::pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M ) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    std::cout << dist[N-1][M-1] + 1;
}