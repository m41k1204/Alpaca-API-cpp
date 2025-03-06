#include "Tradeapi.h"
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <json/json.h>

void Tradeapi::init(const std::string& BaseUrl, const std::string& KeyID, const std::string& SecretKey) {
    this-> BaseUrl = BaseUrl;
    this->KeyID = KeyID;
    this->SecretKey = SecretKey;
}

size_t Tradeapi::callback(const char* in, size_t size, size_t num, std::string* out) {
    out->append(in, size * num);
    return size * num;
}

Json::Value Tradeapi::send_request(const bool trading, const bool stock, const std::string& method, const std::string& endpoint, const std::string& params) const {
    std::string base_url;
    if (trading) {
        base_url = "https://" + BaseUrl + "/v2";
    }
    else {
        if (stock) base_url = "https://data.alpaca.markets/v2";
        else base_url = "https://data.alpaca.markets/v1beta1";
    }
    std::string url = base_url + endpoint;

    CURL* curl = curl_easy_init();
    if (!curl) return Json::Value();

    if(method == "GET" && !params.empty()){
        url += params;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("APCA-API-KEY-ID: " + KeyID).c_str());
    headers = curl_slist_append(headers, ("APCA-API-SECRET-KEY: " + SecretKey).c_str());

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());


    if(method == "POST" || method == "PATCH"){
        // Set the custom request to POST.
        // Use params as the POST payload.
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
        // Append headers for JSON data.
        headers = curl_slist_append(headers, "accept: application/json");
        headers = curl_slist_append(headers, "content-type: application/json");
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    std::string response_string;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    CURLcode res = curl_easy_perform(curl);

    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    Json::Value jsonData;
    if (http_code == 200) {
        Json::CharReaderBuilder reader;
        std::string errs;
        std::istringstream iss(response_string);
        if (!Json::parseFromStream(reader, iss, &jsonData, &errs)) {
            std::cerr << "Failed to parse JSON: " << errs << std::endl;
        } else {
            // Optionally, print the formatted JSON for debugging.
            Json::StreamWriterBuilder writer;
            writer["indentation"] = "   ";
            std::string output = Json::writeString(writer, jsonData);
            // std::cout << "Debug JSON Output:\n" << output << std::endl;
        }
    } else if (http_code == 204) {
    } else {
        std::cerr << "HTTP Error Code: " << http_code << "\n" << response_string << std::endl;
    }


    return jsonData;
}

Account Tradeapi::get_account() {
    return Account(send_request(true, false, "GET", "/account"));
}

Order Tradeapi::submit_order_stock(
    const std::string& symbol,
    const int qty,
    const std::string& side,
    const std::string& type,
    const std::string& time_in_force,
    const double limit_price,
    const double stop_price,
    const std::string& client_order_id,
    const double bracket_take_profit_price,
    const double bracket_stop_loss_price) const {
    Json::Value data;
    data["symbol"] = symbol;
    data["qty"] = qty;
    data["side"] = side;
    data["type"] = type;
    data["time_in_force"] = time_in_force;
    if (!client_order_id.empty()) {
        data["client_order_id"] = client_order_id;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << limit_price;
    if (type == "limit") {
        data["limit_price"] = oss.str();
    }
    if (type == "stop" || type == "stop_limit") {
        data["stop_price"] = stop_price;
    }

    // If bracket order parameters are provided, add stop loss and take profit details.
    if (bracket_take_profit_price > 0.0 || bracket_stop_loss_price > 0.0) {
        data["order_class"] = "bracket";
        if (bracket_take_profit_price > 0.0) {
            Json::Value tp;
            std::ostringstream oss_tp;
            oss_tp << std::fixed << std::setprecision(2) << bracket_take_profit_price;
            tp["limit_price"] = oss_tp.str();
            data["take_profit"] = tp;
        }
        if (bracket_stop_loss_price > 0.0) {
            Json::Value sl;
            std::ostringstream oss_sl;
            oss_sl << std::fixed << std::setprecision(2) << bracket_stop_loss_price;
            sl["stop_price"] = oss_sl.str();
            data["stop_loss"] = sl;
        }
    }

    const Json::StreamWriterBuilder writer;
    return {send_request(true, true, "POST", "/orders", Json::writeString(writer, data))};
}
Order Tradeapi::submit_order_option(
    const std::string& symbol,
    const int qty,
    const std::string& side,
    const std::string& type,
    const std::string& time_in_force,
    const double limit_price,
    const double stop_price,
    const std::string& client_order_id,
    const double bracket_take_profit_price,
    const double bracket_stop_loss_price) const {
    Json::Value data;
    data["symbol"] = symbol;
    data["qty"] = qty;
    data["side"] = side;
    data["type"] = type;
    data["time_in_force"] = time_in_force;
    if (!client_order_id.empty()) {
        data["client_order_id"] = client_order_id;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << limit_price;
    if (type == "limit") {
        data["limit_price"] = oss.str();
    }
    if (type == "stop" || type == "stop_limit") {
        data["stop_price"] = stop_price;
    }

    // Add bracket order parameters if provided.
    if (bracket_take_profit_price > 0.0 || bracket_stop_loss_price > 0.0) {
        data["order_class"] = "bracket";
        if (bracket_take_profit_price > 0.0) {
            Json::Value tp;
            std::ostringstream oss_tp;
            oss_tp << std::fixed << std::setprecision(2) << bracket_take_profit_price;
            tp["limit_price"] = oss_tp.str();
            data["take_profit"] = tp;
        }
        if (bracket_stop_loss_price > 0.0) {
            Json::Value sl;
            std::ostringstream oss_sl;
            oss_sl << std::fixed << std::setprecision(2) << bracket_stop_loss_price;
            sl["stop_price"] = oss_sl.str();
            data["stop_loss"] = sl;
        }
    }

    const Json::StreamWriterBuilder writer;
    return {send_request(true, false, "POST", "/orders", Json::writeString(writer, data))};
}


std::vector<Order> Tradeapi::list_orders(const std::string& status,
                                        int limit,
                                        const std::string& after,
                                        const std::string& until,
                                        const std::string& direction,
                                        const std::string& symbols,
                                        const std::string& side) const {
    std::string params;
    params.append("?status="+status);
    params.append("&limit="+std::to_string(limit));
    if (!after.empty()) params.append("&after=" + after);
    if (!until.empty()) params.append("&until=" + until);
    if (!direction.empty()) params.append("&direction=" + direction);
    if (!symbols.empty()) params.append("&symbols=" + symbols);
    if (!side.empty()) params.append("&side=" + side);


    Json::Value ordersJson = send_request(true, true, "GET", "/orders",params);
    std::vector<Order> orders;

    // Check if the returned JSON is an array.
    if (ordersJson.isArray()) {
        for (const auto& orderJson : ordersJson) {
            // If a positive limit is specified, break out of the loop once reached.
            if (limit > 0 && orders.size() >= static_cast<size_t>(limit))
                break;
            orders.emplace_back(orderJson);
        }
    } else {
        std::cerr << "Expected an array of orders, but got a different JSON structure." << std::endl;
    }
    return orders;
}

Order Tradeapi::get_order(const std::string& order_id) {
    return Order(send_request(true, true, "GET", "/orders/" + order_id));
}

Order Tradeapi::cancel_order(const std::string& order_id) {
    auto order = send_request(true, true, "DELETE", "/orders/" + order_id);
    order = send_request(true, true, "GET", "/orders/" + order_id);
    return order;

}

std::vector<Position> Tradeapi::list_positions() {
    Json::Value positions = send_request(true, true, "GET", "/positions");
    return std::vector<Position>(std::begin(positions), std::end(positions));
}

Position Tradeapi::get_position(const std::string& symbol) {
    Json::Value resp = send_request(true, true, "GET", "/positions/" + symbol);
    return resp.isNull() ? Position(symbol) : Position(resp);
}

std::vector<Quote> Tradeapi::get_latest_quotes_stocks(const std::string& symbols) const {
    const std::string params = "?symbols=" + symbols;

    Json::Value quotes_json = send_request(false, true, "GET", "/stocks/quotes/latest", params);
    std::vector<Quote> quotes;

    // If the quotes are nested under a "quotes" key, use that object.
    const Json::Value quotesObject = quotes_json.isMember("quotes") ? quotes_json["quotes"] : quotes_json;

    for (const std::string& symbol : quotesObject.getMemberNames()) {
        const Json::Value& quoteData = quotesObject[symbol];
        quotes.emplace_back(symbol, quoteData);
    }

    return quotes;
}

std::vector<Quote> Tradeapi::get_latest_quotes_options(const std::string& symbols) const {
    std::string params;
    params.append("?symbols=" + symbols);

    Json::Value quotes_json = send_request(false, false, "GET", "/options/quotes/latest", params);
    std::vector<Quote> quotes;

    const Json::Value quotesObject = quotes_json.isMember("quotes") ? quotes_json["quotes"] : quotes_json;

    for (const std::string& symbol : quotesObject.getMemberNames()) {
        const Json::Value& quoteData = quotesObject[symbol];
        quotes.emplace_back(symbol, quoteData);
    }

    return quotes;
}

std::vector<Trade> Tradeapi::get_latest_trades_stocks(const std::string &symbols) const {
    std::string params;
    params.append("?symbols=" + symbols);

    Json::Value trades_json = send_request(false, true, "GET", "/stocks/trades/latest", params);
    std::vector<Trade> trades;

    const Json::Value tradesObject = trades_json.isMember("trades") ? trades_json["trades"] : trades_json;

    for (const std::string& symbol : tradesObject.getMemberNames()) {
        const Json::Value& quoteData = tradesObject[symbol];
        trades.emplace_back(symbol, quoteData);
    }

    return trades;
}

std::vector<Trade> Tradeapi::get_latest_trades_options(const std::string &symbols) const {
    std::string params;
    params.append("?symbols=" + symbols);

    Json::Value trades_json = send_request(false, false, "GET", "/options/trades/latest", params);
    std::vector<Trade> trades;

    const Json::Value tradesObject = trades_json.isMember("trades") ? trades_json["trades"] : trades_json;

    for (const std::string& symbol : tradesObject.getMemberNames()) {
        const Json::Value& quoteData = tradesObject[symbol];
        trades.emplace_back(symbol, quoteData);
    }

    return trades;
}

std::vector<Trade> Tradeapi::get_historical_data_stocks(const std::string &symbols, const int offset, const int limit) const {
    // Obtener el tiempo actual y redondear al minuto actual
    auto now = std::chrono::system_clock::now();
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_t);
    now_tm.tm_sec = 0;  // reiniciar los segundos al inicio del minuto
    std::time_t current_minute = std::mktime(&now_tm);

    // Calcular el tiempo de inicio: offset segundos antes del minuto actual
    std::time_t start_time = current_minute - offset;

    // Formatear los tiempos como cadenas en formato ISO 8601 (ej. "YYYY-MM-DDTHH:MM:SSZ")
    std::stringstream ss_start, ss_end;
    ss_start << std::put_time(std::localtime(&start_time), "%Y-%m-%dT%H:%M:%SZ");
    ss_end << std::put_time(std::localtime(&current_minute), "%Y-%m-%dT%H:%M:%SZ");
    std::string start = ss_start.str();
    std::string end = ss_end.str();

    // Construir los parámetros de la solicitud
    std::string params;
    params.append("?symbols=" + symbols);
    params.append("&start=" + start);
    params.append("&end=" + end);
    params.append("&limit=" + std::to_string(limit));

    // Enviar la solicitud y procesar la respuesta JSON
    Json::Value trades_json = send_request(false, true, "GET", "/stocks/trades", params);
    std::vector<Trade> trades;

    // Verificar si la respuesta contiene la clave "trades"
    if (trades_json.isMember("trades")) {
        const Json::Value tradesBySymbol = trades_json["trades"];
        // Iterar sobre cada clave (símbolo) en el objeto "trades"
        for (const std::string& symbol : tradesBySymbol.getMemberNames()) {
            const Json::Value& tradesArray = tradesBySymbol[symbol];
            // Si el valor es un arreglo, iterar sobre cada trade
            if (tradesArray.isArray()) {
                for (const auto& tradeData : tradesArray) {
                    trades.emplace_back(symbol, tradeData);
                }
            } else {
                // Si no es un arreglo, tratarlo como un objeto único
                trades.emplace_back(symbol, tradesArray);
            }
        }
    } else {
        std::cerr << "La respuesta JSON no contiene la clave 'trades': "
                  << trades_json.toStyledString() << std::endl;
    }

    return trades;
}
std::vector<Trade> Tradeapi::get_historical_data_options(const std::string &symbols, const std::string &start,
    const std::string &end, const int limit) const {

    std::string params;
    params.append("&symbols=" + symbols);
    params.append("?start=" + start);
    params.append("?end=" + end);
    params.append("?limit=" + std::to_string(limit));

    Json::Value trades_json = send_request(false, false, "GET", "/options/trades", params);
    std::vector<Trade> trades;

    const Json::Value tradesObject = trades_json.isMember("trades") ? trades_json["trades"] : trades_json;

    for (const std::string& symbol : tradesObject.getMemberNames()) {
        const Json::Value& quoteData = tradesObject[symbol];
        trades.emplace_back(symbol, quoteData);
    }

    return trades;
}


Order Tradeapi::change_order_by_order_id(
    const std::string& client_order_id,
    std::optional<int> qty,
    std::optional<std::string> time_in_force,
    std::optional<double> limit_price,
    std::optional<double> stop_price)
{
    Json::Value data;

    if (qty.has_value()) {
        data["qty"] = qty.value();
    }
    if (time_in_force.has_value()) {
        data["time_in_force"] = time_in_force.value();
    }
    if (limit_price.has_value()) {
        data["limit_price"] = limit_price.value();
    }
    if (stop_price.has_value()) {
        data["stop_price"] = stop_price.value();
    }

    // Build the payload as a JSON string.
    const Json::StreamWriterBuilder writer;
    std::string payload = Json::writeString(writer, data);

    // Send the PATCH request and construct an Order from the response.
    return Order(send_request( true, true, "PATCH", "/orders/" + client_order_id, payload));
}



// std::vector<Asset> Tradeapi::list_assets(const std::string& status, const std::string& asset_class) {
//     return std::vector<Asset>(std::begin(send_request("GET", "/assets", "?status=" + status + "&asset_class=" + asset_class)),
//                               std::end(send_request("GET", "/assets", "?status=" + status + "&asset_class=" + asset_class)));
// }
//
// Asset Tradeapi::get_asset(const std::string& symbol) {
//     return Asset(send_request("GET", "/assets/" + symbol));
// }
//
// Json::Value Tradeapi::get_barset(const std::vector<std::string>& symbols, const std::string& timeframe, int limit) {
//     std::string symbols_str = "symbols=";
//     for (const auto& s : symbols) symbols_str += s + ",";
//     symbols_str.pop_back();
//     return send_request("GET", "/bars/" + timeframe, "?" + symbols_str + "&limit=" + std::to_string(limit));
// }
//
// Clock Tradeapi::get_clock() {
//     return Clock(send_request("GET", "/clock"));
// }
//
// Json::Value Tradeapi::get_calendar(const std::string& start, const std::string& end) {
//     return send_request("GET", "/calendar", "?start=" + start + "&end=" + end);
// }