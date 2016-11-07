const double eps=1e-6;
const double PI=acos(-1.0);
const int maxn=110;
//typedef __int64 ll;
int le[maxn],n;
double lx[maxn],ly[maxn],slack[maxn],w[maxn][maxn],ax[maxn],ay[maxn],bx[maxn],by[maxn];
bool visx[maxn],visy[maxn];
double dist(double x1,double y1,double x2,double y2)
{
    double x=x1-x2,y=y1-y2;
    return sqrt(x*x+y*y);
}
bool match(int x)
{
    int y;
    double tp;
    visx[x]=true;
    for(y=1;y<=n;y++)
    {
        if(visy[y])
            continue;
        tp=lx[x]+ly[y]-w[x][y];
        if(tp<eps)
        {
            visy[y]=true;
            if(!le[y]||match(le[y]))
            {
                le[y]=x;
                return true;
            }
        }
        else
            slack[y]=min(slack[y],tp);
    }
    return false;
}
void update()
{
    int i;
    double d;

    for(i=1,d=INF;i<=n;i++)
        if(!visy[i])
            d=min(d,slack[i]);
    for(i=1;i<=n;i++)
    {
        if(visx[i])
            lx[i]-=d;
        if(visy[i])
            ly[i]+=d;
        else
            slack[i]-=d;
    }
}
void KM()
{
    int i,j,x;

    memset(le,0,sizeof le);
    for(i=1;i<=n;i++)
    {
        lx[i]=-INF;//注意这里!!
        ly[i]=0;
        for(j=1;j<=n;j++)
            lx[i]=max(lx[i],w[i][j]);
    }
    for(x=1;x<=n;x++)
    {
        for(i=1;i<=n;i++)
            slack[i]=INF;
        while(1)
        {
            for(i=1;i<=n;i++)
                visx[i]=visy[i]=false;
            if(match(x))
                break;
            else
                update();
        }
    }
}
int main()
{
    int i,j;

    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&ax[i],&ay[i]);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&bx[i],&by[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                w[j][i]=-dist(ax[i],ay[i],bx[j],by[j]);//这里特别注意!因为答案输出的关系
        KM();
        for(i=1;i<=n;i++)
            printf("%d\n",le[i]);
    }
    return 0;
}
