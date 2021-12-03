#include <bits/stdc++.h>


using namespace std;

const int N = 2e5 + 5;


void solve(){
    int x = 0, y = 0, aim = 0;
    while(true){
        string dir;
        cin >> dir;
        if(dir == "#")
            break;
        int amt;
        cin >> amt;
        if(dir == "forward"){
            x+=amt;
            y += (aim*amt);
        }
        else if(dir=="up")
            aim-=amt;
        else
            aim+=amt;
    }

    cout << x * y << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    // int t;
    //cin >> t;
    //while(t--)
    solve();


    return 0;
}