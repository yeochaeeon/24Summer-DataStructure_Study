#include <iostream>
#include <queue>

int r,c;
std::string board[1002];
int distFire[1002][1002];
int distJ[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    std::cin >> r >> c; 
    for (int i = 0 ; i < r; i++){
        std::cin >> board[i];
    }
    std::queue<std::pair<int,int>> qFire;
    std::queue<std::pair<int,int>> qJ; 
    for (int i = 0 ; i < r ; i++){
        for(int j = 0; j < c; j++){
            if (board[i][j] == '#' || board[i][j] == '.') {
                distFire[i][j] = -1;
                distJ[i][j] = -1;
            }
            if (board[i][j] == 'F') {
                qFire.push({i,j});
                distFire[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                qJ.push({i,j});
                distJ[i][j] = 0;
            }
        }
    } 
    while(!qFire.empty()){
        auto cur = qFire.front();qFire.pop();
        for (int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= r  || ny >= c) continue;
            if ( distFire[nx][ny] >= 0 || board[nx][ny] == '#' ) continue;
            distFire[nx][ny] = distFire[cur.first][cur.second] + 1;
            qFire.push({nx,ny});
        }
    }

    while(!qJ.empty()){
        auto cur = qJ.front();qJ.pop();
        for (int dir = 0 ; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                std::cout << distJ[cur.first][cur.second] + 1;
                return 0;
            }
            if (distJ[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if ( distFire[nx][ny] != -1 && distFire[nx][ny] <= distJ[cur.first][cur.second] +1 ) continue;
            distJ[nx][ny] = distJ[cur.first][cur.second] +1 ;
            qJ.push({nx,ny});
        }
    } 
    std::cout << "IMPOSSIBLE";
}