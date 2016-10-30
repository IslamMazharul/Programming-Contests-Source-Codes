#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
int main(int argc, char **argv){
	
	
	ios::sync_with_stdio(false) ;
	int T ,Len1,Len2;
	string s1,s2 ;
	
	cin>>T ;
	vector<int>res ;
	
	while(T--){
		
		res.clear() ;	
		cin>>s1>>s2;
		Len1 = s1.length() ;
		Len2 = s2.length() ;
		
		FOR(i,0,Len1/2-1){
			swap(s1[i],s1[Len1-1-i]) ;
		}
		
		FOR(i,0,Len2/2-1){
			swap(s2[i],s2[Len2-1-i]) ;
		}
	//	cout<<s1<<" "<<s2<<"\n" ;
		int sum,carry = 0 ;
		for(int i=Len1-1,j=Len2-1;i>=0 || j>=0 ;i--,j-- ){
			sum = carry ;
			//cout<<s1[i]<<" "<<s2[j]<<"\n" ;
			
			if(i>=0) sum += (s1[i]-'0') ;
			if(j>=0) sum += (s2[j]-'0') ;
			res.push_back(sum%10) ;
			carry = sum/10 ;
		}
		
		while(carry>0){
			res.push_back(carry%10) ;
			carry  /= 10 ;
		}
		bool zero = 0 ;
		FOR(i,0,res.size()-1){
			if(res[i]==0){
				if(zero) cout<<"0" ;
			}  else {
				zero = 1 ;
				cout<<res[i] ;
			}
		}
		
		cout<<"\n" ; 
	}
	
	return 0;
}


