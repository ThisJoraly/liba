#include <windows.h>
#include "../Library/Stream.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int action;
    std::cin >> action;
    switch (action)
    {
        case 1:
        {
            std::vector<std::string> mem = { "lol", "kke", "meme" };
            Streaming::FileStream::writeFile("test.txt", mem);
            std::vector<std::string> lines = Streaming::FileStream::readFile(std::ifstream("test.txt"));
            for (int i = 0; i < lines.size(); i++)
            {
                std::cout << lines.at(i) << std::endl;
            }
            break;
        }
        case 2:
        {
            HINSTANCE load;
            load = LoadLibraryW(L"LmaoDll.dll");
            typedef bool (*search) (std::string, char);
            search Search;
            Search = (search)GetProcAddress(load, "SearchSymbol");
            std::string word;
            char symbol;
            std::cin >> word >> symbol;
            if (Search(word, symbol))
                std::cout << "слово " << word << " содержит " << symbol << std::endl;
            else
                std::cout << "слово " << word << " не содержит " << symbol << std::endl;
            FreeLibrary(load);
            break;
        }
        case 3:
        {
            HINSTANCE load;
            load = LoadLibraryW(L"LmaoDll.dll");
            typedef bool (*palindrome) (std::string);
            palindrome IsPalindrome;
            IsPalindrome = (palindrome)GetProcAddress(load, "IsPalindrome");
            std::string word;
            std::cin >> word;
            if (IsPalindrome(word))
                std::cout << "слово " << word << " €вл€етс€ палиндромом" << std::endl;
            else
                std::cout << "слово " << word << " не €вл€етс€ палиндромом" << std::endl;
            FreeLibrary(load);
            break;
        }
        case 4:
        {
            HINSTANCE load;
            load = LoadLibraryW(L"LmaoDll.dll");
            typedef bool (*anagram) (std::string, std::string);
            anagram IsAnagram;
            IsAnagram = (anagram)GetProcAddress(load, "IsAnagram");
            std::string word1, word2;
            std::cin >> word1 >> word2;
            if (IsAnagram(word1, word2))
                std::cout << "слово " << word1 << " €вл€етс€ анграммой слова " << word2 << std::endl;
            else
                std::cout << "слово " << word1 << " не €вл€етс€ анграммой слова " << word2 << std::endl;
            FreeLibrary(load);
            break;
        }
        case 5:
        {
            std::vector<std::string> mem = { "lol", "kke", "meme" };
            Streaming::FileStream::writeFile("test.txt", mem);
            int count = Streaming::FileStream().countLines(std::ifstream("test.txt"));
            std::cout << " оличество строк в файле: " << count << std::endl;
            break;
        }
        default:
            std::cout << "Ќеверное действие" << std::endl;
    }
}
