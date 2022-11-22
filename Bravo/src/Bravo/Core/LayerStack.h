#pragma once
#include "Bravo/Core/Base.h"
#include "Bravo/Core/Layer.h"

namespace Bravo
{
	class BRAVO_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverLay(Layer* overlay);
		void PopOverLay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}


