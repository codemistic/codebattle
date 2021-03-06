#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INT_MAX 2147483647
#define DIST(x,y,x1,y1) (((x-x1)*(x-x1))+((y-y1)*(y-y1)))
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second<p2.second;
}
bool compp(pair<pair<int, int>, int > p1, pair<pair<int, int>, int > p2)
{
    if(p1.first.first!=p2.first.first)
    return p1.first.first<p2.first.first;
    return p1.first.second<p2.first.second;
}
int main()
{
 int i,j,n,t,d,d1;
 scanf("%d",&t);
 vector<pair<pair<int, int>, int> >v(30000);
 vector<pair<int, int> > r(30000);
 vector<pair<int, int> > ctr(30000);
 while(t--)
 {
    scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d %d",&v[i].first.first, &v[i].first.second);
  v[i].second=i;
  r[i].first=INT_MAX;
  ctr[i].first=0;
 }

 sort(v.begin(),v.begin()+n, compp);
 for(i=0;i<n;i++)
 {
   r[i].second=v[i].second;
   ctr[i].second=v[i].second;
   
   if(i!=0)
   {
   d=DIST(v[i].first.first, v[i].first.second, v[i-1].first.first, v[i-1].first.second);
   r[i].first=d;
   }
   if(i!=n-1)
   {
   d=DIST(v[i].first.first, v[i].first.second, v[i+1].first.first, v[i+1].first.second);
   if(d<r[i].first)
   r[i].first=d;
   }
   for(j=i-2;j>=0&&(v[j].first.first-v[i].first.first)*(v[j].first.first-v[i].first.first)<r[i].first;j--)
   {
      d=DIST(v[j].first.first,v[j].first.second,v[i].first.first,v[i].first.second);
      if(r[i].first>d)
      r[i].first=d;
   }
   for(j=i+2;j<n&&(v[j].first.first-v[i].first.first)*(v[j].first.first-v[i].first.first)<r[i].first;j++)
   {
      d=DIST(v[j].first.first,v[j].first.second,v[i].first.first,v[i].first.second);
      if(d<r[i].first)
      r[i].first=d;
   }
   d=4*r[i].first;
   for(j=i-1;j>=0&&(v[j].first.first-v[i].first.first)*(v[j].first.first-v[i].first.first)<=d;j--)
   {
      if(DIST(v[i].first.first,v[i].first.second,v[j].first.first,v[j].first.second)<=d)
      ctr[i].first++;
   }
   for(j=i+1;j<n&&(v[j].first.first-v[i].first.first)*(v[j].first.first-v[i].first.first)<=d;j++)
   {
      if(DIST(v[i].first.first,v[i].first.second,v[j].first.first,v[j].first.second)<=d)
      ctr[i].first++;
   }
 }
   sort(r.begin(),r.begin()+n,comp);
   sort(ctr.begin(),ctr.begin()+n,comp);
  for(i=0;i<n;i++)
  printf("%0.2f %d\n", sqrt((float)r[i].first), ctr[i].first);
  printf("\n");
  }
 return 0;
}
