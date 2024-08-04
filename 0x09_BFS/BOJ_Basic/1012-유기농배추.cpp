#include <iostream>
#include <queue>

int m,n;
int board[52][52];
int vis[52][52];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t,k;
    std::cin >> t;
    
    while(t--){
        std::cin >> m >> n >> k;
        for(int i = 0 ; i < n ; i++) { 
            // 처음에 틀린 이유 : 
            // t가 2이상일 때 board,vis 초기화 코드 필요한데 안넣어줌.
            std::fill(board[i],board[i]+m,0);
            std::fill(vis[i],vis[i]+m,0);
        }
        while(k--){
            int x,y;
            std::cin >> x >> y ;
            board[y][x] = 1;
        }
        std::queue<std::pair<int,int>> q;
        int ans = 0; 

        for (int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if (board[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    while(!q.empty()){
                        auto cur = q.front();q.pop();
                        for(int dir = 0 ; dir<4 ; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;

                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    } ans++;
                }
            }
        }
        std::cout << ans << "\n";
    }
}