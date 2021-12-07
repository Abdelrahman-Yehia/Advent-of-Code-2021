#include <bits/stdc++.h>


using namespace std;



long long calcFuel(vector<int> numbers, int pos, bool part){
    long long fuel = 0;
    for(auto x : numbers){
        long long n = abs(pos - x);
        if(part){
            n = n*(n+1)/2;
        }
        fuel += n;
    }
    return fuel;
}


void part1(vector<int> numbers){
    numbers.push_back(55);
    sort(numbers.begin(),numbers.end());
    int start = numbers[0], endd = numbers[numbers.size()-1];


    long long mini = 1e12;
    long long minCost = -1;
    for(int i = start;i<=endd;i++){
        long long curr = calcFuel(numbers,i,0);
        if(curr < mini){
            mini = curr;
            minCost = i;
        }
    }
    cout << mini << endl;
}





void part2(vector<int> numbers){
    numbers.push_back(55);
    sort(numbers.begin(),numbers.end());
    int start = numbers[0], endd = numbers[numbers.size()-1];


    long long mini = 1e12;
    long long minCost = -1;
    for(int i = start;i<=endd;i++){
        long long curr = calcFuel(numbers,i,1);
        if(curr < mini){
            mini = curr;
            minCost = i;
        }
    }
    cout << mini << endl;
}

int toInt(string s){
    stringstream ss;
    ss << s;
    int num;
    ss >> num;
    return num;
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
    int lastComma = -1;
    for(int i = 0;i<s.length();i++){
        int curr;
        if(s[i] == ','){

            string currNum = s.substr(lastComma+1,i - lastComma - 1);
            curr = toInt(currNum);
            numbers.push_back(curr);
            lastComma = i;
        }
    }
    //solve();
    part1(numbers);
    part2(numbers);
    return 0;
}