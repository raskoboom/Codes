#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<deque>
using namespace std;
int total=0;
#define nn 10004
//int table[nn][3]={0};
vector<int> table[nn];
int color[nn]={0};
deque<int> path[nn];
void color_it(int node,int parent,int game=0){
	color[node]=1;
	int first_child=0,second_child=0;
	if(game==0){path[total].push_back(node);}
	else {path[total].push_front(node);}
        for(int i=0;i<table[node].size();i++){
		if(color[table[node][i]]==0 && first_child==0 && table[node][i]!=parent){color_it(table[node][i],node,game);first_child=1;}
		else if(color[table[node][i]]==0 && second_child==0 && table[node][i]!=parent){color_it(table[node][i],node,1);second_child=1;}
	}
}
void find_path(int node,int root,int parent){
	int first_child=0,second_child=0;
	for(int i=0;i<table[node].size();i++){
		if(table[node][i]!=parent)
			find_path(table[node][i],1,node);
	}
	for(int i=0;i<table[node].size();i++){
		if(table[node][i]!=parent){
			if(color[table[node][i]]==0 && first_child==0)first_child=1;
			else if(color[table[node][i]]==0 && second_child==0)second_child=1;
		}	
	}
	if(first_child==1 && second_child==1){color_it(node,parent,0);total++;}
	for(int i=0;i<table[node].size();i++){
		if(table[node][i]!=parent){
			if(color[table[node][i]]==0 && first_child==1 && second_child==1){color_it(table[node][i],node,0); total++;}
		}
	}
	if(node==root && color[node]==0){color_it(node,0,0);total++;}
	 
}
int main(){
	int t=0,a,b;
	cin>>t;
	while(t--){
		long int n=0;
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			//table[b][0]=a;
			table[b].push_back(a);
			table[a].push_back(b);	
		}
		find_path(1,1,0);
		cout<<total<<"\n";
		for(int i=0;i<total;i++){
			for(int j=path[i].size()-1;j>=0;j--){
				cout<<path[i][j];
				if(j!=0)cout<<" ";
			}
			cout<<"\n";
		}
		for(int i=0;i<n+1;i++)table[i].clear();
		memset(color,0,sizeof(color));
		for(int i=0;i<total;i++)path[i].clear();
		total=0;
	}
}
