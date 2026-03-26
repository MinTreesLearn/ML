#include <iostream>

using namespace std;

int main()
{
	int Nr;
	cin >> Nr;
	while(Nr--){
		int a , b, c, d;
		cin >> a >> b >>c >> d;
	    if((b-a)%(c+d) == 0){
			cout << (b - a) / (c + d) << endl;
		}
		else
			cout << "-1" << endl;
	}
}