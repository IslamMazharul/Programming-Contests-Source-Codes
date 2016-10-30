#include <bits/stdc++.h>
using namespace std ;
#define LL long long
#define MAXN 2*100000+10
map<char,string>mp ;
#define mod 1000003
int main(void){

    freopen("in.txt","r",stdin) ;
    mp['>'] = "1000" ;
    mp['<'] = "1001" ;
    mp['+'] = "1010" ;
    mp['-'] = "1011" ;
    mp['.'] = "1100" ;
    mp[','] = "1101" ;
    mp['['] = "1110" ;
    mp[']'] = "1111" ;
    string num = "" ;
    char ch ;
    while(cin>>ch){
        num.append(mp[ch]) ;
    }


    LL res = 0 ,p=1;
    for(int i=num.size()-1;i>=0;i--){
            LL tmp = (p*(num[i]-'0') )%mod;
            res = ( res + tmp)%mod ;
            p = (p*2)%mod ;
    }
    cout<<res<<endl ;
    return 0 ;
}

