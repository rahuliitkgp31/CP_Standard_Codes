//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define INF (int)1e9 + (int)1e8
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

double pi = 3.14159265358979323846264338327;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void kmp(string& str, string& substr){
    //Build pattern from substr
    vector<int> pattern(substr.size(), -1);
    int i=0;
    int j=1;
    while(j<substr.size()){
        if(substr[i]==substr[j]){
            pattern[j]=i;
            i++;
            j++;
        }
        else if(i>0){
            i = pattern[i-1]+1;
        }
        else{
            j++;
        }
    }
    // Main functionality of KMP
    vector<int> ans;
    i=0; //ptr for str
    j = 0; //ptr for substr
    while(str.size()-i+1>=substr.size()-j+1){
        if(str[i]==substr[j]){
            if(j==substr.size()-1){
                ans.push_back(i+1-substr.size());
                i=i+1-substr.size()+1;
                j=0;
                continue;
            }
            i++;
            j++;
        }
        else if(j>0){
            j = pattern[j-1]+1;
        }
        else{
            i++;
        }
    }
    for(auto& ele: ans){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main() {
    cpp();
    while(1){
        string a, b;
        if(!getline(cin, a)) break;
        if(!getline(cin,b)) break;
        kmp(b, a);
    }
    return 0;
}