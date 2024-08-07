#include <iostream>
#include <queue>
#include <tuple>
int l,r,c;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dh[6] = {0,0,0,0,1,-1};

char board[32][32][32];
int dist[32][32][32];

int main(){

    while(true){
        std::cin >> l >> r >> c ;
        if ( l == 0 && r == 0 && c == 0) break;

        for (int i = 0 ; i < l ; i++){
            for (int j = 0 ; j < r ; j++){
                std::fill(dist[i][j], dist[i][j]+c, -1);
            }
        }
        std::queue<std::tuple<int,int,int>> q;
        bool Escape = false;
        for (int i = 0 ; i < l ; i++){
            for (int j = 0 ; j < r ; j++){
                for (int k = 0 ; k < c ; k++) {
                    std::cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        q.push({i,j,k});
                        dist[i][j][k] = 0;
                    }
                    else if (board[i][j][k] == '#') {
                        dist[i][j][k] = 0;
                    }
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front();q.pop();
            int curh,curx,cury;
            std::tie(curh,curx,cury) = cur;
            for (int dir = 0 ; dir < 6 ; dir++){
                int nh = curh + dh[dir];
                int nx = curx + dx[dir];
                int ny = cury + dy[dir];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue;
                if(board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue;

                dist[nh][nx][ny] = dist[curh][curx][cury] + 1; 
                if (board[nh][nx][ny] == 'E'){
                    Escape = true;
                    std::cout <<  "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
                    break;
                }
                q.push({nh,nx,ny});
            }
        }
        if(!Escape) std::cout << "Trapped!" << "\n";
    } 
}