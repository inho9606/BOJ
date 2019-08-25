#include<iostream>
#define MAX = 1000000
using namespace std;
bool c[MAX+1]; 
int main()
{
c[0] = c[1] = true;
for(int i=2; i*i<=MAX; i++)
{
if(c[i] == false)
{
for(int j=i*i; j<=MAX; j=j+i)
c[j] = true;
}
}
int m,n;
cin >> m >> n;
for(int i=m; i<=n; i++)
{
if(c[i]==false)
cout<<i<<'\n';
}
return 0;
}