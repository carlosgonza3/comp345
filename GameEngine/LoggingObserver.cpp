//
// Created by Carlos Gonzalez on 2024-11-04.
//

#include "LoggingObserver.h"

#include <fstream>
#include <iostream>

#define LOG_FILE "gamelog.txt"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Subject Class Implementation

void Subject::attach(Observer* observer) {
    m_observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    for (int i = 0; i < m_observers.size(); i++) {
        if (m_observers[i] == observer) {
            m_observers.erase(m_observers.begin() + i);
        }
    }
}

void Subject::notify(ILoggable* loggable) {
    for (auto & m_observer : m_observers) {
        m_observer->update(loggable);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Log Observer Class Implementation

LogObserver::LogObserver() {
    _logFile.open(LOG_FILE, std::ios::app);
    if (_logFile.fail()) {
        std::cerr << "[!] -> Error opening log file..." << std::endl;
        exit(1);
    }
}

LogObserver::~LogObserver() {
    _logFile.close();
}

void LogObserver::update(ILoggable* loggable) {
    std::cout <<"Logging observer updated" << std::endl;
    _logFile << loggable->stringToLog() << std::endl;
}




