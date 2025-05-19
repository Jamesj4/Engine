#include <JaimeEngine.h>


class ExampleLayer : public JaimeEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override 
	{
		JE_INFO("Example layer -> Layer update");
	}

	void OnEventCall(JaimeEngine::Event& event) override
	{
		JE_TRACE("{0}", event.ToString());
	}

};
class Sandbox : public JaimeEngine::Application
{
public:
	Sandbox() 
	{
		PushLayer(std::make_unique<ExampleLayer>());
	}
	~Sandbox() {}
};

JaimeEngine::Application* JaimeEngine::CreateApplication()
{
	{
		return new Sandbox{};
	}
}