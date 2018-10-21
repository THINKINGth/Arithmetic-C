#include <iostream>
#include <queue>
#include <utility>
const int INF = 100000;
char maze[10][10] = {
        {'#','.','#','#','#','#','#','#','.','#'},
        {'.','.','.','.','.','.','#','.','.','#'},
        {'.','#','.','#','#','.','#','#','.','#'},
        {'.','#','.','.','.','.','.','.','.','.'},
        {'#','#','.','#','#','.','#','#','#','#'},
        {'.','.','.','.','#','.','.','.','.','#'},
        {'.','#','#','#','#','#','#','#','.','#'},
        {'.','.','.','.','#','.','.','.','.','.'},
        {'.','#','#','#','#','.','#','#','#','.'},
        {'.','.','.','.','#','.','.','.','.','#'},
};
int d[10][10];
typedef std::pair<int,int> P;
int sx = 0,sy = 1;
int gx = 9,gy = 8;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int bfs(){
    std::queue<P>que;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            d[i][j] = INF;
        }
    }
    d[sx][sy] = 0;
    que.push(P(sx,sy));
    while(que.size()){
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy)break;
        for(int i = 0;i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx >= 0 && nx < 10 && ny >= 0 && ny <10 && d[nx][ny] == INF && maze[nx][ny] == '.') {
                d[nx][ny] = d[p.first][p.second] + 1;
                /*   这里使用语句：
                 *   p.first = nx;
                 *   p.second = ny;
                 *   que.push(p);
                 *   会使向四个方向的搜索范围变窄，每次的p.first和p.second都会变化，不会再像p的四周进行搜索，并标记附近四个方向的距离
                 */
                que.push(P(nx,ny));
            }
        }

    }
    return d[gx][gy];
}
void sovle(){
    printf("%d",bfs());
}
int main() {
    sovle();
    for(int i = 0;i < 10;i++){
        printf("\n");
        for(int j = 0;j < 10;j++){
            printf("%d\t",d[i][j]);
        }
    }
    for(int i = 0;i < 10;i++){
        printf("\n");
        for(int j = 0;j < 10;j++){
            printf("%c\t",maze[i][j]);
        }
    }
    return 0;
}
