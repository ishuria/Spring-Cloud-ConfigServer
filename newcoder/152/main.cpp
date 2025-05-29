#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000;

struct edge{
    int v;
    int d, p;
};

vector<int> path;
vector<int> temp;
int minCost;

void DFS(vector<int> pre[], int v, int s, vector<edge> g[]){
    if (v==s){
        temp.push_back(v);
        int cost = 0;
        for (int i = 0; i < temp.size()-1; ++i) {
            int u = temp[i];
            int vvv = temp[i+1];
            int m = INF;
            int mc = INF;
            for (int j = 0; j < g[u].size(); ++j) {
                if (g[u][j].v==vvv){
                    if (g[u][j].d<m) {
                        mc = g[u][j].p;
                        m=g[u][j].d;
                    } else if (g[u][j].d==m) {
                        mc = min(mc, g[u][j].p);
                    }
                }
            }
            cost += mc;
        }
        if (cost < minCost){
            minCost = cost;
            path = temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre, pre[v][i], s, g);
    }
    temp.pop_back();
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m)!=EOF) {
        if (n==0||m==0){
            return 0;
        }
        vector<edge> g[n+1];
        vector<int> pre[n+1];
        for (int i = 0; i < m; ++i) {
            int a, b, d, p;
            scanf("%d%d%d%d", &a,&b,&d,&p);
            g[a].push_back({b, d, p});
            g[b].push_back({a, d, p});
        }
        int s, t;
        scanf("%d%d", &s, &t);
        int d[n+1];
        fill(d, d + n + 1, INF);
        d[s]=0;
        bool visit[n+1];
        fill(visit, visit + n + 1, false);

        for (int i = 0; i < n; ++i) {
            int u = -1;
            int min = INF;
            for (int j = 1; j < n+1; ++j) {
                if (!visit[j]&&d[j]<min){
                    u=j;
                    min=d[j];
                }
            }
            if (u==-1){
                break;
            }
            visit[u]=true;
            for (int j = 0; j < g[u].size(); ++j) {
                int v = g[u][j].v;
                if (!visit[v]) {
                    if (d[u]+g[u][j].d<d[v]){
                        d[v] = d[u]+g[u][j].d;
                        pre[v].clear();
                        pre[v].push_back(u);
                    } else if (d[u]+g[u][j].d==d[v]) {
                        pre[v].push_back(u);
                    }
                }
            }
        }

        minCost = INF;
        path.clear();
        temp.clear();
        DFS(pre, t, s, g);

//        int cost = 0;
//        for (int i = 0; i < path.size()-1; ++i) {
//            int u = path[i];
//            int v = path[i+1];
//            for (int j = 0; j < g[u].size(); ++j) {
//                if (g[u][j].v==v){
//                    cost += g[u][j].p;
//                    break;
//                }
//            }
//        }
        printf("%d %d\n", d[t], minCost);
    }
    return 0;
}

//int main() {
//    int n, m;
//    while (scanf("%d%d", &n, &m)!=EOF) {
//        if (n==0||m==0){
//            return 0;
//        }
//        vector<edge> g[n+1];
//        for (int i = 0; i < m; ++i) {
//            int a, b, d, p;
//            scanf("%d%d%d%d", &a,&b,&d,&p);
//            g[a].push_back({b, d, p});
//            g[b].push_back({a, d, p});
//        }
//        int s, t;
//        scanf("%d%d", &s, &t);
//        int d[n+1];
//        fill(d, d + n + 1, INF);
//        d[s]=0;
//        bool visit[n+1];
//        fill(visit, visit + n + 1, false);
//
//        int cost[n+1];
//        fill(cost, cost + n + 1, INF);
//        cost[s]=0;
//
//
//        for (int i = 0; i < n; ++i) {
//            int u = -1;
//            int min = INF;
//            for (int j = 1; j < n+1; ++j) {
//                if (!visit[j]&&d[j]<min){
//                    u=j;
//                    min=d[j];
//                }
//            }
//            if (u==-1){
//                break;
//            }
//            visit[u]=true;
//            for (int j = 0; j < g[u].size(); ++j) {
//                int v = g[u][j].v;
//                if (!visit[v]) {
//                    if (d[u]+g[u][j].d<d[v]){
//                        d[v] = d[u]+g[u][j].d;
//                        cost[v]=cost[u]+g[u][j].p;
//                    } else if (d[u]+g[u][j].d==d[v]&&cost[u]+g[u][j].p<cost[v]) {
//                        cost[v]=cost[u]+g[u][j].p;
//                    }
//                }
//            }
//        }
//        printf("%d %d\n", d[t], cost[t]);
//    }
//    return 0;
//}


//题目描述
//给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
//输入描述:
//输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;起点s，终点t。n和m为0时输入结束。
//(1<n<=1000, 0<m<100000, s != t)
//输出描述:
//输出 一行有两个数， 最短距离及其花费。
//示例1
//输入
//复制
//3 2
//1 2 5 6
//2 3 4 5
//1 3
//0 0
//输出
//复制
//9 11

