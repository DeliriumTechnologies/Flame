#include "flameray.h"

FlameRay::FlameRay(std::vector<int> activeDevices)
{
    this->m_activeDevices = activeDevices;
    this->m_noDevice.push_back(-1);
}

FlameRay::~FlameRay()
{
    this->m_activeDevices = this->m_noDevice;
}