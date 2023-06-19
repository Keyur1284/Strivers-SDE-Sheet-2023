// Problem Link :- https://leetcode.com/problems/integer-to-roman/

// Solved by Basic Implementation
// Time Complexity :- O(1) 
// Space Complexity :- O(1)

class Solution {
public:
    string intToRoman(int num) {
        
        string roman = "";
        
        while (num)
        {
            if (num >= 1000)
            {
                num -= 1000;
                roman += "M";
            }

            else if (num >= 900)
            {
                num -= 900;
                roman += "CM";
            }

            else if (num >= 500)
            {
                num -= 500;
                roman += "D";
            }

            else if (num >= 400)
            {
                num -= 400;
                roman += "CD";
            }

            else if (num >= 100)
            {
                num -= 100;
                roman += "C";
            }

            else if (num >= 90)
            {
                num -= 90;
                roman += "XC";
            }

            else if (num >= 50)
            {
                num -= 50;
                roman += "L";
            }

            else if (num >= 40)
            {
                num -= 40;
                roman += "XL";
            }

            else if (num >= 10)
            {
                num -= 10;
                roman += "X";
            }

            else if (num >= 9)
            {
                num -= 9;
                roman += "IX";
            }

            else if (num >= 5)
            {
                num -= 5;
                roman += "V";
            }

            else if (num >= 4)
            {
                num -= 4;
                roman += "IV";
            }

            else
            {
                num -= 1;
                roman += "I";
            }
        }

        return roman;
    }
};



// Easier Implementation

class Solution {
public:
    string intToRoman(int num) {
        
        map<int, string> mp = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        
        string roman = "";

        while (num)
        {
            auto it = mp.lower_bound(num);

            if (it->first == num)
            {
                roman += it->second;
                num -= it->first;
                break;
            }            

            it--;
            roman += it->second;
            num -= it->first;
        }

        return roman;
    }
};