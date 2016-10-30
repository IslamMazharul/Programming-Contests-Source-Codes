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
#define MAXN 15
#define LL long long
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
LL hash[MAXN] ;

int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
    string line,word ;
    int n ;
    LL C ;
    bool blank = false ;
    while(getline(cin,line)){
			if(blank){
				cout<<"\n" ;
			}
			else blank = true ;
			stringstream strin(line) ;
			n = 0 ;
			C = 10000000000LL ;

			while(strin>>word){

				LL hashing = 0 ;
				LL pow = 1 ;
				for(int i=word.length()-1;i>=0;i--){
					hashing +=((word[i]-'a'+1)*pow) ;
					pow = pow<<5 ;
				}

				hash[n++] = hashing ;
				C = min(C,hashing) ;
				//cout<<word<<" "<<17247663%hash<<endl ;
			}

			bool ok  ;
			int i,j ;
			while(1){
					ok = true ;
					for( i=0;i<n;i++){
						for( j=i+1;j<n;j++){
							if ( ( (C/hash[i]) %n )==( (C/hash[j]) %n) ){
									C = min ( (C/hash[i]+1)*hash[i] , ( C/hash[j] + 1 )*hash[j] ) ;
									i  = n ;
									j = n ;
									ok = 0 ;
									break ;
							}
						}

					}

					if(ok) {
                        break ;
					}
			}
			cout<<line<<"\n"<<C<<"\n" ;
    }

	return 0;
}

