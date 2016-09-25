#include<iostream>
using namespace std;

int N, arr[28];
string str, unique_char;
char ch;


int check_len(char a,char b){
    char now='#';
    int len = 0;
    for(int i=0; i<str.size();i++){
        if(now=='#'){
            if(str[i]==a || str[i]==b)
                now = str[i];
                len = 1;
        }
        else{

            if(str[i]==a && now==b){ len++; now=a;}
            else if(str[i]==b && now==a){ len++; now=b;}
            else if(str[i]==a || str[i]==b) return 0;
        }
    }

    return len;
}

int main(){

str="";
unique_char = "";

for(int i=0; i<27; i++) arr[i]=0;

cin>>N;

for(int i=0; i<N; i++){
    cin>>ch;
    str += ch;
    if(arr[ch-'a']==0) unique_char+=ch;
    arr[ch-'a']+=1;
}

int ans = 0;

for(int i=0; i<unique_char.size();i++)
    for(int j=i+1; j<unique_char.size();j++){
        ans = max(ans,check_len(unique_char[i],unique_char[j]));
    }

cout<<ans<<endl;
return 0;
}
