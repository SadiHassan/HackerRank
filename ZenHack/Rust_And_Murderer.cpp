#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

long int T, N, M, d[500005];
map<long int, bool> arr[500005];
bool visited[500005];

int main() {

    long int x, y, S, u, v;
    cin>>T;
    for(long int t=1; t<=T; t++){

        cin>>N>>M;

        for(long int m=1; m<=M; m++){
            cin>>x>>y;
            arr[x][y] = true;
            arr[y][x] = true;
        }

    cin>>S;

    /*
    cout<<"-------------"<<endl;
    for(long int i=1; i<=N; i++){
        cout<<i<<" : ";
        for(long int j=1; j<=N; j++)
            if(arr[i].find(j)!=arr[i].end())
                cout<<j<<" ";
        cout<<endl;

    }
    cout<<"-------------"<<endl;
    */

    //fill_n(&d[1],N,0);
    fill_n(&visited[1],N,false);
    /*
    for(int i=1; i<=N; i++)
        cout<<i<<" --> "<<d[i]<<" "<<visited[i]<<endl;
    */
    queue<long int> Q;

    d[S] = 0;
    Q.push(S);
    visited[S] = true;

    while(!Q.empty()){

        u = Q.front();
        Q.pop();

        for(v=1; v<=N; v++){

            //if(visited[v]) continue;

            if(arr[u].find(v)==arr[u].end()&&visited[v]==false){
                Q.push(v);
                d[v] = d[u]+1;
                visited[v] = true;
            }

        }
    }

    for(long int i=1; i<=N; i++){
        if(i!=S) cout<<d[i];
        if(i<N&&i!=S) cout<<" ";
    }

    cout<<endl;

    }

    return 0;
}
