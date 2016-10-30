#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define MAXN 101
#define inf 1000000000
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int n,k ,T[5],u,dis[MAXN] ;
bool isReachable[101][11];
string buffer ;
struct edge{
	int pos,lift,cost ;
	bool operator<(const edge  &p )const
	{
		return cost>p.cost ;
	}	
} ;
edge e ;
int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
    #endif
	ios_base::sync_with_stdio(false) ;
	while(cin>>n>>k){
		memset(isReachable,0,sizeof(isReachable)) ;
		FOR(i,0,n-1) {
			cin>>T[i] ;
		}
		getline(cin,buffer) ;
		FOR(i,0,n-1){
			getline(cin,buffer) ;
			stringstream strin(buffer) ;
			//cout<<"lift "<<i<<" : " ;
			while(strin>>u){
				isReachable[u][i] = 1 ;
				//cout<<u<<" " ;
			} 
			//cout<<endl ;
		}
		//Dijkstra
		priority_queue<edge>pq ;
		e.cost = 0 ;
		e.pos = 0 ;
		FOR(i,0,n-1){
			if(isReachable[0][i]){
				e.lift = i ;
				pq.push(e) ;
			}
		}
		dis[0] = 0 ;
		FOR(i,1,99){
			dis[i] = inf ;
		}
		
		while(!pq.empty()){
			
			edge top  = pq.top() ;
			
			pq.pop() ;
			int u = top.pos ;
			int lift = top.lift ;
			
			//if(u==k) break ;
			FOR(v,0,99){
				FOR(i,0,n-1){	
					if( isReachable[v][i] && isReachable[u][i] ){ //floor u and v is reachable by this lift
						int cost = top.cost+T[i]*abs(v-u) ;
						if(i!=lift) cost+=60 ;  
						if(dis[v]>cost){
							//if(cost==357){
									//cout<<u<<" "<<lift<<" "<<top.cost<<endl ;
							//}
							//cout<<cost<<endl ;
							dis[v] = cost ;
							e.pos = v ;
							e.cost = dis[v] ;
							e.lift = i ;
							pq.push(e) ; 
						}
					}
				}
			}
		}
		
		if(dis[k]==inf) cout<<"IMPOSSIBLE\n" ;
		else cout<<dis[k]<<"\n" ;	
	}
	
	return 0;
}

