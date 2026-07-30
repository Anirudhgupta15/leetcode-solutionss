class Solution {
private:
    string removeSpecialCharacters(string &s) {
        string updatedString = "";

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                updatedString += ch;
            } 
            else if (ch >= 'A' && ch <= 'Z') {
                updatedString += (ch + 32);
            } 
            else if (ch >= '0' && ch <= '9') {
                updatedString += ch;
            }
        }

        return updatedString;
    }

public:
    bool isPalindrome(string s) {
        string newString = removeSpecialCharacters(s);

        int low = 0;
        int high = newString.size() - 1;

        while (low < high) {
            if (newString[low] != newString[high]) {
                return false;
            }
            low++;
            high--;
        }

        return true;
    }
};