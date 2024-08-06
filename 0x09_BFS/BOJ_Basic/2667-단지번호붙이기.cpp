#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N,tmp;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
std::string board[27] ;
int vis[27][27];
int main(){

    std::cin >> N;
    for(int i = 0 ; i < N; i++){
        std::cin >> board[i];
    }
    
    std::vector<int> vArea;
    std::queue<std::pair<int,int>> q;
    for (int i = 0 ; i < N; i++){
        for (int j = 0 ; j < N ; j++){
            if (board[i][j] == '0' || vis[i][j] == 1) continue;

            vis[i][j] = 1;
            q.push({i,j});
            int area = 1;

            while(!q.empty()){
                auto cur = q.front();q.pop();
                for (int dir = 0 ; dir < 4 ; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;

                    area++;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            vArea.push_back(area);
        }
    }
    std::sort(vArea.begin(),vArea.end());
    std::cout << vArea.size() << "\n";
    for(int i:vArea){
        std::cout << i << "\n";
    }
}