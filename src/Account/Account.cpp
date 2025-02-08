/* Account.cpp */
#include "Account.h"

Account::Account(const Json::Value& resp) {
    account_blocked = resp.get("account_blocked", false).asBool();
    pattern_day_trader = resp.get("pattern_day_trader", false).asBool();
    trade_suspended_by_user = resp.get("trade_suspended_by_user", false).asBool();
    trading_blocked = resp.get("trading_blocked", false).asBool();
    transfers_blocked = resp.get("transfers_blocked", false).asBool();

    try {
        buying_power = std::stod(resp.get("buying_power", "0").asString());
        cash = std::stod(resp.get("cash", "0").asString());
        cash_withdrawable = std::stod(resp.get("cash_withdrawable", "0").asString());
        portfolio_value = std::stod(resp.get("portfolio_value", "0").asString());
    } catch (const std::exception& e) {
        std::cerr << "Error converting string to double: " << e.what() << std::endl;
        buying_power = 0.0;
        cash = 0.0;
        cash_withdrawable = 0.0;
        portfolio_value = 0.0;
    }

    created_at = resp.get("created_at", "").asString();
    currency = resp.get("currency", "").asString();
    id = resp.get("id", "").asString();
    status = resp.get("status", "").asString();

}