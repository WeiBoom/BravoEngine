#pragma once

#include "RenderContext.h"

namespace Bravo
{
	class UIContext : public RenderContext
	{
	public:
		bool Init(Bravo::IWindow* window) override;
		void PreRender() override;
		void PostRender() override;
		void End() override;

	};
}

