/*                                                   Strongly Connected Components(Tarjan) frome Topcoder:
=========================================================================================================================================*/
int idx[maxn],tim,lowlink[maxn],scc[maxn],components;
stack<int>s ;
vector<int>adj[maxn] ;
void reset(){
     
     memset(scc,-1,sizeof(scc)) ;
     memset(idx,-1,sizeof(idx)) ;
     for(int i=0;i<=maxn;i++) adj[i].clear() ;
     while(!s.empty()) s.pop() ;
     components = 0 ;
}

void dfs(int here,int par) {

    idx[here] = lowlink[here] = tim++;
    s.push(here);
    for(int i = 0; i <(int)adj[here].size(); i++)  {
      int there = adj[here][i];
      if(idx[there] == -1) {
      	dfs(there,here) ;
        lowlink[here] = min(lowlink[here],lowlink[there] );
      }
      else if(scc[there]==-1){

      	/* This line is really trciky .) is means The lowlink[here] is defined as the lowest-numbered vertex reachable from the subtree rooted at here via a single edge in the same component as here. See the difference with line 23 :) */
        lowlink[here] = min(lowlink[here], idx[there]);
      }
    }
    
    if(lowlink[here] == idx[here]) {

    	int elem ;
    	do{
      	elem = s.top() ;
      	s.pop() ;
      	scc[elem]=components ;
      } while(elem!=here) ;
      components++ ;
    }
}
