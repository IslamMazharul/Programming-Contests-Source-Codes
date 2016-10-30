#include <bits/stdc++.h>
using namespace std ;
#define MAXN 5000
#define inf 10000000000
#define LL long long
struct EDGE{
    int to ;
    LL  cost ,out,tot;
    char type ;
    bool operator < (const EDGE &prev) const{
        if(out!=prev.out) return out > prev.out ;
        return tot > prev.tot ;
    }
} e ;

int n,m,p  ;
LL out_time[MAXN],tot_time[MAXN];
vector<EDGE>graph[MAXN] ;

void Dijkstra(int source,int des){

    for(int i=0;i<n;i++){
        out_time[i] = tot_time[i] = inf ;
    }

    priority_queue<EDGE>pq ;

    e.to = source ;
    e.tot = e.out =  0 ;
    out_time[source] = tot_time[source] = 0 ;
    pq.push(e) ;

    while(!pq.empty()){

        e = pq.top() ; pq.pop() ;
        int u  = e.to ;
       // cout<<u<<endl ;
        int siz =  graph[u].size() ;

        for(int i=0;i<siz;i++){

                int v = graph[u][i].to ;
                char type = graph[u][i].type ;
                LL o , t = tot_time[u]+graph[u][i].cost ;
               // cout<<v<<endl ;

                if(type=='I'){
                     o = out_time[u] ;
                }else{
                    o = out_time[u]+graph[u][i].cost ;
                }

            EDGE tmp ;
            tmp.to = v ;
            tmp.out = o ;
            tmp.tot = t ;
            tmp.cost = graph[u][i].cost ;
            tmp.type = graph[u][i].type ;

            if(out_time[v]>o){
               // cout<<o<<t<<endl ;
                 out_time[v] = o ;
                 tot_time[v] = t ;
                 pq.push(tmp) ;
            }

            else if(out_time[v]==o && tot_time[v]>t){
                    out_time[v] = o ;
                    tot_time[v] = t ;
                    pq.push(tmp) ;
            }
        }
    }

    if(tot_time[des]==inf) {
            cout<<"IMPOSSIBLE\n" ;
            return ;
    }

    cout<<out_time[des]<<" "<<tot_time[des]<<"\n" ;

}


int main(void){

    freopen("in.txt","r",stdin) ;
    cin>>n>>m>>p ;
    int u,v,cost ;
    char typ  ;
    for(int i=0;i<m;i++){
        cin>>u>>v>>cost>>typ ; ;
        e.cost = cost ;
        e.type  = typ ;

        e.to = v ;
        graph[u].push_back(e) ;
        e.to = u  ;
        graph[v].push_back(e) ;
    }

    int source ,des ;
    for(int i=0;i<p;i++){
        cin>>source>>des ;
        Dijkstra(source,des) ;
    }
    return 0 ;
}
