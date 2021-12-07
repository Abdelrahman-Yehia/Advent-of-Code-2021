#include <bits/stdc++.h>

using namespace std;

void part1(vector<vector<vector<int>>> boards, vector<int> numbers){

}

void part2(){

}
int main() {
    vector<vector<vector<int>>> boards;
    vector<int> numbers;
    while(true){
        int in ;
        cin >> in;
        char comma;
        cin >> comma;
        if(comma=='#')
            break;
        numbers.push_back(in);
    }

    while(true){
        vector<vector<int>> b(5,vector<int>(5));
        bool done = 0;
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                cin >> b[i][j];
                if(b[i][j]==-123){
                    done = 1;
                    break;
                }
            }
            if(done) break;
        }
        boards.push_back(b);
        if(done) break;
    }
}