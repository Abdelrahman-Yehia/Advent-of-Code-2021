#include <bits/stdc++.h>


using namespace std;

const int N = 2e5 + 5;

const long long mod = 1e9+7;

long long power(long long a, long long  b, long long mod)
{
    if(!b)
        return 1ll;
    if(b == 1)
        return a%mod;
    long long r = power(a, b/2ll,mod)%mod;
    if(b%2ll)
        return ((r*(a%mod)%mod)*r)%mod;
    else
        return (r*r)%mod;

}


void part1(vector<string> input){
    bitset<30> gamma;
    bitset<30> epsilon;

    int len = input[0].length();
    for(int i = 0;i < len;i++){
        int zeros = 0, ones = 0;
        for(int j = 0;j < input.size();j++){
            if(input[j][len-1-i] == '1')
                ones++;
            else zeros++;
        }
        int maxi = 1, mini = 0;
        if(zeros>ones){
            maxi = 0;
            mini = 1;
        }

        gamma[i] = maxi;
        epsilon[i] = mini;
    }

    long long gammaVal = 0;
    long long epsVal = 0;

    for(int i = 0;i<30;i++){
        gammaVal += gamma[i] * power(2,i,mod);
        epsVal += epsilon[i] * power(2,i,mod);
    }


    long long ans = gammaVal * epsVal;
    cout << "Part 2: " << ans << endl;
}


long long calcO2(vector<string> input){

    int len = input[0].length();
    int removed = 0;
    while(true){
        for(int i = 0;i<len;i++){
            int zeros = 0, ones = 0;
            for(int j = 0;j < input.size();j++){
                if(input[j] == "#") {
                    continue;
                }
                if(input[j][i] == '1') {
                    ones++;
                }
                else zeros++;
            }
            int maxi;
            if(zeros <= ones){
                maxi = 1;
            }
            else maxi = 0;
            for (auto &j : input) {
                if(j == "#") {
                    continue;
                }
                if(removed == input.size()-1) {
                    break;
                }
                if(j[i] - '0' != maxi){
                    j = "#";
                    removed++;
                }
            }
        }
        if(removed == input.size() - 1) {
            break;
        }
    }

    long long o2 = 0;
    for(int i = 0;i < input.size();i++){
        if(input[i] == "#") {
            continue;
        }

        for(int j = 0; j<len;j++){
            int bit = input[i][len-j-1] - '0';
            o2 += power(2,j,mod) * bit;
        }
    }
    return o2;
}


long long calcCo2(vector<string> input){

    int len = input[0].length();
    int removed = 0;
    while(true){
        for(int i = 0;i<len;i++){
            int zeros = 0, ones = 0;
            for(int j = 0;j<input.size();j++){
                if(input[j] == "#"){
                    continue;
                }
                if(input[j][i] == '1')
                    ones++;
                else zeros++;
            }
            int mini;
            if(zeros <= ones){
                mini = 0;
            }
            else mini = 1;
            for (auto &j : input) {
                if(j == "#")
                    continue;
                if(removed == input.size() - 1)
                    break;
                if(j[i] - '0' != mini){
                    j = "#";
                    removed++;
                }
            }
        }
        if(removed == input.size() - 1)
            break;
    }

    long long co2 = 0;
    for(int i = 0;i<input.size();i++){
        if(input[i] == "#")
            continue;
        for(int j = 0; j<len;j++){
            int bit = input[i][len-j-1] - '0';
            co2 += power(2,j,mod) * bit;
        }
    }
    return co2;
}
void part2(vector<string> input){
    cout << "Part 2: " << calcO2(input) * calcCo2(input) << endl;
}



int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    // int t;
    //cin >> t;
    //while(t--)
    vector<string> numbers;
    while(true){
        string in;
        cin >> in;
        if(in == "#")
            break;
        numbers.push_back(in);
    }
    part1(numbers);
    part2(numbers);

    return 0;
}