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
#define MAXN 101
#define LL long long
int A[MAXN] ,B[MAXN] ;
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int F_B(int ) ;
int F_A(int ) ;
int F_B(int x){
	if(x<0) return 0 ;
	int &ref = B[x] ;
	if(ref!=-1) return ref ;
	ref = F_A(x-1)+F_B(x-2) ;
	return ref ;
}
int F_A(int x){

	if(x<0) return 0 ;
	int &ref = A[x] ;
	if(ref!=-1) return ref ;
	ref = 2*F_B(x-1)+F_A(x-2) ;
	return ref ;
}

int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	memset(A,-1,sizeof(A) ) ;
	memset(B,-1,sizeof(B) ) ;

	A[0]= 1 ;
	A[1] = 0 ;
	B[0]= 0 ;
	B[1] = 1 ;
	FOR(i,0,30){
		B[i] = F_B(i) ;
		A[i] = F_A(i) ;
	//	dp[i] = A[i-1]+B[i-2] ;
	}
	int TC ,N;
	while(cin>>N){
		if(N==-1) break ;
		if(A[N]==-1) cout<<"0\n" ;
		//	cout<<F_A(N)<<endl ;
		else cout<<A[N]<<endl ;

	}

	return 0;
}

