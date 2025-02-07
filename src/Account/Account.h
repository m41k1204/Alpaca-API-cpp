/* Account.h */
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <json/json.h>
#include <string>
#include <iostream>

class Account {
public:
    Account(const Json::Value&);

    bool account_blocked;
    bool pattern_day_trader;
    bool trade_suspended_by_user;
    bool trading_blocked;
    bool transfers_blocked;

    double buying_power;
    double cash;
    double cash_withdrawable;
    double portfolio_value;

    std::string status;
    std::string created_at;
    std::string currency;
    std::string id;

    Json::Value json;
};

#endif // ACCOUNT_H

