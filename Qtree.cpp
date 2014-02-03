#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define nn 10004
long int total=0;
vector<long int> table[nn][2];
long int euler_route[2*nn+3][2];
int level[2*nn+3]={0};
int h[nn]={0};
bool before[nn]={0};
void path(int a,int b){
	for(int i=0;i<2*n-1;i++){
		if(h[euler_tour[i][0]]==-1){
			h[euler_tour[i][0]=i]
		}
	}
}
void euler_tour(int root,int node,int parent,int index){
	//cout<<node<<" ";
	euler_route[total][0]=node;
        euler_route[total][1]=table[parent][1][index];
	for(int i=0;i<table[node][0].size();i++){
		if(table[node][0][i]!=parent){
			//cout<<node<<" ";
			total++;
			//cout<<
			euler_tour(root,table[node][0][i],node,i);
			total++; 
			euler_route[total][0]=node;
			euler_route[total][1]=table[node][1][i];	
		}
	}
}
void get_level(int n){
	before[1]=1;
	for(int i=1;i<(2*n-1);i++){
		if(before[euler_route[i][0]]==0){
			before[euler_route[i][0]]=1;
			level[i]=level[i-1]+1;
		}
		else{
			level[i]=level[i-1]-1;
		}
	}
}
int main(){
	string input;
	long int t=0,a,b,c,n;
	cin>>t;
	while(t--){
		cin>>n;
                table[1][0].push_back(0);
		table[1][1].push_back(0);
		table[0][1].push_back(0);
		table[0][0].push_back(1);
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			table[a][0].push_back(b);
			table[b][0].push_back(a);
			table[a][1].push_back(c);
			table[b][1].push_back(c);
		}
		euler_tour(1,1,0,0);
		get_level(n);
		for(int i=0;i<(2*n-1);i++){
			cout<<euler_route[i][0]<<" "<<level[i]<<"\n";
			cout<<"\n";
		}
		cout<<"going up the country";
		cin.get();
		while(1){
			getline(cin,input);
			if(input[0]=='D' && input[1]=='O'){
				break;	
			}
		}
	}
}
