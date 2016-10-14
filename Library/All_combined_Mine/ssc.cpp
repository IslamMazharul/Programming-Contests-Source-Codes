/*
 Author                             :     unlucky_13
 Probs_link                         :
 Category                           :
 Algorithm_Used                     :

*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define i64 long long int
//const int min=;
const int maxn=10010;
using namespace std;
int idx[maxn],tim,lowlink[maxn],scc[maxn],components,deg[maxn];
stack<int>s ;
vector<int>adj[maxn] ;

void dfs(int here,int par) {

    idx[here] = lowlink[here] = tim++;
    s.push(here);
    for(int i = 0; i <(int)adj[here].size(); i++)  {
      int there = adj[here][i];
      if(there==par) continue ;
      if(idx[there] == -1) {
    	dfs(there,here) ;
        lowlink[here] = min(lowlink[here],lowlink[there] );
      }
      else if(scc[there]==-1){

      	/* This line is really trciky .) is means The lowlink[here] is defined as the lowest-numbered vertex reachable from the subtree rooted at here via a single edge in the same component as here.*/

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
    	components ++ ;
    }
  }

void reset()
{
	memset(deg,0,sizeof(deg)) ;
	memset(scc,-1,sizeof(scc)) ;
	memset(idx,-1,sizeof(idx)) ;
    for(int i=0;i<=maxn;i++) adj[i].clear() ;
    while(!s.empty()) s.pop() ;
    components = 0 ;
}

int main() {

	//freopen("//home//mazhar//Desktop//in.txt","r",stdin) ;
	int caseno,kase,m,n,u,v;
	scanf("%d",&caseno) ;
	for(kase=1;kase<=caseno;kase++){
		reset() ;
		scanf("%d %d",&n,&m) ;
		while(m--)
		{
			scanf("%d %d",&u,&v) ;
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
		}
		dfs(0,-1) ;
		for(int i=0;i<n;i++){
			for(int j=0;j<(int)adj[i].size();j++){
				int u=adj[i][j] ;

				if(scc[u]!=scc[i]){
					//cout<<u<<" "<<"SSC "<<scc[u]<<"     " ;
					//cout<<i<<" "<<"SSC "<<scc[i]<<endl ;
					deg[scc[u]]++ ;
					deg[scc[i]]++ ;
				}
			}
		}
		int ans = 0 ;
		for(int i=0;i<n;i++){
			if(deg[i]==2) ans++ ;
		}
		printf("Case %d: %d\n",kase,(ans+1)/2) ;


	}


	return 0;
}

