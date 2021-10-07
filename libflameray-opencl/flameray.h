#pragma once
#include "api.h"
#include <vector>

class EXPORTED FlameRay
{
public:
    FlameRay(std::vector<int> activeDevices);
    ~FlameRay();

private:
    std::vector<int> m_activeDevices;
    std::vector<int> m_noDevice;
};