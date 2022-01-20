# Find the latest library
#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void versioncheck(string s, vector<string>& v) {
    int start = 0;
    int end = s.find('.');
    while (end != string::npos) 
    {
        v.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find('.', start);
    }
    v.push_back(s.substr(start));
}
void check(string s, string t)
{
    vector<string> l1;
    vector<string> l2;
    versioncheck(s, l1);
    versioncheck(t, l2);

    bool flag = false;
    int i = 0, j = 0;
        int n = l1.size(), m = l2.size();
        while (i < n && j < m) {
            if (l1[i] == l2[j]) {
                i++;
                j++;
            } else {
                flag = true;
                if (l1[i] > l2[j])  cout <<"\nNewer library is : "<< s << endl ;
                else cout <<"\nNewer library is : "<< t << endl;
                break;
            }
        }
        if (!flag)
        {
              if(j == m)  cout << "\nNewer library is : "<< s << endl ;
              else cout << "\nNewer library is : "<<t << endl;
        }
}
int main() {
    int n;
    cout<<"\n Enter total pairs: ";
    cin>>n;
    while(n--)
    {
        string s, t;
        cout<<"Enter the 1st library: ";
        cin >> s;
        cout<<"\nEnter the 2nd library: ";
        cin>> t;
        if (s.empty() || t.empty())
            cout << max(s, t) << endl;
        else 
            check(s,t);   
    }
    return 0;
}
