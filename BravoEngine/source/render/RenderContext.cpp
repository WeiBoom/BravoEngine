#include "RenderContext.h"

namespace Bravo {

	void RenderContext::PushRenderer(Renderer* rdr) 
	{
		m_Renderers.push_back(rdr);
	}

	void RenderContext::Render() {
		for (int i = 0; i < m_Renderers.size(); i++) {
			if (!m_Renderers[i]) continue;
			m_Renderers[i]->Render();
		}
	}

}