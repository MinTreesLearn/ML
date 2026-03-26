#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int operation(int);
int main()
{
    int t,s,value;
    cin>>t;
    vector<int> testcases;
    for (int i = 0; i <t; i++)
    {
        cin>>value;
        testcases.push_back(value);
    }
    for (int i = 0; i <t; i++)
    {
        cout<<operation(testcases[i])<<endl;
    }    
    return 0;
}
int operation(int bal)
{
    int credit,debit,quot=0;
    int finaldebit=0;
    while (bal>=10)
    {
        credit=0,debit=0;
        quot=bal/10;
        credit=quot;
        debit=quot*10;
        finaldebit+=debit;
        bal=bal+credit-debit;
    }
    finaldebit=finaldebit+bal;
    return finaldebit;
}