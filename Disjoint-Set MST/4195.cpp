#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAXX_N 200000

int t_case,relation,par[MAXX_N+1],cnt[MAXX_N+1];

int find(int node){
    if(par[node]==node)
        return node;
    return par[node]=find(par[node]);
}

void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
        return ;
    cnt[a]+=cnt[b];
    par[b]=a;
}

int main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d",&relation);
        memset(par,0,sizeof(par));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<=2*relation;i++){
            par[i]=i;
            cnt[i]=1;
        }
        
        vector<string> vt;
        vector<pair<string,string>> str;
        for(int i=0;i<relation;i++){
            string a,b;
            cin>>a>>b;
            str.push_back({a,b});
            vt.push_back(a);
            vt.push_back(b);
        }
        sort(vt.begin(),vt.end());
        vt.erase(unique(vt.begin(),vt.end()),vt.end());
        for(int i=0;i<relation;i++){
            int info1=lower_bound(vt.begin(),vt.end(),str[i].first)-vt.begin();
            int info2=lower_bound(vt.begin(),vt.end(),str[i].second)-vt.begin();
            merge(info1,info2);
            printf("%d\n",cnt[par[info1]]);
        }
    }
}
