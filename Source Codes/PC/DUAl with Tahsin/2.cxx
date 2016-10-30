#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
int main(int argc, char **argv){
	ios::sync_with_stdio(false) ;
	int x ,res,val ;
	string line ,CIN ;
	
	// they all some things 
	
	vector<int>co ;
	while(cin>>x){
		res =  0  ;
		co.clear() ;
		getline(cin,line) ;
		getline(cin,line) ;
		stringstream CIN(line) ;
		
		while(CIN>>val){
			co.push_back(val) ;
		}
		
		int n = 1 ;
		int X = 1 ;
		
		for(int i=co.size()-2;i>=0;i--){
				res += (co[i]*n*X) ;
				X *= x ;
				n++ ; 	
		}
		
		cout<<res<<"\n" ;
	}
	
	
	return 0;
}


