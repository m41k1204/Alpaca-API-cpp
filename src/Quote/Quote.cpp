// Quote.cpp
#include "Quote.h"
#include <iostream>
#include <cstdlib> // For std::stod if needed
#include <utility>

Quote::Quote(std::string symbol, const Json::Value& resp) {
    this->symbol = std::move(symbol);

    // Retrieve string fields
    message_type = resp.get("message_type", "").asString();

    // Get ask fields
    ask_exchange_code = resp.get("ax", "").asString();
    try {
        ask_price = std::stod(resp.get("ap", "0").asString());
    } catch (const std::exception& e) {
        std::cerr << "Error converting ask_prize: " << e.what() << std::endl;
        ask_price = 0.0;
    }
    ask_size = resp.get("as", 0).asInt();

    // Get bid fields
    bid_exchange_code = resp.get("bx", "").asString();
    try {
        bid_price = std::stod(resp.get("bp", "0").asString());
    } catch (const std::exception& e) {
        std::cerr << "Error converting bid_prize: " << e.what() << std::endl;
        bid_price = 0.0;
    }
    bid_size = resp.get("bs", 0).asInt();

    // Process quote conditions, which is expected to be an array of strings.
    quote_condition.clear();
    if (resp.isMember("c") && resp["c"].isArray()) {
        for (const auto& cond : resp["c"]) {
            quote_condition.push_back(cond.asString());
        }
    }

    // Get the remaining fields.
    timestamp = resp.get("t", "").asString();
    tape = resp.get("z", "").asString();

}
