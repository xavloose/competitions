#include <stdio.h>

typedef long long ll;

int n, r[1000], i;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		for(i=0;i<n;i++) scanf("%d",&r[i]);
		ll ans = 0;
		int l = 0;
		for(i=0;i<n;i++)
		{
			if(!r[i])
			{
				ans += l*(l+1)/2;
				l = 0;
			}
			else l++;
		}
		ans += l*(l+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
