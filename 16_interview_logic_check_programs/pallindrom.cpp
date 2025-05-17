#include <iostream>
#include <vector>
#include <string>

bool isPallindromeNumber(int val)
{
    int original = val;
    int reversed = 0;

    while (val > 0)
    {
        int digit = val % 10;   // Get the last digit
        reversed = reversed * 10 + digit;   // Append it to the reversed number
        val /= 10;  // Remove the last digit from the original number
    }

    return original == reversed;
}

bool isPallindromeString(const std::string& str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main()
{
    std::vector<int> numVctr = {121, 123, 131, 145, 151, 161, 171, 181, 191, 202};
    std::vector<int> pallindromeNumbers;
    std::vector<std::string> strVctr = {"132", "racecar", "madam", "levelr", "deified", "ceramic", "radar", "referral", "noon", "rotor"};
    std::vector<std::string> pallindromeStrings;

    for(auto& val : numVctr)
    {
        if(isPallindromeNumber(val))
        {
            pallindromeNumbers.push_back(val);
        }
    }

    std::cout << "The pallindrome numbers are: " << std::endl;
    for(auto& val : pallindromeNumbers)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    for(auto& word : strVctr)
    {
        if(isPallindromeString(word))
        {
            pallindromeStrings.push_back(word);
        }
    }
   
    std::cout << "The pallindrome strings are: " << std::endl;
    for(auto& word : pallindromeStrings)
    {
        std::cout << word << " ";
    }

    return 0;
}