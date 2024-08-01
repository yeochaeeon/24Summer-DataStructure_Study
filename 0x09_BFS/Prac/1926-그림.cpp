#include <iostream>
#include <queue>
#define X first 
#define Y second

int board[502][502];
int vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int r,c;
    std::cin >> r >> c;
    std::queue<std::pair<int,int>> q;

    for (int i = 0 ; i < r ; i++){
        for (int j = 0; j < c ; j++){
            std::cin >> board[i][j];
        }
    }
    int num = 0;
    int mxArea = 0;
    for (int i = 0; i < r; i++){
        for(int j = 0 ; j < c ; j++){
            if (board[i][j] == 0 || vis[i][j] == 1) continue;
            else {
                vis[i][j] = 1;
                num++;
                q.push({i,j});
                int area = 0;
                while(!q.empty()){
                    std::pair<int,int> cur = q.front(); q.pop(); area++;
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                        vis[nx][ny] = 1; 
                        q.push({nx,ny});
                    }
                }
                if ( mxArea < area ) mxArea = area;
            }
        }
    } std::cout << num << "\n" << mxArea;
}
