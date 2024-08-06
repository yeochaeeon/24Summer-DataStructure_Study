#include <queue>
#include <iostream>
#include <vector>

int building[1000002];
int dist[1000002];
int f,s,g,u,d;
int main(){
    
    std::cin >> f >> s >> g >> u >> d;
    std::fill(dist,dist+f+1,-1);

    std::queue<int> q;
    std::vector<int> v; 
    v.push_back(u); v.push_back(d - 2*d); // -d를 넣기 위함.
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for (int dir:v){
            int nx = cur + dir;
            // std::cout << "##" << nx;
            if (nx > f || nx < 1) continue;
            if (dist[nx] > -1) continue;

            q.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }
    // for (int i = 0 ; i <f+1; i++){
    //     std::cout << dist[i] << " ";
    // }
    if (dist[g] == -1) std::cout << "use the stairs";
    else std::cout << dist[g];
}