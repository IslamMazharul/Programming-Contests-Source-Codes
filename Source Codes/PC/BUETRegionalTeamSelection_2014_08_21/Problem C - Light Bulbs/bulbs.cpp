#include <iostream>
#include <cstring>

const int ND=128;
const int NB=512;

int toDec(int *v,char *s)
{
	int len,n,x;
	for(x=0;x<ND;x++) v[x]=0;
	n=0;
	len=strlen(s);
	len--;
	while(len>=0)
	{
		v[n]=s[len]-'0';
		len--; n++;
	}
	return n;
}

bool zero(int *v,int n)
{
	return n==1 && v[0]==0;
}

int maxi(int x,int y)
{
	return x>=y?x:y;
}

int div(int *v,int &vn,int q)
{
	int r,x;
	x=vn-1;
	r=0;
	while(x>=0)
	{
		r=(10*r+v[x]);
		v[x]=r/2;
		r=r%2;
		x--;
	}
	while(vn>1 && v[vn-1]==0) vn--;
	return r;
}

int toBin(int *v,int vn,int *b)
{
	int x,bn;
	for(x=0;x<NB;x++) b[x]=0;
	bn=0;
	while(!zero(v,vn))
	{
		b[bn]=div(v,vn,2);
		/*
		cout<<"v: ";
		for(int i=vn-1;i>=0;i--) cout<<v[i];
		cout<<endl;
		*/
		bn++;
	}
	return bn;
}

bool less(int *a,int *b,int n)
{
	int x;
	for(x=n-1;x>=0;x--)
	if(a[x]!=b[x]) return a[x]<b[x];
	return false;
}

void cpy(int *to,int *fr,int n)
{
	int x;
	for(x=0;x<NB;x++) to[x]=0;
	for(x=0;x<n;x++) to[x]=fr[x];
}

void fix(int *v,int &n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(v[i]>=10)
		{
			v[i+1]+=v[i]/10;
			if(i+1==n) n++;
			v[i]%=10;
		}
	}
}

void mult2(int *v,int &n)
{
	int x;
	for(x=0;x<n;x++) v[x]+=v[x];
	fix(v,n);
}

int BintoDec(int *d,int *b,int bn)
{
	int dn,x,i;
	for(x=0;x<ND;x++) d[x]=0;
	dn=1;

	for(x=bn-1;x>=0;x--)
	{
		mult2(d,dn);
		d[0]+=b[x];
		fix(d,dn);
	}
	return dn;
}

int main()
{
	int A[ND],B[ND],ANS[ND];
	int a[NB],b[NB],c[NB],r[NB],ans[NB];
	int An,Bn,Cn,an,bn,cn,n,i,j,x,y;
	bool poss,valid;
	int min,cost,len;
	char as[ND],bs[ND];
	int cc;
	
	cc=1;
	while(std::cin>>as>>bs)
	{
		if(cc>1) std::cout<<std::endl;

		An=toDec(A,as);
		Bn=toDec(B,bs);
		//cout<<"check 1 "<<endl;
		if(zero(A,An) && zero(B,Bn)) break;
		an=toBin(A,An,a);
		bn=toBin(B,Bn,b);
		n=maxi(an,bn);
		
		//cout<<"check!"<<endl;
		std::cout<<"Case Number "<<cc<<": ";
		cn=n;
		if(cn==1)
		{
			if(a[0]==b[0]) std::cout<<0<<std::endl;
			else std::cout<<1<<std::endl;
		}
		else
		{
			poss=false;
			min=NB+10;
			

			for(c[0]=0;c[0]<=1;c[0]++)
			for(c[1]=0;c[1]<=1;c[1]++)
			{
				for(x=0;x<NB;x++) r[x]=0;
				for(x=0;x<an;x++) r[x]=a[x];

				if(c[0]) 
				{
					r[0]=1-r[0];
					r[1]=1-r[1];
				}
				if(c[1]) 
				{
					r[0]=1-r[0];
					r[1]=1-r[1];
					r[2]=1-r[2];
				}
				cost=c[0]+c[1];
				
				valid=false;
				if(r[0]==b[0])
				{
					valid=true;
					for(x=2;x<n;x++)
					{
						if(r[x-1]==b[x-1])
						{
							c[x]=0;
						}
						else
						{
							c[x]=1;
							cost++;
							r[x-1]=1-r[x-1];
							r[x]=1-r[x];
							if(x+1<n) r[x+1]=1-r[x+1];
						}
					}
					if(r[n-1]!=b[n-1]) valid=false;
				}
				if(valid)
				{
					poss=true;
					if(cost<min || cost==min && less(c,ans,n))
					{
						min=cost;
						cpy(ans,c,n);
					}
				}
			}//end (c[0],c[1])=(0,0)..(1,1)

			if(poss)
			{
				len=BintoDec(ANS,ans,n);
				for(len--;len>=0;len--)
				{
					std::cout<<ANS[len];
				}
				std::cout<<std::endl;
			}
			else
			{
				std::cout<<"impossible"<<std::endl;
			}
		}

		cc++;
	}

	return 0;
}