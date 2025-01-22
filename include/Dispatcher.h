#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <vector>
#include "Observer.h"
#include <algorithm>

namespace artt {
    template<typename... Args>
    class Dispatcher {
    protected:
        std::vector<Observer<Args...>*> observers;

    public:
        void subscribe(Observer<Args...>* observer) {
            if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
                observers.push_back(observer);
            }
        }

        void unSubscribe(Observer<Args...>* observer) {
            observers.erase(
                std::remove(observers.begin(), observers.end(), observer),
                observers.end()
            );
        }

        void notifyAll(Args... args) {
            for (auto observer : observers) {
                observer->onNotify(args...);
            }
        }

        void emit(Args... args) {
            notifyAll(args...);
        }

        virtual ~Dispatcher() = default;
    };
}

#endif
