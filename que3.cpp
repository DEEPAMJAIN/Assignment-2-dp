#include<bits/stdc++.h>
using namespace std;

#define forp(i,a,n) for(int i=(a);i<(n);i++)



int loope(int dp[],int r,int k)
{
	int mid,l=-1;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(dp[mid]>=k)
		{
			r=mid;
		}
		else
			l=mid;
	}
	return r;
}

int loop(int a[],int n)
{
	int dp[n];
	int d=1;
	dp[0]=a[0];

	for(int i=1;i<(n);i++)
	{
		if(a[i]<dp[0])
		{
			dp[0]=a[i];
		}
		else if(a[i]>dp[d-1])
		{
			dp[d]=a[i];
			d++;
		}
		else
		{
			dp[loope(dp,d-1,a[i])]=a[i];
		}
	}

	return d;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n+5];
		forp(i,0,n){
			cin>>a[i];
			a[i+n]=a[i];
		}
		int maximum=0;
		forp(i,0,n)
            maximum=max(maximum,loop(a+i,n));
        cout<<maximum<<endl;
	}
}
