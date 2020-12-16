#include<bits/stdc++.h>
using namespace std;
string father;
map<string,string> parent;
string findParent(string son){
	while(parent[son]!=son){
		son=parent[son];
	}
	return son;
}
void join(string f,string s){
	string f_p=findParent(f);
	string s_p=findParent(s);
	if(s_p!=f_p){
		parent[s_p]=f_p;
	}
}
int main(){
	string name;
	while(cin>>name,name[0]!='$') {
		string son=name.substr(1);
		if(name[0]=='#'){
			father=name.substr(1);
			if(parent[father]=="")
				parent[father]=father;
		}else if(name[0]=='+'){
			if(parent[son]=="")
				parent[son]=son;
			join(father,son);
		}
		else{
			cout<<son<<" "<<parent[son]<<endl;
		}
	}
}

