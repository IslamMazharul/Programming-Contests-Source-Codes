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
#define MAXN 100+10
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int r,c ;
int M[MAXN][MAXN] ,DP[MAXN][MAXN];
string name ;
int dx[] = {1,-1,0,0} ;
int dy[] = {0,0,1,-1} ;
inline bool out(int x,int y){
	if(x<0 || y<0 || x>=r || y>=c) return true ;
	return false ;

}
int call(int x,int y){

	int &ref = DP[x][y] ;
	if(ref!=-1) return ref ;
	ref = 0 ;

	FOR(i,0,3){
		int new_x = x+dx[i] ;
		int new_y = y+dy[i] ;
		if(out(new_x,new_y) ) continue ;
		if(M[x][y]>M[new_x][new_y]){
			ref = max(ref,call(new_x,new_y)) ;
		}
	}
	ref++ ;
	return ref ;
}
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
    int testcases ;
    cin>>testcases ;
    while(testcases--){
			cin>>name>>r>>c ;
			FOR(i,0,r-1){
				FOR(j,0,c-1){
					cin>>M[i][j] ;
				}
			}

			memset(DP,-1,sizeof(DP)) ;
			int res= - 1 ;
			FOR(i,0,r-1){
				FOR(j,0,c-1){
					res = max(res,call(i,j)) ;
				}
			}

			cout<<name<<": "<<res<<"\n" ;
    }

	return 0;
}

