#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iomanip>
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
#define MAXN 101
#define inf 100000000
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int N,M,a[11][111],dp[11][111] ;
int call(int course,int hours){

	if(hours>M) return -inf ;
	if(course==N){
		if(hours==M) {
			return 0 ;
		}

		return -inf ;
	}

	if(dp[course][hours]!=-1) return dp[course][hours] ;

	int ret  = -inf,F;
	FOR(i,0,M-1){

		if(a[course][i]<5) continue ;
		F = call(course+1,hours+i+1)+ a[course][i] ;
		ret = max(ret,F) ;

	}



	dp[course][hours] = ret ;
	return dp[course][hours] ;
}

int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
        freopen("out.txt","w",stdout) ;
    #endif
	ios_base::sync_with_stdio(false) ;
	int T ;
	cin>>T ;
	while(T--){
		cin>>N>>M ;
		memset(dp,-1,sizeof(dp)) ;

		FOR(i,0,N-1){
			FOR(j,0,M-1){
				cin>>a[i][j] ;
			}
		}

		int res = call(0,0) ;
		if(res<0){
			cout<<"Peter, you shouldn't have played billiard that much."<<"\n" ;
			continue ;
		}

		double avg = double(res)/double(N) ;
		cout<<"Maximal possible average mark - ";
		cout<<fixed<<setprecision(2)<<avg+1e-9<<".\n" ;
		////////////////////////////////////////////
		//Adding only 1e-9 is giving AC
	}


	return 0;
}

