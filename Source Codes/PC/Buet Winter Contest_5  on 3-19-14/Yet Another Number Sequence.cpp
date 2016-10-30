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
#define MAXN
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define MOD 1000000007
#define LL long long
struct MATRIX{
	LL a[5][5] ;
};

MATRIX UNIT,ZERO ;
MATRIX MULTI(MATRIX A,MATRIX B){
	MATRIX ret ;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ret.a[i][j] = 0 ;
			for(int k=0;k<4;k++){
				ret.a[i][j] +=( (A.a[i][k]*B.a[k][j]) % MOD ) ;
				ret.a[i][j] %=MOD ;
			}
		}
	}
	return ret ;
}

MATRIX BigMod(MATRIX M,int pow){
	if(pow==0) return ZERO ;

	else if(pow%2){
		MATRIX ret = BigMod(M,pow-1) ;
		return MULTI(ret,UNIT) ;
	}
	else{

		MATRIX ret = BigMod(M,pow/2) ;
		return MULTI(ret,ret) ;
	}
}

int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;


	return 0;
}


