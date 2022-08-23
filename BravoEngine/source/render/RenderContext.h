#pragma once

#include "../window/IWindow.h"

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

        virtual void post_render() = 0;

        virtual void end() = 0;

    protected:
        Bravo::IWindow* m_window;
    };
}


