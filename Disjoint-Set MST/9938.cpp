#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXX_N 300000

int drink,folder,check[MAXX_N+1],par[MAXX_N+1];

int find(int node){
    if(par[node]==node)
        return node;
    return par[node]=find(par[node]);
}

void merge(int a,int b){
    a=find(a);
    b=find(b);
    
    par[a]=b;
    puts("LADICA");
}

int main(){
    scanf("%d%d",&drink,&folder);
    
    for(int i=1;i<=folder;i++)
        par[i]=i;
    
    for(int i=1;i<=drink;i++){
        int info1,info2;
        scanf("%d%d",&info1,&info2);
        if(!check[info1]){
            check[info1]=1;
            merge(info1,info2);
        }
        else if(!check[info2]){
            check[info2]=1;
            merge(info2,info1);
        }
        else if(!check[find(info1)]){
            check[find(info1)]=1;
            merge(find(info1),info2);
        }
        else if(!check[find(info2)]){
            check[find(info2)]=1;
            merge(find(info2),info1);
        }
        else puts("SMECE");
    }
}
