#include "imgui.h"

#include "RenderContext.h"

namespace Bravo {

	void RenderContext::PushRenderer(Renderer* rdr) 
	{
		m_Renderers.push_back(rdr);
	}

	void RenderContext::Render() {

		//ImGui::Begin("Scene");

		//ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		//auto size = { viewportPanelSize.x, viewportPanelSize.y };

		for (int i = 0; i < m_Renderers.size(); i++) {
			if (!m_Renderers[i]) continue;
			m_Renderers[i]->Render();
		}

		//ImGui::End();
	}

}