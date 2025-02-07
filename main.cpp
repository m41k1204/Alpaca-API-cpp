#include <iostream>
#include "src/TradeApi/Tradeapi.h"
#include <cstdlib>

int main() {

    std::cout << "Hello World!\n";

//    const char* api_key = std::getenv("APCA_API_KEY_ID");
//    const char* secret_key = std::getenv("APCA_API_SECRET_KEY");
//
//    if (api_key && secret_key) {
//        std::cout << "API Key: " << api_key << std::endl;
//        std::cout << "Secret Key: " << secret_key << std::endl;
//    } else {
//        std::cerr << "Environment variables not set!" << std::endl;
//        return 1; // Error code
//    }

    std::string EndPoint = "paper-api.alpaca.markets";
    std::string KeyID = "PKFLBRNDM7BIV5MLF36G";
    std::string SecretKey = "ftKAoYm4BaDIxbytzVgZ5tklBvplje4Q1KGFhqdA";

    Tradeapi api; //REST
    api.init(EndPoint,KeyID,SecretKey);

    auto account = api.get_account();
    std::cout << account.buying_power << std::endl;
    std::cout << account.created_at << std::endl;

    return 0;
}
