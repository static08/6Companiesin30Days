//Find max 10 numbers in a list having 10M entries.
#include<bits/stdc++.h>
using namespace std;

// METHOD 1: BRUTE FORCE 
// Sorting the array in desending and returning the first 10 elements
// Time Complexity : O(nlogn)
void maxTen(vector<int>& nums, int k)
{
      int n = nums.size();
      sort(nums.begin(),nums.end(),greater<int>());
      
      for(int i=0; i<k; i++)
          cout<<" "<<nums[i];
  
      return;
}

// METHOD 2 : USING MIN HEAP
// By maintaining a min heap of size 10
// Time Complexity : O(nlogk) , k = 10

void maxTen(vector<int>& nums, int k)
{
      int n = nums.size();
      priority_queue<int,vector<int>,greater<int>>p;
      for(int i=0; i<n; i++)
      {
          if(p.size() <= k)
          {
              p.push(nums[i]);
          }
          else
          {
              p.pop();
              p.push(nums[i]);
          }
      }
  
      while(!p.empty())
      {
          cout << p.top() << " ";
          p.pop();
      }
      cout << "\n";
      return;
}

int main()
{
    vector<int> nums;
    int k;
    cin>>k;
    for(int i=0; i<10000000; i++)
    {
        int x ;
        cin>>x;
        nums.push_back(x);
    }
    
    solve(nums,k);
    return 0;
}
