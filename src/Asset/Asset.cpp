//
// Created by m41k1 on 2/6/25.
//

#include "Asset.h"

Asset::Asset(Json::Value data) {
    id = data["id"].asString();
    asset_class = data["asset_class"].asString();
    exchange = data["exchange"].asString();
    symbol = data["symbol"].asString();
    status = data["status"].asString();
    tradable = data["tradable"].asBool();

    json = data;
}