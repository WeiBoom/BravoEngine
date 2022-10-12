workspace "BravoEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bravo"
	location "Bravo"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Bravo/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox")
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"BRAVO_PLATFORM_WINDOWS",
			"BRAVO_BUILD_DLL",
		}

	filter "configurations:Debug"
		defines "BRAVO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BRAVO_RELEASE"
		runtime "Release"
		optimize "on"

		filter "configurations:Dist"
		defines "BRAVO_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Bravo/vendor/spdlog/include",
		"Bravo/src"
	}

	links
	{
		"Bravo"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"BRAVO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "BRAVO_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "BRAVO_RELEASE"
		optimize "on"

		filter "configurations:Dist"
		defines "BRAVO_DIST"
		optimize "on"