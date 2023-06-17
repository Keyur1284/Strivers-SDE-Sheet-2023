// Problem Link :- https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Solved by Recursion
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)



/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   
    if (s.size() == 1)
        return;
        
    int num = s.top();
    s.pop();
    sort();
    
    if (s.top() <= num)
        s.push(num);
        
    else
    {
        int topEle = s.top();
        s.pop();
        s.push(num);
        s.push(topEle);
        sort();
    }
}