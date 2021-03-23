#include <bits/stdc++.h>
using namespace std;
class Solution {
private: int vis[20][20]={0};
private: vector<int> tmp;
vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmp.push_back(0);
        dfs(graph,0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph,int x){
        if(x == graph.size() - 1){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < graph[x].size(); i++){
                tmp.push_back(graph[x][i]);
                dfs(graph,graph[x][i]);
                tmp.pop_back();
        }
    }
};

