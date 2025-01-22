#ifndef SINGLETON_H
#define SINGLETON_H

namespace artt {
    template <typename T>
    class Singleton {
    public:
        static T& getInstance() {
            static T instance;
            return instance;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        Singleton() = default;
        ~Singleton() = default;

        static T& _instance;

    };

    template <typename T>
    T& Singleton<T>::_instance = Singleton<T>::getInstance();
}

#endif
