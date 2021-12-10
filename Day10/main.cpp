#include <bits/stdc++.h>

using namespace std;

map<char, int> score;
map<char, long long> score2;
map<char,char> closeBracket;

char open[] =  {'(', '{', '[', '<'};
char close[] = {')', '}', ']', '>'};

bool existOpen(char c){
    for(int i = 0;i<4;i++){
        if(open[i] == c)
            return true;
    }
    return false;
}

bool existClose(char c){
    for(int i = 0;i<4;i++){
        if(close[i] == c)
            return true;
    }
    return false;
}

vector<long long> part1(vector<string> lines){

    int ans = 0;
    vector<long long> part2Scores;
    for(auto s: lines){
        int sc = 0;
        long long sc2 = 0;
        
        stack<char> currLine;
        for(auto c: s){
            if(existOpen(c)){
                currLine.push(c);
            }

            else if(existClose(c)){

                if(closeBracket[currLine.top()] != c){
                    sc += score[c];
                }

                currLine.pop();
            }
        }

        ans += sc;
        while(!currLine.empty() && sc == 0){
            sc2 *= 5;
            sc2 += score2[closeBracket[currLine.top()]];
            currLine.pop();
        }

        if(sc2 != 0)part2Scores.push_back(sc2);
    }

    cout << "part 1: " << ans << endl;
    return part2Scores;
}

void part2(vector<long long> sc){

    sort(sc.begin(),sc.end());

    cout << "part 2: " << sc[sc.size()/2] << endl;
}
int main() {

    closeBracket['('] = ')';
    closeBracket['{'] = '}';
    closeBracket['['] = ']';
    closeBracket['<'] = '>';

    score[')'] = 3;
    score[']'] = 57;
    score['}'] = 1197;
    score['>'] = 25137;

    score2[')'] = 1;
    score2[']'] = 2;
    score2['}'] = 3;
    score2['>'] = 4;

    vector<string> lines;
    while(true){
        string in;
        cin >> in;
        if(in == "#")
            break;
        lines.push_back(in);
    }
    part2(part1(lines));
    return 0;
}