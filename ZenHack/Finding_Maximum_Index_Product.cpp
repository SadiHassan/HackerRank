#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int arr[100010], left[100010], right[100010], N;
    cin>>N;
    for(long int i=1; i<=N; i++) cin>>arr[i];
    left[0] = 0;
    right[N] = 0;

    for(long int i=2; i<=N; i++){
        for(long int j=i-1;j>=1;j--){
            if(arr[j]>arr[i]) {left[i]=j; break;}
            else if(arr[left[j]]>arr[i]){left[i]=left[j];break;}
            else if(left[j]==0){left[i]=0;break;}
        }
    }



    for(long int i=N-1; i>=1; i--){
        for(long int j=i+1;j<=N;j++){
            if(arr[j]>arr[i]) {right[i]=j; break;}
            else if(arr[right[j]]>arr[i]){right[i]=right[j];break;}
            else if(right[j]==0){right[i]=0;break;}
        }
    }
    /*
    cout<<"Left Right"<<endl;
    for(long int i=1; i<=N; i++){
        if(i==0)
            cout<<left[i]<<" ";
        else cout<<left[i]<<" ";

        if(i==N-1)
            cout<<right[i]<<endl;
        else cout<<right[i]<<endl;
    }*/

    //cout<<"ans..."<<endl;
    long int val = 0, ans=0;
    for(long int i=2; i<=N-1; i++){
        if(ans<left[i]*right[i])
            {
        //        val =arr[left[i]]*arr[right[i]];
                ans = (left[i])*(right[i]);
      //          cout<<val<<" "<<left[i]<<" "<<right[i]<<" "<<ans<<endl;
            }
    }

    cout<<ans<<endl;
    return 0;
}
