#include <iostream>
#include <string>
#include <windows.h>

typedef bool (*CheckCharacters)(const std::string&, const std::string&);

int main() {
    std::string inputString, inputChars;
    std::cout << "String: ";
    std::getline(std::cin, inputString);
    std::cout << "Chars for search: ";
    std::getline(std::cin, inputChars);

    HMODULE dllHandle = LoadLibrary("my_dll.dll");
    if (dllHandle == nullptr) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    CheckCharacters checkChars = reinterpret_cast<CheckCharacters>(GetProcAddress(dllHandle, "check_characters"));
    if (checkChars == nullptr) {
        std::cerr << "Failed to find function in DLL" << std::endl;
        FreeLibrary(dllHandle);
        return 1;
    }

    bool result = checkChars(inputString, inputChars);
    std::cout << (result ? "All chars r present in the string" : "Not all chars r present in the string") << std::endl;

    FreeLibrary(dllHandle);
    return 0;
}
