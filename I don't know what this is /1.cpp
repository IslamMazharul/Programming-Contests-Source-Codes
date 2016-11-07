#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
#define MOD 1000000007
#define LD long double
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

LD dp[2003][2003];

int main()
{
 //   freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
 freopen("A-large-practice.in","r",stdin) ;
    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        for(int i=0;i<=2000;i++)for(int j=0;j<=2000;j++)dp[i][j]=0;

        int n=getnum(),m=getnum();
        dp[1][0]=(LD)(n)/(LD)(n+m);


        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(i-1>j)dp[i][j]=(dp[i-1][j]*(LD)(n-i+1)/(LD)(n-i+1+m-j));
                dp[i][j]+=(dp[i][j-1]*(LD)(m-j+1)/(LD)(n-i+m-j+1));
            }
        }

        cout<<"Case #"<<cases<<": "<<fixed<<setprecision(12)<<dp[n][m]<<'\n';
    }


}
