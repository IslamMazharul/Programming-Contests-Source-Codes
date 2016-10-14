/*
 Author                             :     unlucky_13
 Probs_link                         :     http://www.lightoj.com/volume_showproblem.php?problem=1063
 Category                           :     Articulation-point
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
const int maxn=10001;
using namespace std;
bool artpoint[maxn] ;
int predfn,n,m;
vector<int>g[maxn];
int dis[maxn];
int back[maxn];
void dfs(int u,int p){


	int child = 0 ;
	predfn++;
	dis[u]=back[u]=predfn;
	for(int i=0;i<(int)g[u].size();i++){
		int v = g[u][i] ;

		    if(!dis[v]){
		    	child++ ;
		    	dfs(v,u) ;
			    back[u] = min(back[u],back[v]) ;
			    if(back[v]>=dis[u]) artpoint[u] = 1 ;
		    }
		    else if(v!=p) back[u] =min(back[u],dis[v]) ;
		}
	if(p==-1&&child<=1) artpoint[u] = 0 ; //this line contains vagal
}
void reset(){

	memset(artpoint,0,sizeof(artpoint)) ;
	memset(dis,0,sizeof(dis)) ;
	for(int i=1;i<=n;i++) g[i].clear() ;
	predfn = 0;

}

int main() {
 // freopen("//home//mazhar//Desktop//in.txt","r",stdin) ;
  int tc,ct=1,u,v;
  scanf("%d",&tc) ;
  while(tc--){
	  scanf("%d %d",&n,&m) ;
          reset() ;
	  for(int i=0;i<m;i++){
		  scanf("%d %d",&u,&v);
		  g[u].push_back(v) ;
		  g[v].push_back(u) ;

	  }
	  dfs(1,-1);
	  int res=0 ;
	  for(int i=1;i<=n;i++)  res+=artpoint[i] ;
	  printf("Case %d: %d\n",ct++,res) ;

  }


	return 0;
}

