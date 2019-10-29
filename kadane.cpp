#include <bits/stdc++.h>
#define ll long long
using namespace std;
int f(int a[], int n){
    int maxendhere=1, minendhere=1, maxfar=1;
    int flag=0;
    for (int i = 0; i < n; ++i)
    {
        if(a[i]>0){
            maxendhere*=a[i];
            minendhere=min(minendhere*a[i], 1);
            flag=1;
        }
        else if(a[i]==0){
            maxendhere=1;
            minendhere=1;
        }
        else{
            int t=maxendhere;
            maxendhere=max(1, minendhere*a[i]);
            minendhere=t*a[i];
        }
        if(maxfar<maxendhere){
            maxfar=maxendhere;
        }
    }
    if(flag==0){
        if(maxfar==1){
            return 0;
        }
    }
    return(maxfar);
}
int main(){
int n;
cin>>n;
int a[n];
for (int i = 0; i < n; ++i)
{
    cin>>a[i];
}
cout<<f(a, n);
return 0;
}
