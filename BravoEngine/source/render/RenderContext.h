#pragma once

#include "../window/IWindow.h"
#include "Renderer.h"
#include <vector>

namespace Bravo
{
    class RenderContext
    {
    public:

        RenderContext() : m_window(nullptr) {}

        virtual bool init(Bravo::IWindow* window)
        {
            m_window = window;
            return true;
        }

        virtual void pre_render() = 0;

        void Render();

        virtual void post_render() = 0;

        virtual void end() = 0;

        void PushRenderer(Renderer* rdr);

    protected:
        Bravo::IWindow* m_window;
        std::vector<Renderer*> m_Renderers;
    };
}


