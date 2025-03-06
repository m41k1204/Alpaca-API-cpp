#include "Order.h"
#include <stdexcept>

// Helper function to safely convert a Json::Value to double.
static double jsonToDouble(const Json::Value &value) {
    if (value.isDouble()) {
        return value.asDouble();
    } else if (value.isString()) {
        try {
            return std::stod(value.asString());
        } catch (const std::exception& e) {
            // Log the error or handle it appropriately
            return 0.0;
        }
    }
    return 0.0;
}

Order::Order(const Json::Value& data)
    : id(data.get("id", "").asString()),
      client_order_id(data.get("client_order_id", "").asString()),
      created_at(data.get("created_at", "").asString()),
      updated_at(data.get("updated_at", "").asString()),
      submitted_at(data.get("submitted_at", "").asString()),
      filled_at(data.get("filled_at", "").asString()),
      expired_at(data.get("expired_at", "").asString()),
      canceled_at(data.get("canceled_at", "").asString()),
      asset_id(data.get("asset_id", "").asString()),
      symbol(data.get("symbol", "").asString()),
      exchange(data.get("exchange", "").asString()),
      asset_class(data.get("asset_class", "").asString()),
      qty(jsonToDouble(data["qty"])),
      filled_qty(jsonToDouble(data["filled_qty"])),
      type(data.get("type", "").asString()),
      side(data.get("side", "").asString()),
      time_in_force(data.get("time_in_force", "").asString()),
      limit_price(jsonToDouble(data["limit_price"])),
      stop_price(jsonToDouble(data["stop_price"])),
      status(data.get("status", "").asString()),
      json(data)
{

    // Additional validation or error handling could be added here.
}
