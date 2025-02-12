//
// Created by m41k1 on 2/7/25.
//

#ifndef QUOTE_H
#define QUOTE_H

#include <variant>
#include <json/json.h>
#include "string"



class Quote {
public:
    Quote(std::string symbol, const Json::Value&);

    std::string message_type;
    std::string symbol;
    std::string ask_exchange_code;
    double ask_prize;
    int ask_size;
    std::string bid_exchange_code;
    double bid_prize;
    int bid_size;
    std::vector<std::string> quote_condition;
    std::string timestamp;
    std::string tape;

};





#endif //QUOTE_H
