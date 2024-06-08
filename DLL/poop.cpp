#include <algorithm>
#include <string>

extern "C" __declspec(dllexport) bool IsAnagram(const std::string& word1, const std::string& word2)
{
    std::string temp_word1 = word1;
    std::string temp_word2 = word2;
    std::transform(temp_word1.begin(), temp_word1.end(), temp_word1.begin(), ::tolower);
    std::transform(temp_word2.begin(), temp_word2.end(), temp_word2.begin(), ::tolower);
    std::sort(temp_word1.begin(), temp_word1.end());
    std::sort(temp_word2.begin(), temp_word2.end());

    return temp_word1 == temp_word2;
}
