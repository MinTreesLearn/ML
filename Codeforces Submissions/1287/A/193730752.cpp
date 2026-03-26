/*▄███████▀▀▀▀▀▀███████▄
░▐████▀▒▒▒▒▒▒▒▒▒▒▀██████▄
░███▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀█████
░▐██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
░▐█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
░░█▒▄▀▀▀▀▀▄▒▒▄▀▀▀▀▀▄▒▐███▌
░░░▐░░░▄▄░░▌▐░░░▄▄░░▌▐███▌
░▄▀▌░░░▀▀░░▌▐░░░▀▀░░▌▒▀▒█▌
░▌▒▀▄░░░░▄▀▒▒▀▄░░░▄▀▒▒▄▀▒▌
░▀▄▐▒▀▀▀▀▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒█
░░░▀▌▒▄██▄▄▄▄████▄▒▒▒▒█▀
░░░░▄█████████████  █▒▒▐▌
░░░▀███▀▀████▀█████▀▒▌
░░░░░▌▒▒▒▄▒▒▒▄▒▒▒▒▒▒▐
░░░░░▌▒▒▒▒▀▀▀▒▒▒▒▒▒▒▐*/
#include <bits/stdc++.h>  //{بسم الله الرحمن الرحمن الرحيم}
#define Amogus_elzengy ios::sync_with_stdio(0);cin. tie(0);
#define ll long long
#define pb  push_back
#define ppb  pop_back
#define pf  push_front
#define ppf pop_front
using namespace std;
void mortada_mansor()
{
   int k,time;
   string students,prev,c;
   cin>>k>>students;
do{
     prev=students;
     c=students;
    for (int i = 0; i < k-1; ++i) {
        if(students[i]=='A')
        {c[i+1]='A';}
    }
    students=c;
    if(prev!=students)
time++;
}
while(prev!=students);
cout<<time<<endl;
}
int main () {
    Amogus_elzengy
    ll t;
    cin>>t;
    while(t--)
    {
        mortada_mansor();
    }
    return 0;
}
	   	 			  		  		   	  	 			 	