#pragma once
#include "Layer.h"

namespace JaimeEngine
{
	class JE_API LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack() = default;

		void PushLayer(std::unique_ptr<Layer> layer);
		void PushOverlay(std::unique_ptr<Layer> overlay);

		std::unique_ptr<Layer> PopLayer(Layer* layer);
		std::unique_ptr<Layer> PopOverlay(Layer* overlay);

		std::vector<std::unique_ptr<Layer>>::iterator begin() { return m_Layers.begin(); }
		std::vector<std::unique_ptr<Layer>>::iterator end() { return m_Layers.end(); }


		LayerStack(const LayerStack&) = delete;
		LayerStack& operator=(const LayerStack&) = delete;


	private:

		std::vector<std::unique_ptr<Layer>> m_Layers;
		size_t m_LayerInsertIndex = 0;
	};
}


