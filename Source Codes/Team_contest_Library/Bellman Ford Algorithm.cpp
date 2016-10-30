#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map> 
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <iterator>
const int MAXN=210;
#define INF 0xffffff
inline int cube(int x){ return x*x*x ; }
using namespace std;
struct edges{
	int to,cost;
};
vector<edges>g[MAXN] ;
int main() {
	
	
	
	int kase,caseno,n,busyness[MAXN],e;
	int dis[MAXN],rdis[MAXN];
	scanf("%d",&caseno) ;
	
	for(kase=1;kase<=caseno;kase++){
		printf("Case %d:\n",kase) ;
		scanf("%d",&n) ;
		for(int i=1;i<=n;i++) {
			scanf("%d",&busyness[i]) ;
			dis[i]=INF ;
			rdis[i] = INF ;
			g[i].clear() ;
		}
		dis[1] = rdis[1] = 0 ;	
		scanf("%d",&e) ;
		int u,v;
		edges EDG ;
		
		for(int i=0;i<e;i++){
			scanf("%d %d",&u,&v) ;
			EDG.to  = v  ;
			EDG.cost= cube( busyness[v]-busyness[u] ) ;
			g[u].push_back(EDG) ;
		}
			
		//Bellman-Ford
		
		for(int i=1;i<=n-1;i++){
			for(int u=1;u<=n;u++){
				for(int j=0;j<(int)g[u].size();j++){
					//relaxing
					int v=g[u][j].to ;
					int cost = g[u][j].cost ;
					if(dis[u]!=INF && dis[u]+cost<dis[v]) {
						rdis[v] = dis[v]=dis[u]+cost ;
					}
				}
			}
		}
		
		//checking for -ve cycle

		for(int i=1;i<=n-1;i++){
			for(int u=1;u<=n;u++){
				for(int j=0;j<(int)g[u].size();j++){
					//relaxing
					int v=g[u][j].to ;
					int cost = g[u][j].cost ;
					if(rdis[u]!=INF && rdis[v]>rdis[u]+cost) {
						rdis[v] = rdis[u]+cost ;
					}
				}
			}
		}

		int q ;
		scanf("%d",&q) ;
		
		while(q--){
			
			scanf("%d",&u) ;
			if(rdis[u]!=dis[u] || dis[u]==INF ||dis[u]<3){
				printf("?\n") ;
			}
			else {
				printf("%d\n",dis[u]) ;
			}
		}
	}

	return 0;
}

