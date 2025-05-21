#ifndef TIME_H
#define TIME_H

class Time {
    static float _fps;
    static float _timeElapsed;
    static float _currentTime;

public:
    static float deltaTime();
    static float fps();
    static float timeElapsed();

    static float currentTime();
    static float currentTimeSin();
    static float currentTimeCos();

    static float s2h(float seconds);
    static float s2m(float seconds);
    static float s2ms(float seconds);

    static float m2h(float minutes);
    static float m2s(float minutes);
    static float m2ms(float minutes);

    static float h2ms(float hours);
    static float h2s(float hours);
    static float h2m(float hours);

    static float ms2s(float ms);
    static float ms2m(float ms);
    static float ms2h(float ms);

    friend int main();
};

#endif // TIME_H
