/// 		DFS without recursive call using stack  fron shanto sir

vector<int>adj[MAXN] ;
int edge_id[MAXN] ;
int vis[MAXN] ;
void DFS(int s,int n){
	for(int i=0;i<n;i++) edge_id[i]=vis[i]=0 ;
	stack<int>S ;
	while(!S.empty()){
		int u  = S.top() ;
		S.pop() ;
		while(edge_id[u]<adj[u].size()){
			int v = adj[u][edge_id[u]] ;
			edge_id[u]++ ;
			if(vis[v] == 0 ){
				vis[v]=1 ;
				S.push(u) ;
				S.push(v) ;
				break ;
			}
		}
	}
}
