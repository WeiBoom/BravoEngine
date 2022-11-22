#include "pch.h"
#include "LayerStack.h"
namespace Bravo {


	Bravo::LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	Bravo::LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void Bravo::LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void Bravo::LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void Bravo::LayerStack::PushOverLay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void Bravo::LayerStack::PopOverLay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}
