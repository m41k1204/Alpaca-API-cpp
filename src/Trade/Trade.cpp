//
// Created by m41k1 on 2/7/25.
//

// Trade.cpp
#include "Trade.h"
#include <iostream>
#include <cstdlib> // For std::stod
#include <utility>

Trade::Trade(std::string symbol, const Json::Value& resp) {\
    this->symbol = std::move(symbol);

    message_type = resp.get("message_type", "").asString();

    trade_id = resp.get("i", 0).asLargestUInt();



    exchange_code = resp.get("x", "").asString();

    try {
        trade_price = std::stod(resp.get("p", "0").asString());
    } catch (const std::exception& e) {
        std::cerr << "Error converting trade_price: " << e.what() << std::endl;
        trade_price = 0.0;
    }

    trade_size = resp.get("s", 0).asInt();

    trade_condition.clear();
    try {
        if (resp.isMember("c") && resp["c"].isArray()) {
            for (const auto& cond : resp["c"]) {
                trade_condition.push_back(cond.asString());
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error converting trade_condition: " << e.what() << std::endl;
    }


    timestamp = resp.get("t", "").asString();

    tape = resp.get("z", "").asString();
}
