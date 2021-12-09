#include <bits/stdc++.h>


using namespace std;

vector<string> grid;
int rows, cols;  //Dimensions of the grid

//The 4 directions of adjacent cells
int dx[] = {-1, +1, +0, +0};
int dy[] = {+0, +0, -1, +1};


//graph Node representing coordinates of cell in the grid
struct node{
    int x, y;
};


//Validate that the node being checked is within the grid borders
bool valid(int x, int y){
    return !(x < 0 || x >= rows || y < 0 || y >= cols);
}

//Part 1 returns a vector of nodes to be used in part 2;
vector<node> part1(){
    vector<int> lowPoints;
    vector<node> compStart;     //Vector saves the low points as starting points for connected components to used in part 2
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            int cnt = 0; // number of adjacent points higher than current
            int all = 0; // number of all adjacent points
            for(int k = 0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(!valid(x,y))  //Check if point is inside the grid
                    continue;

                all++;
                if(grid[i][j] < grid[x][y])
                    cnt++;
            }
            if(cnt == all){
                lowPoints.push_back(grid[i][j] - '0');
                node v;
                v.x = i;
                v.y = j;
                compStart.push_back(v); // save position of low point
            }
        }
    }
    int sum = 0;
    for(auto x: lowPoints){
        sum += x + 1;
    }
    cout << "Part 1: " << sum << endl;
    return compStart;
}

vector<vector<bool>> vis; //Visited array to mark visited nodes


void dfs(node currNode, int & sum){
    vis[currNode.x][currNode.y] = 1;
    sum++; // Incerement the size of basin (Connected component)

    for(int i = 0;i<4;i++){
        int x = currNode.x + dx[i];
        int y = currNode.y + dy[i];

        //Checks if point is a valid neighbour
        if(!valid(x,y) || vis[x][y] || grid[x][y] == '9' || grid[x][y] < grid[currNode.x][currNode.y])
            continue;
        node child;
        child.x = x;
        child.y = y;
        dfs(child, sum);
    }
}

void part2(vector<node> compStart){

    vis = vector<vector<bool>> (rows,vector<bool> (cols));

    vector<int> largestBasins;

    //Start DFS from each low points (start connected component) to calculate size of basin (connected component)
    for(auto v: compStart){
        int compSum = 0;
        dfs(v, compSum);
        largestBasins.push_back(compSum);
    }
    sort(largestBasins.begin(),largestBasins.end());
    int ans = 1;
    for(int i = 0 ;i < 3;i++){
        ans *= largestBasins[largestBasins.size() - i - 1];
    }
    cout << "Part 2: " << ans << endl;
}
int main() {
    while(true){
        string row;
        cin >> row;
        if(row == "#")  //Enter # at the end of Input
            break;
        grid.push_back(row);
    }
    rows = grid.size();
    cols = grid[0].length();
    part2(part1());
}