// RGB 따로 말고 한 번에 구하는 코드로도 짜보기 
#include <iostream>
#include <queue>

char board[102][102];
int vis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n;

int main(){
    std::cin >> n;
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n ; j++){
            std::cin >> board[i][j] ;            
        }
    }
    // 적록색약 아닌 사람 
    // R개수 
    int r = 0; 
    for( int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n ; j++){
            if (board[i][j] == 'R' && vis[i][j] == 0) {
                std::queue<std::pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if ( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if ( vis[nx][ny] == 1 || board[nx][ny] != 'R') continue; 

                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                r++;
            }
        }
    }
    // G개수
    int g = 0;
    for(int i = 0 ; i < n ; i++) { 
        std::fill(vis[i],vis[i]+n,0);
    }
    for( int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n ; j++){
            if (board[i][j] == 'G' && vis[i][j] == 0) {
                std::queue<std::pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if ( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if ( vis[nx][ny] == 1 || board[nx][ny] != 'G') continue; 

                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                g++;
            }
        }
    }
    // B개수
    int b = 0; 
    for(int i = 0 ; i < n ; i++) { 
        std::fill(vis[i],vis[i]+n,0);
    }
    for( int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n ; j++){
            if (board[i][j] == 'B' && vis[i][j] == 0) {
                std::queue<std::pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if ( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if ( vis[nx][ny] == 1 || board[nx][ny] != 'B') continue; 

                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                b++;
            }
        }
    }
    // 적록색약 - RG개수
    int rg = 0; 
    for(int i = 0 ; i < n ; i++) { 
        std::fill(vis[i],vis[i]+n,0);
    }
    for( int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n ; j++){
            if (board[i][j] != 'B' && vis[i][j] == 0) {
                std::queue<std::pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if ( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if ( vis[nx][ny] == 1 || board[nx][ny] == 'B') continue; 

                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                rg++;
            }
        }
    }
    std::cout << r + g + b << " " << rg + b ;
}