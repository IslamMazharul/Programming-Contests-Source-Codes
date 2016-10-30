#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define MAXN 1000+10
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int n,dp[MAXN],dir[MAXN] ;
struct ELEPANT{
	int w,s,id ;
};
ELEPANT e[MAXN] ;
bool comp(ELEPANT a, ELEPANT b){

    return a.w < b.w;
}
int call(int u){

	int &ref = dp[u] ;
	if(ref!=-1) return ref ;
	ref = 1 ;
	FOR(i,u+1,n-1){

		if(e[u].w<e[i].w && e[u].s>e[i].s){
			int siz = call(i)+1 ;
			if(siz>ref){

				ref = siz ;
				dir[u] = i ;
			}
		}
	}


	return ref ;
}
void solution(int u){

	while(dir[u]!=-1){
		cout<<e[u].id+1<<endl ;
		u = dir[u] ;
	}
	cout<<e[u].id+1<<endl ;
}
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	n = 0 ;
	while(cin>>e[n].w>>e[n].s){
			e[n].id = n ;
			n++ ;
	}

	sort(e,e+n,comp) ;
	memset(dp,-1,sizeof(dp)) ;
	memset(dir,-1,sizeof(dir)) ;
	int res = 0 ;
	int start = 0 ;
	FOR(i,0,n-1){
		//cout<<dp[i]<<endl ;
		if(res<call(i)){
			res = call(i) ;
			start = i ;
		}
	}

	cout<<res<<endl ;
	solution(start) ;

	return 0;
}

