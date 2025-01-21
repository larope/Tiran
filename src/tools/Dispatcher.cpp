#include "Dispatcher.h"

namespace artt {
    template<typename... Args>
    void Dispatcher<Args...>::notifyAll(Args... args) {
        for (Observer<Args...>* observer : observers) {
            observer->onNotify(args...);
        }
    }

    template<typename... Args>
    void Dispatcher<Args...>::subscribe(Observer<Args...>* observer) {
        if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
            observers.push_back(observer);
        }
    }

    template<typename... Args>
    void Dispatcher<Args...>::unSubscribe(Observer<Args...>* observer) {
        observers.erase(
                std::remove(observers.begin(), observers.end(), observer),
                observers.end()
        );
    }

    template<typename... Args>
    void Dispatcher<Args...>::emit(Args... args) {
        notifyAll(args...);
    }

    template<typename... Args>
    Dispatcher<Args...>::~Dispatcher() = default;
}
