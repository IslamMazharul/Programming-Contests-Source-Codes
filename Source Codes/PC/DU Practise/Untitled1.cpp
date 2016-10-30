#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define MAXN 100000+7
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define LL long long
int N ,skip[MAXN],depth[MAXN],parent[MAXN],bit[MAXN];
struct EDGE{
    int to,cost ;
};
vector<EDGE>graph[MAXN] ;
EDGE e ;
int decomp(int u,int pr,int d){
    depth[u] = d ;
    parent[u] = pr ;
    int siz = graph[u].size()-1 ,childNodes = 1 ,heavyNode,temp=0,maxii=0 ;
    FOR(i,0,siz){
        int v = graph[u][i].to ;
        if(v==pr) continue ;
        temp = decomp(v,u,d+1) ;
        childNodes+=temp ;
        if(maxii>temp){
                maxxi = temp ;
                heavyNode = v ;
        }
    }
    if(childNodes!=1){
        skip[heavyNode] = u ;
    }
    return childNodes ;
}
void init(int u,int r,int pr){
    skip[u] = r ;
    int siz = graph[u].size()-1 ;
    FOR(i,0,siz){
        int v = graph[u][i].to ;
        if(to==pr) continue ;
        if(skip[v]!=-1){
            //Heavy edge
            bit[r] = max(bit[r],graph[u][i].cost) ;
            init(v,r,u) ;
        }
        else{
            init(v,v,u) ;
        }
    }
}
void update(int u,unt v,int val){
    if(skip[u]==skip[v]){
        int r  = skip[u] ;
        bit[r] = max(bit[r],val) ;
        return ;
    }
    else{
            // u and v is a light edge
    }
}
int query(int u,int root){
    int ret = - 1 ;
    while(u!=root){
        if(skip[u]==root){
            ret = max(ret,graph[u][]) ;
            u = parent[u] ;
        }
        else{
            ret = max(ret,bit[skip[u]) ;
            if(skip[u]==root) return ret ;
            u = parent[skip[u]] ;
        }
    }
    return ret ;
}

int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\Users\Mazharul Islam\Documents\in.txt","r",stdin) ;
    #endif
    int Testcases ;
    cin>>Testcases ;
    while(Testcases--){
        cin>>N ;
        FOR(i,0,N-2){
            cin>>u>>v>>cost ;
            e.to = v ;
            e.cost = cost ;
            graph[u].push_back(e) ;
            e.to = u ;
            graph[v].push_back(e) ;
        }
        memset(skip,-1,sizeof(skip)) ;
        memset(bit,-1,sizeof(bit)) ;
        decomp(0,0,0) ;
        init(0,0,0);
    }

    return 0 ;
}
