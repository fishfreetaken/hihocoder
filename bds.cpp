#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    //bool end;
    char c;
    int  pass;
    struct node *right;
    struct node *next;
};
struct node root={0};

void insert(string s,struct  node *i,int ith){
    if(ith!=s.size()){
        if(i->c==s[ith]){
            i->pass++;
            if(i->next){
                insert(s,i->next,++ith);
            }else{
                struct node *buf;
                buf=i;
                ith++;
                for(int t=ith;t<s.size();t++){
                    struct node *ct=(struct node*)malloc(sizeof(struct node));
                    ct->c=s[t];
                    ct->pass=1;
                    ct->right=NULL;
                    ct->next=NULL;
                    buf->next=ct;
                    buf=buf->next;
                }
            }
        }else{
            if(i->right){
                insert(s,i->right,ith);
            }else{
                struct node *ct=(struct node *)malloc(sizeof(struct node));
                ct->c=s[ith];
                ct->pass=1;
                ct->right=NULL;
                ct->next=NULL;
                i->right=ct;

                struct node *buf;
                buf=i->right;
                for(int t=ith+1;t<s.size();t++){
                    ct=(struct node *)malloc(sizeof(struct node));
                    ct->c=s[t];
                    ct->pass=1;
                    ct->right=NULL;
                    ct->next=NULL;
                    buf->next=ct;
                    buf=buf->next;
                }
            }
        }
    }
    return ;
}

int find(string s,struct node *i,int ith){
    if(i->c==s[ith]){
        if(ith==(s.size()-1)){
            return i->pass;
        }else{
            if(i->next){
                return find(s,i->next,++ith);
            }
        }    
    }else{
        if(i->right){
            return find(s,i->right,ith);
        }
    }
    return 0;
}

void query(string s,struct node *i){
    if(i->right){
        query(s,i->right);
    }
    string c;
    s.append(1,i->c);
    c=s;
    if(i->next){
        query(c,i->next);
    }else{
        cout<<s<<endl;
    }
}
/**将字符串改变为数字，没有进行输入的字符是否为数字的有效性检查**/
int trans(string a){ 
    int num=0;
    for(int i=0;i<a.size();i++){
        num=num*10+((int)a[i]-48);
    }
    return num;
}

int main(){
    string a;
    ifstream in("test.txt");
    if(!in.is_open()){
        cout<<"Error open file"<<endl;
        return 0;
    }
    getline(in,a);
    int num;
    num=trans(a);
    for(int i=0;i<num;i++){
        getline(in,a);
        insert(a,&root,0);
      //  cout<<a<<endl;
    }

    getline(in,a);
    num=trans(a);
    int as;
    for(int i=0;i<num;i++){
        getline(in,a);
        as=find(a,root.right,0);
        cout<<as<<endl;
    }

    in.close();

    return 0;
}
