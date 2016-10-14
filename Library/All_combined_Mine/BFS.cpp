///             from shanto sir
vector<int>adj[MAXN]
int visited[MAXN] ;
int dist[MAXN] ;
int parent[MAXN] ;


void BFS(int s,int n){
	for(int i=0;i<n;i++){
		vis[i]=0 ;
	}
	queue<int>Q ;
	Q.push(s) ;
	visted[s]=1 ;
	dist[s]=0 ;
	parent[s] = s ;
	while(!Q.empty()){
		int u = Q.front() ;
		Q.pop() ;
		for(int i=0;i<adj[u].size();i++){
			if(visited[adj[u][i]]==0){
				int v = adj[u][i] ;
				visited[v]=1 ;
				dist[v]=dist[u]+1 ;
				parent[v]=u ;
				Q.push(v) ;
			}
		}
	}

}
