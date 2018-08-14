#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXX_N 100000

int gate,plane,par[MAXX_N+1],cnt;

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
    par[b]=a;
}

int main(){
    scanf("%d%d",&gate,&plane);
    for(int i=1;i<=gate;i++)
        par[i]=i;
    
    for(int i=0;i<plane;i++){
        int num;
        scanf("%d",&num);
        int find_num=find(num);
        if(!find_num)
            break;
        else{
            merge(find_num-1,find_num);
            cnt++;
        }
    }
    printf("%d",cnt);
}
