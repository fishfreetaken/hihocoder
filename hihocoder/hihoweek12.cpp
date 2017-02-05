#include <cstdio>

#define MAX(x,y) ((x)>(y)?(x):(y))

int f[101][101] = {}, header[101] = {};
int n, m;
struct {
	int next, to;
} tree_node[100];

void dfs(int t) {
	int p = header[t];
	int i, j;
	while(p) {
		dfs(tree_node[p].to);
		p = tree_node[p].next;
	}

	p = header[t];
	while(p) {
		for(j = m; j > 1; j--)
			for(i = 1; i < j; i++)
				f[t][j] = MAX(f[t][j], f[t][j-i] + f[tree_node[p].to][i]);
		p = tree_node[p].next;
	}
}

int ss[]={0,370, 328, 750, 930, 604, 732, 159, 167, 945, 210}; 
int sq[][2]={{0,0},{1,2},{2,3},{1,4},{1,5},{4,6},{4,7},{4,8},{6,9},{5,10}};
int main() {
	int i, from, to;
	//scanf("%d%d", &n, &m);
	//for(i = 1; i <= n; i++)
		//scanf("%d", &f[i][1]);
    n=10;
    m=4;
    for(i = 1; i <= n; i++)
        f[i][1]=ss[i];
	for(i = 1; i < n ; i++) {
		//scanf("%d%d", &from, &to);
        from=sq[i][0];
        to=sq[i][1];
		tree_node[i].to = to;
		tree_node[i].next = header[from];
		header[from] = i;
	}
	dfs(1);
	printf("%d\n", f[1][m]);
	return 0;
}

