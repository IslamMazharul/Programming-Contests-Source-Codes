/// Dijkstra from  shanto sir

class Node{
        int at,cost ;
        Node(int _at,int _cost){
            at = _at ; cost = _cost ;
        }
} ;
bool operator<(const Node &A,const Node &B){
    return A.cost>B.cost ;
}
class Edge{
    int v,w ;
};
vector<Edge> adj[MAXN] ;
priority_queue<Node>PQ ;
int dist[MAXN] ;
int n ;
void dijkstra(int s){
    for(int i=1;i<=n;i++) dist[i]=INT_MAX ;
    dist[s]=0 ;
    PQ.push(Node(s,0)) ;
    while(!PQ.empty()){
        Node u = PQ.top() ; PQ.pop() ;
        if (u.cost != dist[u.at]) continue ;
        for(Edge edg: adj[u.at]){
            if(dist[e.v]>u.cost+e.w){
                dist[e.v] = u.cost+e.w ;
                PQ.push(Node(e.v,dist[e.v])) ;
            }
        }
    }
}
