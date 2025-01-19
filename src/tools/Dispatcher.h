#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H
#include <unordered_map>
#include <vector>
#include <glm/detail/setup.hpp>

#include "Observer.h"

namespace artt {
    template<typename... Args>
    class Dispatcher {
    protected:
        std::vector<std::vector<Observer<Args...>>> observers;
        virtual void notifyAll(Args... args, glm::uint type) {
            for (Observer observer : observers[type]) observer.onNotify(args..., type);
        }

    public:
        virtual void subscribe(Observer<Args...> observer, glm::uint type) = 0;
        virtual void unSubscribe(Observer<Args...> observer, glm::uint type) = 0;
        virtual void emit(Args... args, glm::uint type) = 0;

        virtual ~Dispatcher() = default;
    };
}

#endif
