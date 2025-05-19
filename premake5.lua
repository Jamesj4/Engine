workspace "JaimeEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	--Include directories relative to root folder 
	IncludeDir ={}
	IncludeDir["GLFW"] = "JaimeEngine/vendor/GLFW/include"

	include "JaimeEngine/vendor/GLFW"

	project "JaimeEngine"
		location "JaimeEngine"
		kind "SharedLib"
		language "C++"
		staticruntime "off"

		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

		pchheader "jepch.h"
		pchsource "JaimeEngine/src/jepch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs 
		{
			"%{prj.name}/vendor/spdlog/include",
			"$(SolutionDir)JaimeEngine/src",
			"%{IncludeDir.GLFW}"
		}

		links
		{
			 "GLFW",
			 "opengl32.lib"
		}

		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"
			toolset "v143"
			buildoptions { "/utf-8" }

			defines
			{
				"JE_PLATFORM_WINDOWS",
				"JE_BUILD_DLL",
				"JE_CORE_ASSERT",
				"JE_ASSERT"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
			}

		filter "configurations:Debug"
		defines "JE_DEBUG"
		runtime "Debug"
		symbols "On"

		filter "configurations:Release"
		defines "JE_Release"
		runtime "Release"
		optimize "On"


		filter "configurations:Dist"
		defines "JE_DIST"
		runtime "Release"
		optimize "On"

		
	project "Sandbox"

		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		toolset "v143"
		
		buildoptions { "/utf-8" }

		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs 
		{
			"JaimeEngine/vendor/spdlog/include",
			"JaimeEngine/src"
		}

		filter "system:windows"
			cppdialect "C++17"
			
			systemversion "latest"

			defines
			{
				"JE_PLATFORM_WINDOWS",
			}

			links
			{
				"JaimeEngine"
			}

		filter "configurations:Debug"
		defines "JE_DEBUG"
		runtime "Debug"
		symbols "On"

		filter "configurations:Release"
		defines "JE_Release"
		runtime "Release"
		optimize "On"


		filter "configurations:Dist"
		defines "JE_DIST"
		runtime "Release"
		optimize "On"