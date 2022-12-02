workspace "AdventOfCode"
    configurations {"Release"}
    location "../"
    platforms { "Win64" }

    filter { "platforms:Win64" }
        system "windows"
        architecture "x86_64"
        cppdialect "C++20"
        defines {
            "WINDOWS"
        }

    includedirs { 
        "../../AdventTools/src/" 
    }

local names = { "1-1", "1-2" }

for _, name in ipairs(names) do
    project (name) 
    location ("../" .. name)
    targetdir ("../" .. name .. "/bin")
    debugdir ("../" .. name .. "/bin")
    kind "ConsoleApp"
    language "C++"
    files { 
        ("../" .. name .. "/src/**.h")
        , ("../" .. name .. "/src/**.cpp")
        , ("../" .. name .. "/src/**.c")
        , ("../../AdventTools/src/**.h")
        , ("../../AdventTools/src/**.cpp")
        , ("../../AdventTools/src/**.c")
    }
end