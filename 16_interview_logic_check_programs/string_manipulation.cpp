#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <unordered_map>
#include <vector>

bool isPallindrome(std::string& str)
{
    int length = str.length()/2;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == str[length-1-i]) return true;
    }
    return false;
}
std::string removeACharacter(std::string& orgString, char& chrToRemove)
{
    std::string resultString;
    for(char c : orgString)
    {
        if(c != chrToRemove)
        {
            resultString += c;
        }
    }

    return resultString;
}

void replaceACharacter(std::string& orgStr, char letterToReplace, char letterToReplaceWith)
{
    for(char& c : orgStr)
    {
        if (c == letterToReplace)
        {
            c = letterToReplaceWith;
        }
    }
}

std::string removestartingtralingspaces(std::string orgString)
{
    std::string resultString;
    int start = 0;
    int end = orgString.size() - 1;

    while (start <= end && orgString[start] == ' ') {
        start++;
    }
    while (end >= start && orgString[end] == ' ') {
        end--;
    }

    for(int i = start; i <= end; i++)
    {
        resultString += orgString[i];
    }
    
    return resultString;
}

std::string reverseString(std::string s)
{
    int length = s.length();
    for(int i = 0; i < (length/2); i++)
    {
        std::swap(s[i], s[length-1-i]);
    }

    return s;
}

int reverseNumber(int num)
{
    int remainder, reversed = 0;
    while(num != 0)
    {
        remainder = num % 10;
        reversed = (reversed * 10) + remainder;
        num = num / 10;
    }
    return reversed;
}

void printDuplicateCharWithFrequency(std::string& str)
{
    std::unordered_map<char, int> counter;
    for(int i = 0; i < str.length(); i++)
    {
        counter[str[i]]++;
    }

    for(auto& [key, value] : counter)
    {
        if (value > 1) {
            std::cout << key << " appears " << value << " times\n";
        }
    }
}

void duplicateWordsInSentense(std::string& sentence)
{
    std::unordered_map<std::string, int> wordCount;
    std::stringstream ss(sentence);
    std::string word;

    // Count frequency of each word
    while(ss >> word)
    {
        wordCount[word]++;
    }
    // Print repeated words
    std::cout << "Repeated words:\n";
    for (const auto& [w, count] : wordCount) {
        if (count > 1)
            std::cout << w << " appears " << count << " times\n";
    }

}

void reverseCharsInWordsOfSentence(std::string& sentese)
{
    std::stringstream ss(sentese);
    std::string word;
    std::string resultString;

    while(ss >> word)
    {
        int length = word.length();
        for(int i = 0; i < (length/2); i++)
        {
            std::swap(word[i], word[length-1-i]);
        }
        resultString+= word;
        resultString+= " ";
    }
    std::cout << "reversing chars in words of a sentece : "<< resultString <<std::endl;
}

bool checkRotation(std::string mainStr, std::string rotatedStr)
{
    if(mainStr.length() != rotatedStr.length()) return false;

    std::string concatedStr = mainStr + mainStr;

    if(concatedStr.find(rotatedStr) == std::string::npos)
        return false;

    return true;
}

bool isAnagram(std::string s1, std::string s2)
{
    if(s1.length() != s2.length()) return false;

    std::unordered_map <char, int> Map;

    for(int i = 0; i < s1.length(); i++)
    {
        Map[s1[i]] += 1;
    }
    for(int i = 0; i < s2.length(); i++)
    {
        if(Map.find(s2[i]) != Map.end())
        {
            Map[s2[i]] -= 1;
        }
        else{
            return false;
        }
    }
    for(auto items : Map)
    {
        if(items.second != 0)
            return false;
    }
    return true;
}


int main()
{
    std::string str = "  I am Milind Bodhare   ";
    std::string checkPallindrome = "racecar";
    char letter = ' ';
    char letterToReplace = ' ';
    char letterToReplaceWith = '#';
    int number = 145672;
    std::string sentence = "Hello world world Hello";
    std::string sentense1 = "My name is MB";
    std::cout << "string without mentioned character : " << removeACharacter(str, letter) <<std::endl;
    //replaceACharacter(str, letterToReplace, letterToReplaceWith);
    //std::cout << "string with replaced charcter is : "<< str << std::endl;
    std::cout << "string with no staring & trailing spaces : " <<removestartingtralingspaces(str) <<std::endl;
    std::cout << "reversed string : " <<reverseString(str) <<std::endl;

    if(isPallindrome(checkPallindrome)) 
        std::cout << "string is pallindrom" <<std::endl;
    else
        std::cout << "string is not pallindrom" <<std::endl;
    
    std::cout << "reversed number is : " <<reverseNumber(number) <<std::endl;
    std::cout << "counting charcters with frequency :" <<std::endl;
    printDuplicateCharWithFrequency(checkPallindrome);
    std::cout << "counting words with frequency in sentense :" <<std::endl;
    duplicateWordsInSentense(sentence);

    std::cout << "reversing chars in words of sentece :" <<std::endl;
    reverseCharsInWordsOfSentence(sentense1);

    std::cout << "checking if it is rotated string : " << checkRotation("ABCD","CDAB") <<std::endl;

    std::cout << "checking if it is anamgram string : " << isAnagram("racecar","carrace") <<std::endl;
    
}



