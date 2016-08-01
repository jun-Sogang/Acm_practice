#include <cstdio>
#include <vector>
#include <algorithm>
#define maxnode 10001
using namespace std;
 
vector < int > outdegree[maxnode];
int parent[maxnode];
int depth[maxnode];
vector < vector < int > > v;
int flag=1;
void inorder(int start,int dep)
{
    if(start==-1)
        return ;
    depth[start]=dep+1;
    inorder(outdegree[start][0],depth[start]);
	v[depth[start]].push_back(flag++);
    inorder(outdegree[start][1],depth[start]);
}
int find_parent(int start)
{
    int temp=start;
    while(parent[temp] != -1)
    {
        temp=parent[temp];
    }
    return temp;
}
int main()
{
    int n;
     
    scanf("%d",&n);
	v.resize(n + 1);
	for(int i=0; i<n+1; i++)
        parent[i]=-1;
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(b!=-1)
        {
            outdegree[a].push_back(b);
            parent[b]=a;
        }
        else
            outdegree[a].push_back(-1);
        if(c!= -1)
        {
            outdegree[a].push_back(c);
            parent[c]=a;
        }
        else
            outdegree[a].push_back(-1);
    }
     
    inorder(find_parent(n),0);
	int ans = 0, ans_level = 0;
	for (int i = 1; i < n+1; i++)
	{
		sort(v[i].begin(), v[i].end());
		if (v[i].size() == 1)
		{
			if (ans < 1)
			{
				ans = 1;
				ans_level = 1;
			}
		}
		else if (v[i].size() == 0)
			continue;
		else
		{
			if (v[i].back() - v[i].front()+1 > ans)
			{
				ans = v[i].back() - v[i].front()+1;
				ans_level = i;
			}
		}
	}
    
    printf("%d %d\n",ans_level,ans);
    return 0;
}