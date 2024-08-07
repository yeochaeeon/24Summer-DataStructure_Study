#include <iostream>
#include <queue>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int vis[102][102];
int board[102][102];

int N,mxheight,mx;

int bfs(int rain){
    int cnt = 0;
    std::queue<std::pair<int,int>> q;
    for (int i = 0 ; i < N; i++){
        for (int j = 0 ; j < N; j++){
            if (board[i][j] <= rain || vis[i][j] == 1) continue;

            cnt++;
            vis[i][j] = 1;            
            q.push({i,j});
            while(!q.empty()){
                auto cur = q.front();q.pop();
                for (int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if ( nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if ( vis[nx][ny] == 1 || board[nx][ny] <= rain) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = 1;

                }
            }
        }
    }
    return cnt;
}
void resetVis(int vis[102][102]){
    for (int i = 0 ; i < N; i++){
        std::fill(vis[i],vis[i]+N,0);
    }
}
int main(){
    std::cin >> N;
    int minheight = 100;
    for (int i = 0 ; i < N; i++){
        for (int j = 0 ; j < N; j++){
            std::cin >> board[i][j];
            if (mxheight < board[i][j]) mxheight = board[i][j];
            if (minheight > board[i][j]) minheight = board[i][j];
        }
    }
    // std::cout << mxheight << minheight;
    for (int i = minheight-1 ; i < mxheight ; i++){ 
        // 모든 영역이 잠기지 않는 상황까지 고려해주기위해 minheight-1
        int result = bfs(i);
        if (result > mx) mx = result;
        resetVis(vis);
    }
    std::cout << mx;

}