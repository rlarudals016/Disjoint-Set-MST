#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXX_N 1000000

int n,m,par[MAXX_N+1];

int find(int node){
    if(par[node]==node)
        return node;
    return par[node]=find(par[node]);
}

void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    par[a]=b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        par[i]=i;
    for(int i=0;i<m;i++){
        int qu,info1,info2;
        scanf("%d%d%d",&qu,&info1,&info2);
        if(!qu)
            merge(info1,info2);
        else{
            if(find(info1)==find(info2))
                puts("YES");
            else
                puts("NO");
        }
    }
    
}
