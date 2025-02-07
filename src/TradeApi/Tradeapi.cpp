#include "Tradeapi.h"
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <json/json.h>

void Tradeapi::init(const std::string& EndPoint, const std::string& KeyID, const std::string& SecretKey) {
    this->base_url = "https://" + EndPoint + "/v2";
    this->KeyID = KeyID;
    this->SecretKey = SecretKey;
}

size_t Tradeapi::callback(const char* in, size_t size, size_t num, std::string* out) {
    out->append(in, size * num);
    return size * num;
}

Json::Value Tradeapi::send_request(const std::string& method, const std::string& endpoint, const std::string& params) {
    CURL* curl = curl_easy_init();
    if (!curl) return Json::Value();

    std::string request = base_url + endpoint + params;
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("APCA-API-KEY-ID: " + KeyID).c_str());
    headers = curl_slist_append(headers, ("APCA-API-SECRET-KEY: " + SecretKey).c_str());

    std::string response_string;
    long http_code = 0;
    curl_easy_setopt(curl, CURLOPT_URL, request.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    Json::Value jsonData;
    if (http_code == 200) {
        Json::CharReaderBuilder reader;
        std::string errs;
        std::istringstream iss(response_string);
        Json::parseFromStream(reader, iss, &jsonData, &errs);
    }
    return jsonData;
}

Account Tradeapi::get_account() {
    return Account(send_request("GET", "/account"));
}

Order Tradeapi::submit_order(const std::string& symbol, int qty, const std::string& side, const std::string& type,
                             const std::string& time_in_force, double limit_price, double stop_price,
                             const std::string& client_order_id) {
    Json::Value data;
    data["symbol"] = symbol;
    data["qty"] = qty;
    data["side"] = side;
    data["type"] = type;
    data["time_in_force"] = time_in_force;
    if (type == "limit") data["limit_price"] = limit_price;
    if (type == "stop" || type == "stop_limit") data["stop_price"] = stop_price;
    Json::StreamWriterBuilder writer;
    return Order(send_request("POST", "/orders", Json::writeString(writer, data)));
}

std::vector<Order> Tradeapi::list_orders(const std::string& status, int limit) {
    return std::vector<Order>(std::begin(send_request("GET", "/orders", "?status=" + status)), std::end(send_request("GET", "/orders", "?status=" + status)));
}

Order Tradeapi::get_order(const std::string& order_id) {
    return Order(send_request("GET", "/orders/" + order_id));
}

Order Tradeapi::get_order_by_client_order_id(const std::string& client_order_id) {
    return Order(send_request("GET", "/orders:by_client_order_id?client_order_id=" + client_order_id));
}

void Tradeapi::cancel_order(const std::string& order_id) {
    send_request("DELETE", "/orders/" + order_id);
}

std::vector<Position> Tradeapi::list_positions() {
    return std::vector<Position>(std::begin(send_request("GET", "/positions")), std::end(send_request("GET", "/positions")));
}

Position Tradeapi::get_position(const std::string& symbol) {
    Json::Value resp = send_request("GET", "/positions/" + symbol);
    return resp.isNull() ? Position(symbol) : Position(resp);
}

std::vector<Asset> Tradeapi::list_assets(const std::string& status, const std::string& asset_class) {
    return std::vector<Asset>(std::begin(send_request("GET", "/assets", "?status=" + status + "&asset_class=" + asset_class)),
                              std::end(send_request("GET", "/assets", "?status=" + status + "&asset_class=" + asset_class)));
}

Asset Tradeapi::get_asset(const std::string& symbol) {
    return Asset(send_request("GET", "/assets/" + symbol));
}

Json::Value Tradeapi::get_barset(const std::vector<std::string>& symbols, const std::string& timeframe, int limit) {
    std::string symbols_str = "symbols=";
    for (const auto& s : symbols) symbols_str += s + ",";
    symbols_str.pop_back();
    return send_request("GET", "/bars/" + timeframe, "?" + symbols_str + "&limit=" + std::to_string(limit));
}

Clock Tradeapi::get_clock() {
    return Clock(send_request("GET", "/clock"));
}

Json::Value Tradeapi::get_calendar(const std::string& start, const std::string& end) {
    return send_request("GET", "/calendar", "?start=" + start + "&end=" + end);
}
