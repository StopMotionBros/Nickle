workspace "NickleEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nickle"
	location "Nickle"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nkpch.h"
	pchsource "Nickle/src/nkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NK_PLATFORM_WINDOWS",
			"NK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Nickle/vendor/spdlog/include",
		"Nickle/src"
	}

	links
	{
		"Nickle"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NK_DIST"
		optimize "On"