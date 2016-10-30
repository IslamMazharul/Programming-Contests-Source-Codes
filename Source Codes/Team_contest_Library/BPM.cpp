#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=202 ;
bool seen[maxn] ;
int deg[maxn] ,match[maxn] ,g[maxn][maxn],A[maxn],B[maxn] ;

bool bpm(int u){

  for(int i=0;i<deg[u];i++){
      int v=g[u][i] ;
      if(seen[v]) continue ;
      seen[v]=true ;
      if(match[v]==-1 || bpm(match[v])){
          match[v] = u ;
          return true ;
      }
  }

  return false ;

}

int main() {

   // freopen("//home//mazhar//Desktop//in.txt","r",stdin) ;
    int n,m,t,ct;
    ct = 0 ;
    scanf("%d",&t);
    while(ct!=t){

           scanf("%d",&n);
           for(int i=0;i<n;i++)  scanf("%d",&A[i]);
           scanf("%d",&m);
           for(int i=0;i<m;i++) scanf("%d",&B[i]);
           memset(deg,0,sizeof(deg));

           for(int i=0;i<n;i++){
			   for(int j=0;j<m;j++){
                    if(A[i]==0 && B[j]==0){

                        g[i][deg[i]++]=j+n;
                        g[j+n][deg[j+n]++]=i;
                    }
                    else if ( A[i]==0 ) continue;
                    else if(B[j]%A[i]==0){
                         g[i][deg[i]++]=j+n;
                         g[j+n][deg[j+n]++]=i;
                    }
                }
	        }

           int cnt = 0 ;
           memset(match,-1,sizeof(match)) ;
           for(int i=0;i<n;i++){
			   memset(seen,0,sizeof(seen)) ;
			   if(bpm(i)) cnt++ ;
		   }

           printf("Case %d: %d\n",++ct,cnt);
    }

    return  0  ;
}
