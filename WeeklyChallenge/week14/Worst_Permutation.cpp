#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool comp(int a, int b){
    if(a>=b) return true; return false;
}

int main() {

    map<int,int> m;
    vector<int> v, sv /*sv = sorted vector*/;
    int N, K, temp;

    cin>>N>>K;

    for(int i=0;i<N;i++){
      cin>>temp;
      v.push_back(temp);
      sv.push_back(temp);
      m[temp]=i;
    }

    sort(sv.begin(),sv.end(),comp);
    //for(int i=0; i<sv.size();i++) cout<<sv[i]<<endl;
    int ind;
    for(int i=0; i<sv.size();i++){
        if(K==0) break;
        ind = m[sv[i]];
        if(v[i]<v[ind]){
             temp = v[i];
             v[i] = v[ind];
             v[ind] = temp;
             K--;
             m[v[i]] = i;
             m[v[ind]] = ind;
        }

    /*
    cout<<"************** Debug Print **************\n";
     for(int i=0;i<v.size();i++)
    {   cout<<v[i];
        if(i<v.size()-1) cout<<" ";
    }
    cout<<endl;
    cout<<"-----------------------------------------\n";
    */

    }

    for(int i=0;i<v.size();i++)
        {   cout<<v[i];
            if(i<v.size()-1) cout<<" ";
        }
        cout<<endl;

    return 0;
}
