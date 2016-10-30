//Bismillahir Rahmanir Rahim
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
#define MAXN 1000+7
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int T,CT=1,n ;
	double nao[MAXN],ken[MAXN] ;
	cin>>T ;
	while(T--){
		cin>>n ;
		FOR(i,0,n-1){
			cin>>nao[i] ;
		}
		FOR(i,0,n-1){
			cin>>ken[i] ;
		}
		sort(nao,nao+n) ;
		sort(ken,ken+n) ;
		int res1 = 0 ,res2 =0 ;
		FOR(i,0,n-1){

			if(nao[i]>ken[i]) res1++ ;
			//if(nao[i]>ken[n-i-1]) res2++ ;
		}

		cout<<res1<<" "<<res1<<"\n" ;
	}

	return 0;
}


