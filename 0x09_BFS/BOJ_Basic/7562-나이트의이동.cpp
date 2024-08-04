#include <iostream>
#include <queue>

// int board[302][302];
int dist[305][305];
#define x first
#define y second
 int dx[8] = {-2,-1,1,2,2,1,-1,-2};
 int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int t,n;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> t; 
    while (t--){
        std::cin >> n;
        for(int i = 0 ; i < n; i++) {
            std::fill(dist[i],dist[i]+n,-1);
        }
        std::queue<std::pair<int,int>> q;
        int x,y;
        std::cin >> x >> y;
        dist[x][y] = 0;
        q.push({x,y});
        int tx,ty;
        std::cin >> tx >> ty;
        while(dist[tx][ty] == -1) {
            auto cur = q.front();q.pop();
            for (int dir = 0 ; dir < 8 ; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (dist[nx][ny] != -1 ) continue;

                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx,ny});
            }
        } 
        std::cout << dist[tx][ty] << "\n";
    }
}