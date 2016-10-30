/*
TASK:
*/
using namespace std ;
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<fstream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define maxn 1001
//#define mod

vector<int>res ;
void computeLPSArray(char *pat,int M,int *lps){

	int len = 0 ;
	int i = 1 ;
	lps[0] = 0 ;
	while(i<M){

		if(pat[i] == pat[len]){
			len++ ;
			lps[i] = len ;
			i++ ;
		}
		else{
			if(len!=0) len = lps[len-1] ;
			else{
				lps[i] = 0 ;
				i++ ;
			}
		}
	}
}

void KMPSearch(char *pat,char *txt){

	int M = strlen(pat) ;
	int N = strlen(txt) ;
	int *lps = (int *)malloc(sizeof(int)*M) ;
	int j = 0 ,i=0  ;  //the two pointers
	computeLPSArray(pat,M,lps) ;
	while(i<N){

		if(pat[j] == txt[i]) { i++ ; j++ ; }
		if(j==M) {
           // printf("MATCH FOUND\n") ;
            //cout<<j<<" "<<j-M<<"\n" ;
            res.push_back(i-M) ;
            j=lps[j-1] ;

        }
		else if(pat[j]!=txt[i]){
			if(j==0) i++ ;
			else j = lps[j-1] ;
			// Do not match lps[0..lps[j-1]] characters,
           // they will match anyway
		}
	}
}

int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    freopen("C:\\Users\\Mazhar\\Desktop\\in.txt","r",stdin) ;
    #endif
    char pat[maxn],txt[maxn] ;
    int n ;
    while(scanf("%d ",&n)==1){
        scanf("%s\n",pat) ;
        //cout<<n<<" "<<pat<<"\n" ;
        while(n--){
            gets(txt) ;
          //  cout<<txt<<"\n" ;
            res.clear() ;
            KMPSearch(pat,txt) ;
            //for(int i=0;i<res.size();i++) cout<<res[i]<<" " ;
            //cout<<"\n" ;
           int idx = 0 ,i = 0,M=strlen(pat),N=strlen(txt) ;
           while(idx<N){
                if(i<res.size() && res[i]==idx) {
                        idx+=(M) ;
                        i++ ;
                }
                else{
                    printf("%c",txt[idx]) ;
                    idx++ ;
                }
           }
           printf("\n") ;

        }

    }




    return 0 ;
}

