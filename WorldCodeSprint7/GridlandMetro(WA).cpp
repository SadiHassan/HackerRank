#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stdio.h>
#define LD uint64_t
//uint64_t
using namespace std;

struct train{
    LD c1, c2;
};

bool compare(train ob1, train ob2){
    if(ob1.c1 == ob2.c1) return (ob1.c2 <= ob2.c2);
    return (ob1.c1 < ob2.c1);
}


map< LD , vector<train> > m;

int main(){

LD N, M, K, map_len;
LD r, c1, c2;

//freopen("in.txt","r",stdin);
map_len = 0;

cin>>N>>M>>K;

for(LD i=0; i<K; i++){
    cin>>r>>c1>>c2;

    if(c1>c2){
        LD temp;
        temp = c1;
        c1 = c2;
        c2 = temp;
    }

    train ob;
    ob.c1 = c1;
    ob.c2 = c2;

    if(m.find(r)==m.end()){
        map_len++;
        vector<train> v;
        v.push_back(ob);
        m[r] = v;
        //m[r].swap(v);
    }
    else m[r].push_back(ob);
}

LD total_gap = 0, gap=0;

for (std::map< LD , vector<train> >::iterator it=m.begin(); it!=m.end(); ++it){

    vector<train> v;
    v = it->second;

    sort( v.begin(), v.end() , compare);

    //cout<<it->first<<" --> ";
    gap = v[0].c1 - 1 ;

    for(int i=1; i<v.size();i++){
        if(v[i].c1 > v[i-1].c2)
            gap = gap + v[i].c1 - v[i-1].c2 - 1;
        //cout<<v[i].c1<<","<<v[i].c2<<" --> "<<gap<<" # ";
        //cout<<v[i].c1<<","<<v[i].c2<<" --> "<<gap<<" # ";
    }
    gap = gap + M - v[ v.size()-1 ].c2;
    //cout<<endl;

    total_gap += gap;
}

//cout<<m.size()<<endl;
/*
for(LD i=1; i<=N; i++)
    if(m.find(i)==m.end()) total_gap += M;
cout<<total_gap<<endl;
*/
cout<< ( total_gap+ (LD) ( (LD) (N - map_len)*M ) ) <<endl;
return 0;
}
