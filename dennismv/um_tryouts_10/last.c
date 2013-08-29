#include <stdio.h>

typedef long long ll;

int n, i, j;
ll x[1000], g;

ll gcd( ll a, ll b )
{
	while( b != 0 )
	{
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		for(i=0;i<n;i++) scanf("%lld",&x[i]);
		for(i=0;i<n;i++) for(j=i+1;j<n;j++)
		{
			g=gcd(x[i],x[j]);
			x[j]=x[i]*x[j]/g;
			x[i]=g;
		}
		printf("%lld",x[0]);
		for(i=1;i<n;i++) printf(" %lld",x[i]);
		printf("\n");
	}
	return 0;
}
