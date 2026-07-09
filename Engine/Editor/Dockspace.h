#pragma once

namespace Arc
{
    class Dockspace
    {
    public:
        void Begin();
        void End();

    private:
        bool m_FirstFrame = true;
    };
}