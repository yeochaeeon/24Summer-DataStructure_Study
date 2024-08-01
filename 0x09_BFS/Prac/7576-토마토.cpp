#include <iostream>
#include <queue>

int board[1002][1002] ;
int dis[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n,m;

int main(){

    std::queue<std::pair<int,int> > q; 
    std::cin >> m >> n ;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < m; j++){
            std::cin >> board[i][j];
            if ( board[i][j] == 1) q.push({i,j});
            if ( board[i][j] == 0) dis[i][j] = -1;
        }
    }
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if ( nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if ( dis[nx][ny] >= 0 ) continue;
            dis[nx][ny] = dis[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    int maxDist = 0;
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < m;  j++){
            // std::cout << dis[i][j] ;
            if (dis[i][j] == -1) {
                std::cout << -1 ;
                return 0;
            }
            if (dis[i][j] > maxDist) maxDist = dis[i][j]; 
        }
        // std::cout << "\n";
    }
    std::cout << maxDist ;
}