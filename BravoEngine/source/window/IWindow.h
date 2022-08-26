#pragma once
#include "../define.h"
namespace Bravo
{
    class IWindow
    {
    public:
        virtual void* GetNativeWindow() = 0;
        virtual void SetNativeWindow(void* window) = 0;
        virtual void OnScroll(double delta) = 0;
        virtual void OnKey(int key, int scancode, int action, int mods) = 0;
        virtual void OnResize(int width, int height) = 0;
        virtual void OnClose() = 0;
    public:
        int Width;
        int Height;
        std::string Title;
    };
}