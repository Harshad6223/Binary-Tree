   #include <bits/stdc++.h>
#define ll  long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Sawlani
  *
  */
void initialize(ll a[],ll size[],ll n)//initializing dsu each vertex is parent of itself
{
      f(i,1,n)
       {
      a[i]=i;
      size[i]=1;
       }
}
ll root(ll a[],ll i)
{
  while(a[i]!=i)
  {
    a[i]=a[a[i]];
    i=a[i];
  }
  return i;
}
bool find(ll x,ll y,ll a[])
{
  if(root(a,x)==root(a,y))
    return true;
  else
    return false;
}
void wieghted_union(ll a[],ll size[],ll x,ll y) // union by id
{
   ll rootX=root(a,x);
   ll rootY=root(a,y);
   if(find(x,y,a))
    return ;

   if(size[rootX]<size[rootY])
   {
     size[rootY]+=size[rootX];
     a[rootX]=a[rootY];
   }
   else
   {
     size[rootX]+=size[rootY];
     a[rootY]=a[rootX];
   }
}

  int main()
 {
  ll n,m;
  cin >> n >> m;
  ll a[n+1]={0};
  ll size[n+1]={0};
    initialize(a,size,n);
  f(i,1,m)
  {
    ll x,y;
    cin >> x >> y;
    wieghted_union(a,size,x,y);
    multiset <ll> s;
    f(j,1,n)
    {
      if(a[j]==j)
      {
          s.insert(size[j]);
      }
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
  }
 }
