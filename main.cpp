#include <iostream>
#include "src/TradeApi/Tradeapi.h"
#include <cstdlib>

int main() {

    std::cout << "Hello World!\n";

    std::string EndPoint = "paper-api.alpaca.markets";
    std::string KeyID = "PKFLBRNDM7BIV5MLF36G";
    std::string SecretKey = "ftKAoYm4BaDIxbytzVgZ5tklBvplje4Q1KGFhqdA";

    Tradeapi api; //REST
    api.init(EndPoint,KeyID,SecretKey);

    auto account = api.get_account();
    // std::cout << account.buying_power << std::endl;
    // std::cout << account.created_at << std::endl;

    // auto order = api.submit_order("TSLA", 54, "buy", "market", "day");
    // auto orders = api.list_orders("all", 3);
    // for (const auto& o : orders) {
    //     std::cout << o.qty << std::endl;
    // }
    // auto order = api.get_order("f85a3a86-34cc-40d7-a38b-e6e67fa9cd2b");
    // auto changed_order = api.change_order_by_client_order_id("f85a3a86-34cc-40d7-a38b-e6e67fa9cd2b", 567);
    return 0;
}
