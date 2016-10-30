int fordFulkerson(int n,int s,int t){

    memset(fnet,0,sizeof(fnet)) ;  //initialization of the flow
    int flow = 0 ;
    while(1){
       //find an argumenting path
        memset(prev,-1,sizeof(prev)) ;
        prev[s] = -2 ;
        queue<int>q ;
        q.push(s) ;
        while(!q.empty() && prev[t]==-1){

             int u = q.front() ;
             //cout<<u<<"\n" ;
             q.pop() ;
             FOR(v,1,n){
                //int v = adj[u][i] ;
                if(prev[v]==-1){ //never seen before
                   if(fnet[v][u] || fnet[u][v]<cap[u][v]){        //taking backedge over forword edge
                        prev[v]= u ;
                        q.push(v) ;
                   }
                }
            }
        }

        if(prev[t]==-1) break ;  //no argumenting path found
        int bot = INT_MAX ;
        for(int v=t,u=prev[t];u>=0;v=u,u=prev[v]){  //tracing the argumenting path
            if(fnet[v][u]){
               bot = min(fnet[v][u],bot) ;
            }
            else{
               bot = min(cap[u][v]-fnet[u][v],bot) ;
            }
        }

        for(int v=t,u=prev[t];u>=0;v=u,u=prev[v]){  //tracing the argumenting path and updating the flow
            if(fnet[v][u]) fnet[v][u] -= bot ;
            else  fnet[u][v]+=bot   ;
        }
        flow+=bot ;
    }

    return flow ;

}
