#include <bits/stdc++.h>
using namespace std;

struct Node{
    set<int> child;
    int par = -1;
    int depth = 0;
};

vector<int> smallest;

int check(int n, int d, int n1){
    int ln1 = n1*(n1-1);
    ln1 /= 2;
    int l1 = d-(n-1)-ln1;
    int r1 = d-(n-1)-smallest[n1];
    int l2 = smallest[n-1-n1];
    int r2 = (n-1-n1)*(n-2-n1);
    r2 /= 2;
    // cout << "called: " << n << " " << d << " " << n1 << " " << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
    if(max(l1,l2) <= min(r1,r2)){
        return max(l1,l2);
    }
    return -1;
}

int go(int n, int d, vector<Node>& arr,int& curr){
    // cout<<n<<" "<<d<<" "<<curr<<endl;
    int root = curr++;
    for(int i=0;i<n;i++){
        int d2 = check(n,d,i);
        if(d2 != -1){
            if(i!=n-1){
                int lchild = go(n-i-1,d2,arr,curr);
                arr[root].child.insert(lchild);
                arr[lchild].par = root;
                // cout<<"lchild: "<<lchild<<" "<<root<<endl;
            }
            if(i!=0){
                int rchild = go(i,d+1-n-d2,arr,curr);
                arr[root].child.insert(rchild);
                arr[rchild].par = root;
                // cout<<"rchild: "<<rchild<<" "<<root<<endl;
            }
            break;
        }
    }
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int sm = 0;
        int add = 0;
        int currp = 0;
        int cnt = 0;
        smallest.resize(n+1);
        for(int i=1;i<=n;i++){
            cnt++;
            sm += add;
            smallest[i] = sm;
            if(cnt == (1<<currp)){
                cnt = 0;
                currp++;
                add++;
            }
            // cout << smallest[i] << " ";
        }
        // cout << "\n";
        // cout << check(5,7,3);
        vector<Node> arr(n);
        int curr = 0;
        bool done = 0;
        int root = curr++;
        for(int n1=0;n1<n;n1++){
            int d2 = check(n,d,n1);
            if(d2 != -1){
                done = 1;
                if(n1!=n-1){
                    int lchild = go(n-n1-1,d2,arr,curr);
                    arr[root].child.insert(lchild);
                    arr[lchild].par = root;
                }
                if(n1!=0){
                    int rchild = go(n1,d+1-n-d2,arr,curr);
                    arr[root].child.insert(rchild);
                    arr[rchild].par = root;
                }
                break;
            }
        }
        if(!done){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i=1;i<n;i++){
                cout<<arr[i].par+1<<" ";
            }
            cout<<"\n";
        }

    }
    
    return 0;   
}