#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include <fstream>
using namespace std;

int main(){
    int n,m;
    int *p,*need,*value;
    cin>>n>>m;
    //int p[m],need[n],value[n];
    need=(int*)malloc(sizeof(int)*n);
    value=(int*)malloc(sizeof(int)*n);
    p=(int*)malloc(sizeof(int)*m);

    /*
    for(int i=0;i<m;i++){
        p[i]=0;
    }*/
    for(int i=0;i<n;i++){
        cin>>need[i]>>value[i];
        for(int j=m-1;j>=need[i];j--){
            //for(int k=0;k<=j/need[i];k++){
                p[j]=max(p[j],(p[j-need[i]]+value[i]));
                if(j==m-1){
                    cout<<p[m-1]<<" "<<p[j-need[i]]<<" "<<j-need[i]<<endl;
                }
            //}
        }
    }

    cout<<p[m-1]<<endl;

    return 0;
}