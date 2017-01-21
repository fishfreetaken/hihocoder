#include <iostream>
#include <string>
using namespace std;
struct node{
	char a;
	struct node *left;
	struct node *right;
}root;

void fid(string a,string b,string *st){
	int j=0;int s=2;
	for(int i=0;i<b.size();i++){
		if(b[i]!=a[0]){
			*(st+s)+=b[i];
		}else{
			j=i;
			s++;
		}
	}
	for(int i=1;i<a.size();i++){
		if(i<=j){
			*(st+0)+=a[i];
		}else{
			*(st+1)+=a[i];
		}
	}
}
void mag(string a,string b,struct node *t){
	string st[4];
	t->a=a[0];
	if(a.size()||b.size()){
		fid(a,b,st);
		t->left=(struct node*)malloc(sizeof(struct node));
		t->right=(struct node*)malloc(sizeof(struct node));
		mag(st[0],st[2],t->left);
		mag(st[1],st[3],t->right);
	}
}
void ctf(struct node *t){
	if(t->left->a){
		ctf(t->left);
	}
	if(t->right->a){
		ctf(t->right);
	}
	cout<<t->a;
}
int main()
{
	string ad,mid,lat;
	cin>>ad>>mid;
	mag(ad,mid,&root);
	ctf(&root);
	return 0;
}
