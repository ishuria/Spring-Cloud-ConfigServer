#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000;
struct edge{
    int v;
    int w;
};

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m)!=EOF) {
        if (n==0) {
            return 0;
        }
        vector<edge> g[n+1];
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        int side[n+1];
        for (int i = 1; i <= n; ++i) {
            int s;
            scanf("%d", &s);
            side[i]=s;
        }

        bool visit[n+1];
        fill(visit, visit+n+1, false);

        int d[n+1];
        fill(d, d+n+1, INF);
        d[1]=0;
        d[2]=0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            int min = INF;
            for (int j = 1; j <= n; ++j) {
                if (!visit[j]&&side[j]==1&&d[j]<min) {
                    min = d[j];
                    u=j;
                }
            }
            if (u==-1){
                break;
            }
            visit[u]= true;
            for (int j = 0; j < g[u].size(); ++j) {
                int v = g[u][j].v;
                if (!visit[v]&&side[v]==1&&d[v]>d[u]+g[u][j].w) {
                    d[v] = d[u]+g[u][j].w;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int u = -1;
            int min = INF;
            for (int j = 1; j <= n; ++j) {
                if (!visit[j]&&side[j]==2&&d[j]<min) {
                    min = d[j];
                    u=j;
                }
            }
            if (u==-1){
                break;
            }
            visit[u]= true;
            for (int j = 0; j < g[u].size(); ++j) {
                int v = g[u][j].v;
                if (!visit[v]&&side[v]==2&&d[v]>d[u]+g[u][j].w) {
                    d[v] = d[u]+g[u][j].w;
                }
            }
        }

        int ans = INF;

        for (int i = 1; i <= n; ++i) {
            if (side[i]!=1){
                continue;
            }
            for (int j = 1; j <= n; ++j) {
                if (side[j]!=2) {
                    continue;
                }
                for (int k = 0; k < g[i].size(); ++k) {
                    if (g[i][k].v==j) {
                        ans = min(ans, d[i]+d[j]+g[i][k].w);
                    }
                }
            }
        }

        printf("%d\n", ans==INF?-1:ans);
    }
    return 0;
}

//2
//1
//1 2 100
//1 2
//3
//3
//1 2 100
//1 3 40
//2 3 50
//1 2 1
//5
//5
//3 1 200
//5 3 150
//2 5 160
//4 3 170
//4 2 170
//1 2 2 2 1
//0