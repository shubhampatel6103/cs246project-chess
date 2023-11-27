#ifndef __OBSERVER_H__
#define __OBSERVER_H__
class Cell;

class Observer {
    public:
        virtual void notify(Cell &c) = 0; // Cell c calls the notify function
        virtual ~Observer() = default;
};

#endif
