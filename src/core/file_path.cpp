
#include "file_path.hpp"

namespace core
{
    std::string getFilePathGFX(const std::string& file)
    {
        return GFX_PATH + file;
    }

    std::string getFilePathSFX(const std::string& file)
    {
        return SFX_PATH + file;
    }
}