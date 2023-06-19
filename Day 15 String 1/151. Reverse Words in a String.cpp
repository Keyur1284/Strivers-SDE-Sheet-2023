// Problem Link :- https://leetcode.com/problems/reverse-words-in-a-string/

// Solved using vector<string>
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string reverseWords(string s) {

        int len = s.length();    
        vector<string> words;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
                continue;

            string word = "";

            while (i < len && s[i] != ' ')
                word += s[i++];

            words.emplace_back(word);
        }   

        string reverse = "";

        int n = words.size();

        for (int i = n - 1; i >= 0; i--)
            reverse += words[i] + " ";
        
        reverse.pop_back();
        
        return reverse;
    }
};



// Solved without using extra space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string reverseWords(string s) {

        int len = s.length();    
        string reverse = "";

        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
                continue;

            string word = "";

            while (i < len && s[i] != ' ')
                word += s[i++];

            reverse = word + " " + reverse;
        }   
        
        reverse.pop_back();
        
        return reverse;
    }
};