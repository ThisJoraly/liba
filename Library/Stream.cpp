#include "Stream.h"
#include <windows.h>
#include <locale>
#include <codecvt>

namespace Streaming
{
    int FileStream::countLines(std::ifstream file)
    {
        int count = 0;
        std::string temp;
        while (file.is_open())
        {
            if (std::getline(file, temp))
            {
                count++;
            }
            else file.close();
        }
        return count;
    }
}
