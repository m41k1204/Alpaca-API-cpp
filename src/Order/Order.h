#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <json/json.h>
#include "iostream"

class Order {
public:
    Order() = default;
    Order(const Json::Value& data);

    std::string id;
    std::string client_order_id;
    std::string created_at;
    std::string updated_at;
    std::string submitted_at;
    std::string filled_at;
    std::string expired_at;
    std::string canceled_at;
    std::string asset_id;
    std::string symbol;
    std::string exchange;
    std::string asset_class;
    double qty = 0.0;
    double filled_qty = 0.0;
    std::string type;
    std::string side;
    std::string time_in_force;
    double limit_price = 0.0;
    double stop_price = 0.0;
    std::string status;

    // Store the original JSON object for debugging or future reference.
    Json::Value json;
};

#endif // ORDER_H
