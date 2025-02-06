//
// Created by m41k1 on 2/6/25.
//

#include "Clock.h"

Clock::Clock(Json::Value data) {

    timestamp = data["timestamp"].asString();
    is_open = data["is_open"].asBool();
    next_open = data["next_open"].asString();
    next_close = data["next_close"].asString();

    json = data;
}
