
//
// Created by Carlos Gonzalez on 2024-11-04.
//

#ifndef LOGGINGOBSERVER_H
#define LOGGINGOBSERVER_H

#include <fstream>
#include <list>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ILoggable Interface
class ILoggable {
    public:
        virtual ~ILoggable() = default;
        virtual std::string stringToLog() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Observer Interface
class Observer {
    public:
        virtual ~Observer() = default;
        virtual void update(ILoggable* loggable) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Subject Class
class Subject {
    public:
        Subject();
        virtual ~Subject() = default;
        void attach(Observer* observer);
        void detach(Observer* observer);
        void clear();
        void notify(ILoggable* loggable);
    private:
        std::list<Observer*> *m_observers;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Log Observer Class
class LogObserver : public Observer {
    public:
        LogObserver();
        ~LogObserver() override;
        void update(ILoggable* loggable) override;
        void saveHeaders();

        std::ofstream _logFile;

};

#endif //LOGGINGOBSERVER_H

