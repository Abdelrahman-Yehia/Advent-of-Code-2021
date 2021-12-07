#include <bits/stdc++.h>


using namespace std;



void part1(vector<int> numbers){
    int cnt = 80;
    while(cnt>0){
        int currLen = numbers.size();
        for(int i = 0;i<currLen;i++){
            if(numbers[i]==0){
                numbers.push_back(8);
                numbers[i] = 6;
            }
            else numbers[i]--;
        }
        cnt--;
    }
    cout << numbers.size() << endl;
}





void part2(vector<int> numbers){
    int days = 256;
    vector<long long> freq(9);
    for(auto x: numbers)
        freq[x]++;

    for(int i = 0;i<256;i++){
        rotate(freq.begin(),freq.begin()+1,freq.end());
        freq[6] += freq[8];
    }
    long long ans = 0;
    for(auto x: freq)
        ans += x;
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    //cin >> t;
    //while(t--)
    string s;
    cin >> s;
    vector<int> numbers;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ',')
            continue;
        int x = s[i] - '0';
        numbers.push_back(x);
    }
    //solve();
    part1(numbers);
    part2(numbers);
    return 0;
}