//
// Created by Carlos Gonzalez on 2024-11-04.
//

#include "LoggingObserver.h"

#include <fstream>
#include <iostream>
#include <ctime>

#define LOG_FILE "gamelog.txt"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Subject Class Implementation
///

// Default Constructor
    Subject::Subject() {
        m_observers = new std::list<Observer *>();
    }

// Attaches a new Observer to notify
    void Subject::attach(Observer* observer) {
        m_observers->push_back(observer);
}

// Detaches a new Observer to notify
    void Subject::detach(Observer* observer) {
    m_observers->remove(observer);
    delete observer;
}

// Clears all list with observers
    void Subject::clear() {
        for (int i = 0; i < m_observers->size(); i++) {
             m_observers[i].pop_back();
        }
        m_observers->clear();
        m_observers = nullptr;
    }

// Notifies all attached Observers with the loggable as parameter
    void Subject::notify(ILoggable* loggable) {
    for (auto & m_observer : *m_observers) {
        m_observer->update(loggable);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Log Observer Class Implementation

// Default Constructor (Opens _logFile)
    LogObserver::LogObserver() {
    _logFile.open(LOG_FILE, std::ios::app);
    if (_logFile.fail()) {
        std::cerr << "[!] -> Error opening log file..." << std::endl;
        exit(1);
    }
}

// Deconstructor
    LogObserver::~LogObserver() {
    _logFile.close();
    }

// Updates behaviour when notified by Subject
    void LogObserver::update(ILoggable* loggable) {
        _logFile << loggable->stringToLog() << std::endl;
        std::cout <<"\n\t[:0] -> Log observer updated!\n" << std::endl;
        _logFile.flush();
    }

// Writes Header of creation time
    void LogObserver::saveHeaders() {
        _logFile << "\n===================================================================================" << std::endl;

        // Get the current time
        std::time_t now = std::time(nullptr);
        char timeBuffer[100];
        std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        // Write the log header with timestamp
        _logFile << "\t[!] Game Log Created at: " << timeBuffer << std::endl;
        _logFile << "===================================================================================\n" << std::endl;
    }






