#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
typedef long long LL ;
int main(int argc, char **argv){
	ios::sync_with_stdio(false) ;
	vector<int>v ;
	LL val ,prev;
	int n ;  
	while(cin>>n>>val){
		v.clear() ;
		if(n==1) {
			cout<<"1\n" ;
			continue ;
		}
		int cur = 1 ;
		FOR(i,0,n-2){
			prev = val ;
			cin>>val ;
			if(val>=prev) cur++ ;
			else {
				v.push_back(cur) ;
				cur = 1 ;
			}
		}
		
		//if(cur!=1) 
		v.push_back(cur) ;
		
		int res = v[0] ;
		FOR(i,1,v.size()-1){
			res = max(res,v[i-1]+v[i]) ;
		}
		
		cout<<res<<"\n" ; 
	}
	return 0;
}


