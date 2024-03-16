//User function Template for C++
class Solution
{
    public:
    string reverseWord(string s)
    {
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};

