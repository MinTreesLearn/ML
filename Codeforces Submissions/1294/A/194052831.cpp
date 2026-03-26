#include <iostream>
using namespace std;
int maxx(int a , int b)
{
     if (a>=b)
     return a ; 
    else 
    return b ; 
}
int main()
{
   int t ,a , b , c , n , max; 
   long long x ; 
   cin >> t ; 
   for (int i=0 ; i<t; i++)
   {
       cin >> a >>b >> c >> n ; 
       max=maxx(c, maxx(a, b));
       x= (max-a) + (max-b) + (max-c) ; 
       if (n>=x && (n-x)%3==0)
       cout << "YES" ; 
       else 
       cout << "NO" ; 
       
       cout << endl ; 
   }
    return 0;
}