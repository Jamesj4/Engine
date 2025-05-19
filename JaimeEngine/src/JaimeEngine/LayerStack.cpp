#include "jepch.h"
#include "LayerStack.h"


namespace JaimeEngine
{
    void LayerStack::PushLayer(std::unique_ptr<Layer> layer)
    {
        auto it = m_Layers.begin() + m_LayerInsertIndex;
        m_Layers.emplace(it, std::move(layer));
    }

    void LayerStack::PushOverlay(std::unique_ptr<Layer> overlay)
    {
        m_Layers.emplace_back(std::move(overlay));
    }

    std::unique_ptr<Layer> LayerStack::PopLayer(Layer* layer)
    {
        for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it)
        {
            if (it->get() == layer)
            {
                size_t index = std::distance(m_Layers.begin(), it);
                if (index < m_LayerInsertIndex)
                    --m_LayerInsertIndex;

                std::unique_ptr<Layer> removed = std::move(*it);
                m_Layers.erase(it);
                return removed;
            }
        }
        return nullptr;
    }

    std::unique_ptr<Layer> LayerStack::PopOverlay(Layer* overlay)
    {
        for (auto it = m_Layers.begin() + m_LayerInsertIndex; it != m_Layers.end(); ++it)
        {
            if (it->get() == overlay)
            {
                std::unique_ptr<Layer> removed = std::move(*it);
                m_Layers.erase(it);
                return removed;
            }
        }
        return nullptr;
    }
}