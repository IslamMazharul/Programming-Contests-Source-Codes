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
string num ;
int Len ;
bool isDivisible(int n){

	int pow = 1 ;
	int mod = 0 ;
	for(int j=Len;j>=0;j--){
		mod += ( (num[j]-'0')*(pow)  )% n  ;
		mod %=n ;
		pow = (pow*10)%n ;
	}
	return mod==0? 1 : 0 ;
}
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int N,T ;
	bool res ;
	int val ;
	cin>>T ;
	while(T--){

		cin>>num ;
		Len = num.length()-1 ;
		cin>>N ;
		res = true ;
		while(N--){
				cin>>val ;
				if(res){
					res = isDivisible(val) ;
				}
		}

		res?cout<<num<<" - Wonderful.\n":cout<<num<<" - Simple.\n" ;
	}

	return 0;
}


