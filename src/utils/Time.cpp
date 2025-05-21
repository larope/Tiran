#include "../../include/Time.h"

#include <cmath>

float Time::_fps = 0.0f;
float Time::_timeElapsed = 0.0f;
float Time::_currentTime = 0.0f;

float Time::deltaTime() {
    return _fps > 0 ? 1.0f / _fps : 0.0f;
}

float Time::fps() {
    return _fps;
}

float Time::timeElapsed() {
    return _timeElapsed;
}

float Time::currentTime() {
    return _currentTime;
}
float Time::currentTimeSin() {
    return sinf(_currentTime);
}
float Time::currentTimeCos() {
    return cosf(_currentTime);
}


float Time::s2m(const float seconds) { return seconds / 60; }
float Time::s2h(const float seconds) { return seconds / 3600; }
float Time::s2ms(const float seconds) { return seconds * 1000; }

float Time::m2h(const float minutes) { return minutes / 60; }
float Time::m2s(const float minutes) { return minutes * 60; }
float Time::m2ms(const float minutes) { return minutes * 60000; }

float Time::h2m(const float hours) { return hours * 60; }
float Time::h2s(const float hours) { return hours * 3600; }
float Time::h2ms(const float hours) { return hours * 3600000; }

float Time::ms2s(const float milliseconds) { return milliseconds / 1000.0f; }
float Time::ms2m(const float milliseconds) { return milliseconds / 60000.0f; }
float Time::ms2h(const float milliseconds) { return milliseconds / 3600000.0f; }