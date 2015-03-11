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

    for(v=1;v<=N;v++)
        if(v!=S&&arr[S].find(v)==arr[S].end()) d[v] = 1;
        else d[v]=2;



    for(long int i=1; i<=N; i++){
        if(i!=S) cout<<d[i];
        if(i<N&&i!=S) cout<<" ";
    }

    cout<<endl;

    }

    return 0;
}
