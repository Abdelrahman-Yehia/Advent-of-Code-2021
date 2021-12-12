#include <bits/stdc++.h>

using namespace std;


map<string, vector<string>> adjList;
map<string, int> visited;

bool isBig(string s){
    return (toupper(s[0]) == s[0]);
}

void dfs(string currNode, int &paths , int part){
    if(currNode == "end"){
        paths++;
        return;
    }

    if(!isBig(currNode)){
        if(part == 2)
            visited[currNode]++;
        else
            visited[currNode] = 1;
    }

    int twos = 0;
    for(auto x: visited){
        if(x.second > 1)
            twos++;
    }

    if(twos > 1){
        visited[currNode]--;
        return;
    }

    for(auto x: adjList[currNode]){
        if(x != "start"){
            if(part == 1 && visited[x] < 1){
                dfs(x,paths,part);
            }
            else if(part == 2 && visited[x] < 2)
                dfs(x,paths,part);
        }
    }
    visited[currNode]--;
}

void part1(){
    int paths = 0;
    dfs("start", paths,1);
    cout <<"Part 1: " <<" "<< paths << endl;
}

void part2(){
    visited.clear();
    int paths = 0;
    dfs("start", paths, 2);
    cout << "Part 2: " << paths << endl;
}
int main() {
    while(true){
        string s;
        cin >> s;
        if(s == "#")
            break;
        int dash = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '-'){
                dash = i;
                break;
            }
        }
        string u,v;
        u = s.substr(0,dash);
        v = s.substr(dash+1);
        //cout << u << " " << v << endl;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    part1();
    part2();
}