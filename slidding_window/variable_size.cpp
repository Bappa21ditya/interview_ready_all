
identification:
arr/string
subarray
window size / condition given need window size
if window size given condition is asked
if condition is given  k is asked


general format/pattern for variable size window
while(j<size)
{
calculations  

if(condition<k)
{
j++;
}
else if(condition==k)
{
ans calculation
j++
}
else if(condtion>k)
{
while(condtion>k)
{
relevent calculation for i
 i++;
}
j++;
}
}
return ans





1.
#include <bits/stdc++.h>
using namespace std;
//  7, nums = [2,3,1,2,4,3]
int max_sum(int a[],int n,int k)
{
    int i=0,sum=0,mx=0;
    int j=0;
    while(j<n)
    {
        sum+=a[j];
        if(sum<k)
        {                                // 1 1 1 4     6
          j++;                           // 2 4 1 2     6
          
        }
        else if(sum==k)
        {
            if(j-i+1>mx)
              mx=j-i+1;
              
            j++;  
        }
        else if(sum>k)
        {
            while(sum>k)
            {
              sum=sum-a[i];
              i++;
                if(sum==k)
                {
                  if(j-i+1>mx)
                     mx=j-i+1;
                }
            }
            
            j++;
        }
    }
    return mx;
}
int main()
{
  int n=6;
  int a[n]={2,3,1,2,4,3};
  int k=7;
  cout<<max_sum(a,n,k)<<endl; 
}


2.Longest Substring With K Unique Characters
"aabbcc", k = 1
Max substring can be any one from {"aa" , "bb" , "cc"}.

"aabbcc", k = 2
Max substring can be any one from {"aabb" , "bbcc"}.

"aabbcc", k = 3
There are substrings with exactly 3 unique characters
{"aabbcc" , "abbcc" , "aabbc" , "abbc" }
Max is "aabbcc" with length 6.

"aaabbb", k = 3
There are only two unique characters, thus show error message. 

#include <bits/stdc++.h>
using namespace std;
int longest(string s,int n,int k)
{
    unordered_map<char,int>um;
    int i=0,j=0;
    int s1=0;
    while(j<n)
    {
        um[s[j]]++;
        
        if(k==um.size())
        {
           s1=max(s1,j-i+1);
           j++;
        }
        else if(um.size()<k)
        {
            j++;
        }
        else if(um.size()>k)
        {
            while(um.size()>k)
            {
                um[s[i]]--;
                // we need to erase it ,if not then map size will not decreases;
                // https://ide.geeksforgeeks.org/1aridjb8Yz
                  if(um[s[i]] == 0)
                     um.erase(s[i]);
                  i++;
                 if(um.size()==k)
                  {
                      s1=max(s1,j-i+1);
                   }
            }
            j++;
        }
    }
    return s1;
}
int main()
{
    string s="aabacbebebe";
    int n=s.size();
    int k=3;
    cout<<longest(s,n,k);
}

3.Longest Substring With Without Repeating Characters 
#include <bits/stdc++.h>
using namespace std;
int longest(string s,int n)
{
    unordered_map<char,int>um;
    int i=0,j=0;
    int s1=0;
    while(j<n)
    {
        um[s[j]]++;
        
        if(j-i+1==um.size())
        {
           s1=max(s1,j-i+1);
           j++;
        }
        else if(um.size()<j-i+1)
        {
            while(um.size()<j-i+1)
            {
                um[s[i]]--;
                // we need to erase it ,if not then map size will not decreases;
                // https://ide.geeksforgeeks.org/1aridjb8Yz
                  if(um[s[i]] == 0)
                     um.erase(s[i]);
                  i++;
                 if(um.size()==j-i+1)
                  {
                      s1=max(s1,j-i+1);
                   }
            }
            j++;
        }
    }
    return s1;
}
int main()
{
    string s="kwwekw";
    int n=s.size();
    cout<<longest(s,n);
}






