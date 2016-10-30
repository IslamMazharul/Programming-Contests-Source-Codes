#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
#define MAXN 10000+7
vector<int>g[MAXN],temp ;
int n , m ,col[MAXN];
void DFS(int u,int par){
		col[u] = 1 ;
		temp.push_back(u) ;
		FOR(i,0,g[u].size()-1){
			int v = g[u][i] ;
			if(v==par) continue ;
			if(!col[v]){
				DFS(v,u) ;
			}
		}
}
int main(int argc, char **argv){
	ios::sync_with_stdio(false) ;
	int x,y ;
	while(cin>>n>>m){
		
		FOR(i,0,n) {
			g[i].clear() ;
			col[i] = 0 ;
		}
		
		FOR(i,0,m-1){
			cin>>x>>y ;
			g[x].push_back(y) ;
			g[y].push_back(x) ;
		}
		bool res =0  ;
		FOR(i,1,n){
			if(!col[i]){
				temp.clear() ;
				DFS(i,-1) ;
				if(temp.size()>=4){
					res = 1 ;
					break ;
				}
			}
			
		}
		
		if(res) cout<<"YES\n" ;
		else cout<<"NO\n" ;
	}
	
	return 0;
}


