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
#define MAXN 100
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int n,Q,val[MAXN] ;
int dp[222][20][20][11] ;  //idx + divisor + rem + taken

int call(int idx,int div,int rem,int taken){

		if(taken>11) return 0 ;
		if(idx==n) return 1 ;
		int &ref = dp[idx][div][rem][taken] ;
		if(ref!=-1) return ref ;

		dp[idx][div][rem][taken] = call(idx+1,div,rem,taken)  +     call(idx+1,div,(rem+val[idx])%div,taken+1) ;
}

int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int tc = 1 ;
	while(cin>>n>>Q){
		if(!n && !Q) break ;
		FOR(i,0,n-1){
			cin>>val[i] ;
		}
		memset(dp,-1,sizeof(dp)) ;
		FOR(i,1,20){
			call(0,i,0,0) ;
		}

		int div,taken ;
		cout<<"SET"<<tc++<<":\n" ;
		FOR(i,1,Q){
			cin>>div>>taken ;
			cout<<call(0,div,0,taken)<<"\n" ;
		}
	}


	return 0;
}

