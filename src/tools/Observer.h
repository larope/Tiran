#ifndef OBSERVER_H
#define OBSERVER_H

namespace artt {
    template<typename... Args>
    class Observer {
    public:
        virtual void onNotify(Args... args, glm::uint type) = 0;
        virtual ~Observer() = default;
    };
}

#endif
