#ifndef TRADEAPI_H
#define TRADEAPI_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <optional>
#include <curl/curl.h>
#include <json/json.h>

#include "Account/Account.h"
#include "Order/Order.h"
#include "Position/Position.h"
#include "Asset/Asset.h"
#include "Clock/Clock.h"
#include "Quote/Quote.h"

class Tradeapi {
public:
    void init(const std::string&, const std::string&);
    ~Tradeapi() = default;

    /* Account */
    Account get_account();

    /* Orders */
    Order submit_order(const bool stock, const std::string&, int, const std::string&, const std::string&,
                       const std::string&, double limit_price = 0, double stop_price = 0,
                       const std::string& client_order_id = "") const;
    std::vector<Order> list_orders(const std::string& status = "open",
                                    int limit = 50,
                                    const std::string& after = "",
                                    const std::string& until = "",
                                    const std::string& direction = "",
                                    const std::string& symbols = "",
                                    const std::string& side = "") const;
    Order get_order(const std::string& order_id);
    Order get_order_by_client_order_id(const std::string& client_order_id);
    void cancel_order(const std::string& order_id);
    Order change_order_by_client_order_id(
            const std::string& client_order_id,
            std::optional<int> qty = std::nullopt,
            std::optional<std::string> time_in_force = std::nullopt,
            std::optional<double> limit_price = std::nullopt,
            std::optional<double> stop_price = std::nullopt);
    /* Positions */
    std::vector<Position> list_positions();
    Position get_position(const std::string&);

    /* Asset */
    std::vector<Asset> list_assets(const std::string& status = "active", const std::string& asset_class = "us_equity");
    Asset get_asset(const std::string&);

    /* Market Data */
    Json::Value get_barset(const std::vector<std::string>& symbols, const std::string& timeframe = "1D", int limit = 100);

    /* Clock */
    Clock get_clock();

    /* Calendar */
    Json::Value get_calendar(const std::string& start = "", const std::string& end = "");

    /* Quotes */
    std::vector<Quote> get_latest_quotes(const std::string& symbols, const bool stock, const std::string& currency = "USD"/*, const std::string& feed = "opra"*/);

    /* Trades */


private:
    std::string KeyID, SecretKey;

    Json::Value send_request(const bool, const bool stock, const std::string& method, const std::string& endpoint, const std::string& params = "") const;
    static size_t callback(const char* in, size_t size, size_t num, std::string* out);
};




#endif //TRADEAPI_H
