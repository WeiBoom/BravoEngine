#pragma once

#include "RenderContext.h"

namespace Bravo
{
	class UIContext : public RenderContext
	{
	public:
		bool init(Bravo::IWindow* window) override;
		void pre_render() override;
		void post_render() override;
		void end() override;

	};
}

