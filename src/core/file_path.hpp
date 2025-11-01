#pragma once

#include <string>

#define GFX_PATH                            "/workspaces/cpp-workspace/_resources/gfx/"
#define SFX_PATH                            "/workspaces/cpp-workspace/_resources/sfx/"

namespace core
{
    std::string getFilePathGFX(const std::string&);
    std::string getFilePathSFX(const std::string&);
}