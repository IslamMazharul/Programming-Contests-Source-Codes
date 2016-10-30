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
#define MAXN 101
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int n , m ;
string name ,str1,str2;
map<string,int>MP ;
string MMP[MAXN] ;
map<string,int>::iterator it ;
vector<int>g[MAXN] ;
int getID(string &s){
	it = MP.find(s) ;
	return it->second ;
}
int deg[MAXN] ;
int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
    #endif
	ios_base::sync_with_stdio(false) ;
	int u,v,tc=0 ;
	while(cin>>n){
		
		
		MP.clear() ;
		
		FOR(i,0,n-1){
			cin>>name ;
			MP[name] = i ;
			deg[i] = 0 ;
			MMP[i] = name ;
			g[i].clear() ;
		}
		
		cin>>m ;
		FOR(i,0,m-1){
			cin>>str1>>str2 ;
			u = getID(str1) ;
			v = getID(str2) ;
			g[u].push_back(v) ;
			deg[v]++ ;
		}
		
		cout<<"Case #"<<++tc<<": Dilbert should drink beverages in this order:" ;
		
		FOR(i,0,n-1){
			FOR(j,0,n-1){
				
				if(deg[j]==0){
					cout<<" "<<MMP[j] ;
					int siz = g[j].size()-1 ;
					FOR(k,0,siz){
						int v = g[j][k] ;
						if(deg[v]>0) deg[v]-- ;
					}
					
					deg[j] = -1 ;
					break ;
				}
			}
		}
		
		cout<<".\n\n" ;
	}
	
	return 0;
}

