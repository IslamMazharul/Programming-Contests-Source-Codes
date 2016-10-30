#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
char get(string s){
	
	
	if(s==".-") return 'A' ;
	if(s=="-...") return 'B' ;
	if(s=="-.-.") return 'C' ;
	if(s=="-..") return 'D' ;
	if(s==".") return 'E' ;
	if(s=="..-.") return 'F' ;
	if(s=="--.") return 'G' ;
	if(s=="....") return 'H' ;
	if(s=="..") return 'I' ;
	if(s==".---") return 'J' ;
	if(s=="-.-") return 'K' ;
	if(s==".-..") return 'L' ;
	if(s=="--") return 'M' ;
	if(s=="-.") return 'N' ;
	if(s=="---") return 'O' ;
	if(s==".--.") return 'P' ;
	if(s=="--.-") return 'Q' ;
	if(s==".-.") return 'R' ;
	if(s=="...") return 'S' ;
	if(s=="-") return 'T' ;
	if(s=="..-") return 'U' ;
	if(s=="...-") return 'V' ;
	if(s==".--") return 'W' ;
	if(s=="-..-") return 'X' ;
	if(s=="-.--") return 'Y' ;
	if(s=="--..") return 'Z' ;
	
	if(s=="..--") return '_' ;
	if(s==".-.-") return ',' ;
	if(s=="---.") return '.' ;
	if(s=="----") return '?' ;
	return 0 ; 
	
}
string  get1(char c){
	
	
	
	if(c=='A') return ".-" ; 
	if(c=='B') return "-..." ; 
	if(c=='C') return "-.-." ;
	if(c=='D') return "-.." ;
	if(c=='E') return "." ;
	if(c=='F') return "..-." ;
	if(c=='G') return "--." ;
	if(c=='H') return "...." ;
	if(c=='I') return ".." ;
	if(c=='J') return ".---" ;
	if(c=='K') return "-.-" ;
	if(c=='L') return ".-.." ;
	if(c=='M') return "--" ;
	if(c=='N') return "-." ;
	if(c=='O') return "---" ;
	if(c=='P') return ".--." ;
	if(c=='Q') return "--.-" ;
	if(c=='R') return ".-." ;
	if(c=='S') return "..." ;
	if(c=='T') return "-" ;
	if(c=='U') return "..-" ;
	if(c=='V') return "...-" ;
	if(c=='W') return ".--" ;
	if(c=='X') return "-..-" ;
	if(c=='Y') return "-.--" ;
	if(c=='Z') return "--.." ;
	if(c=='_') return "..--" ;
	if(c==',') return ".-.-" ;
	if(c=='.') return "---." ;
	if(c=='?') return "----" ;
	return 0 ; 
	
}
int main(int argc, char **argv){
	ios::sync_with_stdio(false) ;
	string line ;
	vector<char>mc,res ;
	vector<int>num ;
	while(getline(cin,line)){
		
		mc.clear() ;
		res.clear() ;
		num.clear() ;
		FOR(i,0,line.length()-1){
			string s   = get1(line[i]) ;
			//cout<<line[i]<<" "<<s<<"\n" ;
			num.push_back(s.length()) ;
			FOR(j,0,s.length()-1) mc.push_back(s[j]) ;
		}
		
		int cur = 0 ;
		//FOR(i,0,num.size()-1) cout<<num[i] ;
		//cout<<"----------\n" ;
		bool end = 0 ;
		for(int i=num.size()-1;i>=0;i--){
			if(end) break ;
		//	cout<<num[i] ;
			string temp  = "" ;
			FOR(k,0,num[i]-1) {
					temp.push_back(mc[cur]) ;
					cur++ ;
			}
			//cout<<temp<<" "<<get(temp)<<"\n" ;
			res.push_back(get(temp)) ;
		}
		
		FOR(i,0,res.size()-1) cout<<res[i] ;
		cout<<"\n" ;
		
	}
	
	return 0;
}


