#include <iostream>
#include "src/TradeApi/Tradeapi.h"
#include "src/Quote/QuoteToCSV.h"
#include "src/Trade/TradeToCSV.h"

#include <cstdlib>

int main() {
    std::cout << "Hello World!\n";

    std::string PaperEndPoint = "paper-api.alpaca.markets";
    std::string RealEndPoint = "api.alpaca.markets";
    std::string KeyID = "PKFLBRNDM7BIV5MLF36G";
    std::string SecretKey = "ftKAoYm4BaDIxbytzVgZ5tklBvplje4Q1KGFhqdA";

    Tradeapi api;
    api.init(PaperEndPoint, KeyID, SecretKey);

    // api.change_order_by_client_order_id("", 2);

    std::vector<Trade> operaciones = api.get_latest_trades_stocks("AAPL,TSLA", "USD");
    for (const auto& trade : operaciones) {
        std::cout << "Trade - Símbolo: " << trade.symbol << ", Precio: " << trade.trade_price << std::endl;
    }
    // std::vector<Quote> quotes_container;
    //
    //     std::cout << "Ingrese quote" << std::endl;
    //     std::string symbol;
    //     std::string symbols;
    //     std::cin >> symbol;
    //     while (symbol != "&") {
    //         symbols += symbol + ",";
    //         std::cin >> symbol;
    //     }
    //
    //     std::vector<Quote> quotes = api.get_latest_quotes_stocks(symbols);
    //     for (auto q : quotes) {quotes_container.push_back(q);}
    //
    // writeQuotesToCSV(quotes);
    //


    return 0;
}
