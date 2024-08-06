#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int board[102][102];
int vis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int m,n,k;

int main(){
    std::cin >> m >> n >> k; // 행, 열 , 개수
    // 1. 사각형 채우기 
    while(k--){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int lefttopX, lefttopY, rightbotX,rightbotY;
        std::cin >> lefttopX >> lefttopY >> rightbotX >> rightbotY ;
        int r = rightbotY - lefttopY;
        int c = rightbotX - lefttopX;

        for (int i = lefttopY ; i < rightbotY; i++){
            for (int j = lefttopX ; j < rightbotX; j++){
                if ( board[i][j] != 0) continue;
                board[i][j] = 1;
            }
        }
    }
    // 2. 빈공간 개수, 영역 세기
    int cnt = 0; 
    std::vector<int> vArea;
    std::queue<std::pair<int,int>> q;
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n; j++){
            if ( board[i][j] == 1 || vis[i][j] == 1) continue;
            
            vis[i][j] = 1;
            q.push({i,j});
            int area = 0;
            cnt++; area++;
            while( !q.empty() ){
                auto cur = q.front(); q.pop();
                for (int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if (board[nx][ny] != 0 || vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                    area++;
                }
            }
            vArea.push_back(area);
        }
    }
    std::sort(vArea.begin(),vArea.end());
    std::cout << cnt << "\n";
    for (int i:vArea){
        std::cout << i << " ";
    }
}