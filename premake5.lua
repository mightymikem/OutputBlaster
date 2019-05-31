workspace "OutputBlaster"
	configurations { "Debug", "Release" }
	platforms { "x64", "x86" }

	flags { "StaticRuntime", "No64BitChecks" }

	systemversion "10.0.17134.0"

	symbols "On"

	characterset "Unicode"

	flags { "NoIncrementalLink", "NoEditAndContinue", "NoMinimalRebuild" }

	includedirs { "Common Files/", "Game Files/", "Output Files/" }

	libdirs { "" }

	buildoptions { "/MP", "/std:c++17" }

	filter "platforms:x86"
		architecture "x32"

	filter "platforms:x64"
		architecture "x64"

project "OutputBlaster"
	targetname "OutputBlaster"
	language "c++"
	kind "SharedLib"

	files
	{
		"**.txt", "**.cpp", "**.h", "Common Files/**.cpp", "Common Files/**.h", "Game Files/**.cpp", "Game Files/**.h", "Output Files/**.cpp", "Output Files/**.h",
	}

