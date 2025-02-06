//
// Created by m41k1 on 2/6/25.
//

#ifndef CLOCK_H
#define CLOCK_H

#include <json/json.h>

class Clock {
public:
    Clock(Json::Value);
    std::string timestamp;
    bool is_open;
    std::string next_open;
    std::string next_close;

    //Keep Json
    Json::Value json;
};



#endif //CLOCK_H
