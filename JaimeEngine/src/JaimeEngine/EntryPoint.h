#pragma once

#include "Application.h"


#ifdef JE_PLATFORM_WINDOWS

extern JaimeEngine::Application* JaimeEngine::CreateApplication();

int main(int argc, char** argv)
{
	JaimeEngine::Log::Init();

	JE_CORE_WARN("Initialized Log!");
	auto app = JaimeEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif