#include <iostream>
#include <fstream> 
#include <map>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;


int main() {
    string text;
    ifstream Input("input.txt");
    vector<int> a,b;
    map<int,int> mp;
    int result = 0;
    while (getline (Input, text)) {
        int pos = text.find("   ");
        string first = text.substr(0,pos);
        string second = text.substr(pos + 1);
        a.push_back(stoi(first));
        b.push_back(stoi(second));
        mp[stoi(first)] = 0;
        // cout << first << " " << second << " " << "\n";
    };
    Input.close();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0; i < a.size(); i++)
    {
        result += abs(a[i] - b[i]);
    }
    cout << result << + "\n";
    for (auto i : b)
    {
        if(mp.find(i) != mp.end())
        {
            mp[i] += 1;
        }
    }
    int count = 0;
    for (auto i : mp)
    {
        count += i.first * i.second;
    }
    cout << count << "\n";
    return 0;
}

