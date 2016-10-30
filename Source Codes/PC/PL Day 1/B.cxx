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
#define inf 1000000
using namespace std ;
#define MAXN 1000
struct edge{
	int x,y,cost ;
	bool operator<(const edge &p)const
	{
		return cost>p.cost ;
	}
} ;
edge e ,top;
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int n , m ,maze[MAXN][MAXN],res[MAXN][MAXN] ;
int dx[] = {-1,1,0,0} ;
int dy[] = {0,0,-1,1} ;
inline bool in(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m) return 0 ;
	return 1 ;
}

int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
    #endif
	ios_base::sync_with_stdio(false) ;
	int tc ;
	cin>>tc ;
	while(tc--){
		cin>>n>>m ;
		FOR(i,0,n-1){
			FOR(j,0,m-1){
				cin>>maze[i][j] ;
				res[i][j] = inf ;
			}
		}
		//dijkstra
		priority_queue<edge>pq ;	
		e.x = e.y =  0 ;
		e.cost = res[0][0] = maze[0][0] ;
		pq.push(e) ;
		while(!pq.empty() && res[n-1][m-1]==inf){
			top = pq.top() ; 
			pq.pop() ;
			FOR(i,0,3){
				int newX = top.x+dx[i] ;
				int newY = top.y+dy[i] ;
				if(in(newX,newY)){
					int cost = res[top.x][top.y]+maze[newX][newY] ;
					if(res[newX][newY]>cost){
						res[newX][newY] = cost ;
						e.x = newX ;
						e.y = newY ;
						e.cost = cost ;
						pq.push(e) ;
					}
				}
			}
		}
		
		cout<<res[n-1][m-1]<<"\n" ;
	}
	return 0;
}

