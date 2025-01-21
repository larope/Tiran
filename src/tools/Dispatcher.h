#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <vector>
#include <algorithm>
#include "Observer.h"

namespace artt {
    template<typename... Args>
    class Dispatcher {
    protected:
        std::vector<Observer<Args...>*> observers;

        virtual void notifyAll(Args... args);

    public:
        virtual void subscribe(Observer<Args...>* observer);
        virtual void unSubscribe(Observer<Args...>* observer);

        virtual void emit(Args... args);

        virtual ~Dispatcher();
    };
}

#endif
