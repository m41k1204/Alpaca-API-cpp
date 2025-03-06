//
// Created by m41k1 on 2/7/25.
//

#ifndef TRADE_H
#define TRADE_H

#include <json/json.h>

class Trade {

  public:
    Trade(std::string symbol, const Json::Value&);

    std::string message_type;
    std::string symbol;
    uint trade_id;
    std::string exchange_code;
    double trade_price;
    int trade_size;
    std::vector<std::string> trade_condition;
    std::string timestamp;
    std::string tape;
};



#endif //TRADE_H
