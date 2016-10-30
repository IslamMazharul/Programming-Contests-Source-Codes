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
//#define maxn
//#define mod
int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    //freopen("E:\\in.txt","r",stdin) ;
    #endif
    string str1,str2 ;
    int cnt[27] ;
    while(cin>>str1>>str2){
        memset(cnt,0,sizeof(cnt)) ;
        FOR(i,0,str1.length()-1) cnt[str1[i]-'a']++ ;
        bool yes = true ;
        FOR(i,0,str2.length()-1){
            if(cnt[str2[i]-'a']!=0) cnt[str2[i]-'a']++ ;
            else{
                yes = false ;
                break;
            }
        }
        yes?cout<<"YES\n":cout<<"NO\n" ;
    }




    return 0 ;
}

