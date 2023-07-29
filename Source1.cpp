#include "watch.hpp"
#include "unistd.h"
#include <iostream>
#include <string>
#include <stdio.h>

watch::watch() { // Constructor
    this->_time = { seconds: 0, mins : 0, hours : 0, days : 0, months : 0 };
}

std::string
watch::get_time() { // Ðåàëèçàöèÿ ÌÅÒÎÄÀ std::string get_time() êëàññà watch
    char result[10];
    sprintf(result, "%d:%d:%d:%d:%d", this->_time.months, this->_time.days,
        this->_time.hours, this->_time.mins, this->_time.seconds);
    std::string _result = result;
    return _result;
}

int watch::get_time(std::string key) {
    if (key.compare("hours") == 0) {
        return _time.hours;
    }

    if (key.compare("mins") == 0)
        return _time.mins;

    if (key.compare("seconds") == 0)
        return _time.seconds;

    if (key.compare("days") == 0)
        return _time.days;

    if (key.compare("months") == 0)
        return _time.months;
}

int watch::run_time() {
    while (true) {
        // std::cout << "start" << std::endl;
        _time.seconds++;
        if (_time.seconds == 60) {
            _time.seconds = 0;
            _time.mins++;

            if (_time.mins == 60) {
                _time.mins = 0;
                _time.hours++;

                if (_time.hours == 24) {
                    _time.hours = 0;
                    _time.days++;

                    if (_time.days == 30) {
                        _time.days = 0;
                        _time.months++;
                    }
                }
            }
        }
        this->print_time();
        sleep(1);
    };
    return 0;
}

void watch::print_time() {
    printf("%s   \r", this->get_time().c_str());
    std::cout.flush();
}