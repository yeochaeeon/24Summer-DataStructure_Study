#include <iostream>
#include <queue>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int board[302][302] ;
int zero[302][302];
int vis[302][302];

int main(){

    int n,m;
    std::cin >> n >> m;
    for (int i = 0 ; i < n; i++){
        for (int j= 0 ; j < m ; j++){
            std::cin >> board[i][j];
        }
    }
    int year = 0; 
    while (true){
        int cnt = 0 ;
        year++;
        // 사방에 있는 zero 의 개수를 센다
        for (int i = 0 ; i < n; i++) {
            for (int j= 0 ; j < m ; j++) {
                if (board[i][j] > 0) {
                    int cntZero = 0;
                    for (int dir = 0 ; dir < 4 ; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (board[nx][ny] == 0) cntZero++;
                    }
                    zero[i][j] = cntZero;
                }
            }   
        }
        // 빙산 - zero
        for (int i = 0 ; i < n; i++){
            for (int j = 0 ; j < m; j++){
                board[i][j] = board[i][j] - zero[i][j];
            }
        }
        // 덩어리 개수 세기 
        std::queue<std::pair<int,int>> q; 
        for (int i = 0 ; i < n; i++){
            for (int j = 0 ; j < m; j++){
                if (board[i][j] > 0 && vis[i][j] == 0) {
                    cnt++;
                    q.push({i,j}); 
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto cur = q.front();q.pop();
                        for (int dir = 0 ; dir < 4 ; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if ( vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        if (cnt == 2) {
            break;
            std::cout << year;
        }
    }
}