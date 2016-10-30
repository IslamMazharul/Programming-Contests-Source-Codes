/*                           Dijkstra-from https://sites.google.com/site/smilitude
=======================================================================================================================*/


vector<int> edge[100], cost[100];
const int infinity = 1000000000;

edge[i][j] = jth node connected with i 
cost[i][j] = cost of that edge

struct data 
{
    int city, dist;
    bool operator < ( const data& p ) const 
    {
        return dist > p.dist ;     // if is return true true than the swap is occured
    }
};

int dijkstra(int source, int destination) {
    
    int d[100];
    for(int i=0; i<100; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top();  q.pop();
        int ucost = d[ u.city ];
        int edge_count = edge[u.city].size() ;
        for(int i=0; i<edge_count; i++) {
            v.city = edge[u.city][i] ; v.dist = cost[u.city][i] + ucost;
            // relaxing :)
            
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    
    return d[ destination ];
}
