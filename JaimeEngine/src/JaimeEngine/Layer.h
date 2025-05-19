#pragma once
#include "Events/Event.h"
#include <string>

namespace JaimeEngine
{
	class JE_API Layer
	{
	public:
		
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEventCall(Event& event) {}


		inline const std::string GetDebugName() { return m_DebugName; }


	private:

		const std::string m_DebugName;
	};
}


