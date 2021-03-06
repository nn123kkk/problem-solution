#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
 
 
using namespace std;
 
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))
 
#define INF INT_MAX
 
 
#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;
 
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_EDGES 2509
#define MAX_NODES 200
 
struct Edge{
    int st;
    int en;
    int w;
}e[MAX_EDGES];
int pre[MAX_NODES];
int nodes,edges;
int findPre(int u){
    if(pre[u]==u)return u;
    else return findPre(pre[u]);
}
bool comp(Edge e1, Edge e2){
    return e1.w<e2.w;
}
void resetPre(int n){
    for(int i=0;i<n;i++)pre[i] = i;
}
int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int i,j, in, test,mstw,total,w, takenEdge, cs=0;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &nodes);
        in = total = 0;
        for(i=0;i<nodes;i++){
            for(j=0;j<nodes;j++)
            {
            scanf("%d", &w);
            if(w!=0){
            e[in].st = i;
            e[in].en = j;
            e[in].w = w;
            total +=w;
            in++;
            }
            }
        }
        edges = in;
        resetPre(nodes);
        sort(e,e+edges,comp);
        mstw = takenEdge = 0;
        for(i=0;i<edges;i++){
            int stp = findPre(e[i].st);
            int enp = findPre(e[i].en);
            if(stp!=enp){
                takenEdge++;
                mstw += e[i].w;
                pre[stp]= enp;
            }
        }
        printf("Case %d: ", ++cs);
        if(takenEdge == nodes-1)printf("%d\n", total-mstw);
        else printf("-1\n");
 
    }
    return 0;
}
 