#include<bits/stdc++.h>

using namespace std;

int MAX, MIN;
int a[100];
void maxmin(int i, int j)
{
 int max1, min1, mid;
 if(i==j)
 {
  MAX = MIN = a[i];
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    MAX = a[j];
    MIN = a[i];
   }
   else
   {
    MAX = a[i];
    MIN = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   maxmin(i, mid);
   max1 = MAX; min1 = MIN;
   maxmin(mid+1, j);
   if(MAX <max1)
    MAX = max1;
   if(MIN > min1)
    MIN = min1;
  }
 }
}
int main ()
{
 int i, num;
 cout<<"Enter the total number of numbers : ";
 cin>>num;
 cout<<"Enter the numbers : "<<endl;
 for (int i=1;i<=num;i++)
    cin>>a[i];

 MAX = a[1];
 MIN = a[1];
 maxmin(1, num);
 cout<<"Minimum element in an array : "<< MIN<<endl;
 cout<<"Maximum element in an array : "<< MAX;
 return 0;
}
