#include "TradeToCSV.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

static std::string escape_csv(const std::string& field) {
    bool needQuotes = field.find(',') != std::string::npos ||
                      field.find('"') != std::string::npos ||
                      field.find('\n') != std::string::npos;
    if (!needQuotes) {
        return field;
    }
    std::string escaped = "\"";
    for (char c : field) {
        if (c == '"') {
            escaped += "\"\"";
        } else {
            escaped.push_back(c);
        }
    }
    escaped += "\"";
    return escaped;
}

void writeTradesToCSV(const std::vector<Trade>& trades) {
    std::string directory = "output";

    if (!fs::exists(directory)) {
        if (!fs::create_directories(directory)) {
            std::cerr << "Error: could not create directory: " << directory << std::endl;
            return;
        }
    }

    std::string filePath = directory + "/trades.csv";

    bool fileAlreadyExists = fs::exists(filePath);

    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    if (!fileAlreadyExists) {
        outFile << "message_type,symbol,trade_id,exchange_code,trade_price,trade_size,trade_condition,timestamp,tape\n";
    }

    for (const auto& trade : trades) {
        outFile << escape_csv(trade.message_type) << ",";
        outFile << escape_csv(trade.symbol) << ",";
        outFile << trade.trade_id << ",";
        outFile << escape_csv(trade.exchange_code) << ",";
        outFile << trade.trade_price << ",";
        outFile << trade.trade_size << ",";

        std::ostringstream conditionStream;
        for (size_t i = 0; i < trade.trade_condition.size(); ++i) {
            conditionStream << trade.trade_condition[i];
            if (i < trade.trade_condition.size() - 1) {
                conditionStream << ";";
            }
        }
        outFile << escape_csv(conditionStream.str()) << ",";
        outFile << escape_csv(trade.timestamp) << ",";
        outFile << escape_csv(trade.tape) << "\n";
    }

    outFile.close();
}
