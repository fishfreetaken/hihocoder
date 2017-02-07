#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("test.txt");

    int N,M,id=0; char strbuf[1024];
    N=11;
    vector<string> fns,sns,names;
    map<string,int> all;
    
    string s;
    for(int j=0;j<N;j++){
        string fn,sn;
        getline(in,s);
        int i=0;
        while(s[i]!=' '){
            fn+=s[i];
            i++;
        }
        i++;
        while(i!=s.size()){
            sn+=s[i];
            i++;
        }
        fns.push_back(fn);sns.push_back(sn);
        all[fn] = 0;all[sn] = 0;
    }
	
	for(map<string,int>::iterator ite = all.begin(); ite != all.end(); ite++) {
		names.push_back(ite->first); ite->second = id++;
	}
	vector<int> pid(id,-1);
	for(int i = 0; i < N; i++) pid[all[sns[i]]] = all[fns[i]];
	M=3;
	for(int j = 0; j < M; j++) {
		string s1,s2;
		int i=0;
        while(s[i]!=' '){
            s1+=s[i];
            i++;
        }
        i++;
        while(i!=s.size()){
            s2+=s[i];
            i++;
        }
		
		int a=-1,b=-1;
		if(all.count(s1)) a = all[s1];
		if(all.count(s2)) b = all[s2];
		
		if(a==-1 || b==-1) {
			if(s1==s2) printf("%s\n",s1.c_str());
			else printf("-1\n");
		} else {
			vector<int> mask(id,1);
			while(a>-1) {mask[a] = 0;a = pid[a];}
			while(b>-1&&mask[b]) b = pid[b];
			if(b>-1) printf("%s\n",names[b].c_str());
			else printf("-1\n");
		}
	}

    in.close();
	return 0;
}
