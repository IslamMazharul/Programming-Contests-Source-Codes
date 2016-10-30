#include <bits/stdc++.h>
#define MAXN 1000007 
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
bool sieve[MAXN] ;
int n ;
vector<int>v ;
bool isPalidrome(int base){
	
	
	v.clear() ;
	int num =  n ;
	
	while(num>0){
		int d = num%base ;
		num /=base ;
		v.push_back(d) ;
	}
	
	int Len = v.size()-1 ;
	bool ret  = 1 ;
	//cout<<base<<" : " ;
	//FOR(i,0,Len) cout<<v[i] ;
	//cout<<"\n" ;
	
	FOR(i,0,Len/2){
		if(v[i]!=v[Len-i]) ret = 0 ;
	}
		
	return ret ;	
}

int main(int argc, char **argv){
	ios::sync_with_stdio(false) ;
	while(cin>>n){
		
		int res = 0 ;
		memset(sieve,0,sizeof(sieve)) ;
		
		FOR(i,2,n-1){
			
			if(!sieve[i]){
				bool ret = isPalidrome(i) ;
				if(!ret){
					for(int j = i ;  ; j*=i){
						if(j>=n)  break ;
						sieve[j] = 1 ;
					}
				}
				
				else{
					res = i ;
					break ;
				}
			}
		}
		
		cout<<res<<"\n" ;
	}
	
	return 0;
}


