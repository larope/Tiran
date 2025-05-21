#ifndef TIME_H
#define TIME_H

class Time {
    static float _fps;
    static float _timeElapsed;
    static float _currentTime;

public:
    [[nodiscard]] static float deltaTime();
    [[nodiscard]] static float fps();
    [[nodiscard]] static float timeElapsed();

    [[nodiscard]] static float currentTime();
    [[nodiscard]] static float currentTimeSin();
    [[nodiscard]] static float currentTimeCos();

    [[nodiscard]] static float s2h(float seconds);
    [[nodiscard]] static float s2m(float seconds);
    [[nodiscard]] static float s2ms(float seconds);

    [[nodiscard]] static float m2h(float minutes);
    [[nodiscard]] static float m2s(float minutes);
    [[nodiscard]] static float m2ms(float minutes);

    [[nodiscard]] static float h2ms(float hours);
    [[nodiscard]] static float h2s(float hours);
    [[nodiscard]] static float h2m(float hours);

    [[nodiscard]] static float ms2s(float ms);
    [[nodiscard]] static float ms2m(float ms);
    [[nodiscard]] static float ms2h(float ms);

    friend int main();
};

#endif // TIME_H
