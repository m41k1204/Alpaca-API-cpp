//
// Created by m41k1 on 2/6/25.
//

#ifndef ASSET_H
#define ASSET_H


#include <json/json.h>

class Asset {
public:
    Asset(Json::Value);

    std::string id;
    std::string asset_class;
    std::string exchange;
    std::string symbol;
    std::string status;
    bool tradable;

    //Keep Json
    Json::Value json;

};


#endif //ASSET_H
