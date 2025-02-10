#include <iostream>
#include "src/TradeApi/Tradeapi.h"
#include <cstdlib>

    int main() {

        std::cout << "Hello World!\n";

        std::string PaperEndPoint = "paper-api.alpaca.markets";
        std::string RealEndPoint = "api.alpaca.markets";
        std::string KeyID = "PKFLBRNDM7BIV5MLF36G";
        std::string SecretKey = "ftKAoYm4BaDIxbytzVgZ5tklBvplje4Q1KGFhqdA";

        Tradeapi api; //REST
        api.init(PaperEndPoint,KeyID,SecretKey);

        // auto account = api.get_account();
        // std::cout << account.buying_power << std::endl;
        // std::cout << account.created_at << std::endl;

        // auto order = api.submit_order(true, "TSLA", 1, "sell", "market", "day");
        // auto orders = api.list_orders("all", 3, "", "", "", "TSLA,SPY" );
        // for (const auto& o : orders) {
        //     std::cout << o.qty << std::endl;
        // }
        // auto order1 = api.get_order("cbaa4bf4-ad6d-47ee-b60b-e7059a471886");
        // auto changed_order = api.change_order_by_client_order_id("cbaa4bf4-ad6d-47ee-b60b-e7059a471886", 567);
        // auto positions = api.list_positions();
        //
        // std::vector<Quote> quotes_stocks = api.get_latest_quotes_stocks("TSLA,AAPL,MSFT,SPY");
        // // std::vector<Quote> quotes_options = api.get_latest_quotes_options("TSLA");
        // for (const auto& quote : quotes_stocks) {
        //     std::cout << quote.symbol << std::endl;
        // }

        auto trades_stocks = api.get_latest_trades_stocks("TSLA,AAPL");
        for (const auto& trade : trades_stocks) {
            std::cout << trade.trade_price << std::endl;
        }
        return 0;
    }
