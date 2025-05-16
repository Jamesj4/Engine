#include <JaimeEngine.h>

class Sandbox : public JaimeEngine::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

JaimeEngine::Application* JaimeEngine::CreateApplication()
{
	return new Sandbox();
}