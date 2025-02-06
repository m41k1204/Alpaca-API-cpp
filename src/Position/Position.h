//
// Created by m41k1 on 2/6/25.
//

#ifndef POSITION_H
#define POSITION_H

#include <json/json.h>

class Position {
public:
    Position(std::string symbol);
    Position(Json::Value);

    std::string asset_id;
    std::string symbol;
    std::string exchange;
    std::string asset_class;
    double avg_entry_price;
    int qty;
    std::string side;
    double market_value;
    double cost_basis;
    std::string unrealized_pl;
    double unrealized_plpc;
    double unrealized_intraday_pl;
    double unrealized_intraday_plpc;

    double current_price;
    double lastday_price;
    double change_today;


    //Keep Json
    Json::Value json;

};


#endif //POSITION_H
