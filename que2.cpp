#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter the height and width\n";
    int x,y;
    cin>>x>>y;
    cout<<"enter the number of bad node\n";
    int n;
    cin>>n;
    cout<<"enter the bad blocks\n";
    int a,b,c,d,e[x+1][y+1];
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++){
        e[i][j]=0;}}
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        if(a==c+1)
            e[a][b]==10;
        else if(b==d+1)
            e[a][b]==11;
        else if(a==c-1)
            e[c][d]=10;
        else
            e[c][d]=11;
    }
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++) for(int j=0;j<=y;j++) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {

            if(j>=1&&e[i][j]!=11)
                dp[i][j]+=dp[i][j-1];

            if(i>=1&&e[i][j]!=10)
                dp[i][j]+=dp[i-1][j];
        }
    }
    cout<<"ans\n";
    cout<<dp[x][y]<<endl;

    return 0;
}

