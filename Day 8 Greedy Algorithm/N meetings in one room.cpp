// Problem Link :- https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Solved by sorting (w.r.t start time) and iterating from the back
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(start[i], end[i]);
        }
        
        sort (vec.begin(), vec.end());
        
        int meetings = 1, last = vec[n - 1].first;
        
        for (int i = n - 2; i >= 0; i--)
        {
            if (vec[i].second < last)
            {
                last = vec[i].first;
                meetings++;
            }
        }
        
        return meetings;
    }
};



// Solved by sorting (w.r.t end time) and iterating from the front
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(end[i], start[i]);
        }
        
        sort (vec.begin(), vec.end());
        
        int meetings = 1, last = vec[0].first;
        
        for (int i = 1; i < n; i++)
        {
            if (vec[i].second > last)
            {
                last = vec[i].first;
                meetings++;
            }
        }
        
        return meetings;
    }
};