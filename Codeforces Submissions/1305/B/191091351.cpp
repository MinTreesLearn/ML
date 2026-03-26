#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string brackets;
    cin >> brackets;

    int length = brackets.length();
    int left = 0, right = length - 1;
    vector<int> ans;

    while (left < right){
        while (left < right && brackets[left] == ')'){
            left++;
        }
        while (left < right && brackets[right] == '('){
            right--;
        }

        if (left < right){
            ans.push_back(left + 1);
            ans.push_back(right + 1);
        }
        left++;
        right--;
    }
    sort(ans.begin(), ans.end());
    if (ans.size() > 0){
        cout<<1<<"\n";
        cout<<ans.size()<<"\n";
        for (int index: ans){
            cout<<index<<" ";
        }
    }else{
        cout<<0<<"\n";
    }
    cout<<"\n";
    return 0;
}