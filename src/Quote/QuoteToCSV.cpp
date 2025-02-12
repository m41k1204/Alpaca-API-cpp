#include "QuoteToCSV.h"
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
            escaped += "\"\""; // Escape quotes by doubling them.
        } else {
            escaped.push_back(c);
        }
    }
    escaped += "\"";
    return escaped;
}

void writeQuotesToCSV(const std::vector<Quote>& quotes) {
    std::string directory = "output";

    if (!fs::exists(directory)) {
        if (!fs::create_directories(directory)) {
            std::cerr << "Error: could not create directory: " << directory << std::endl;
            return;
        }
    }

    std::string filePath = directory + "/quotes.csv";

    bool fileAlreadyExists = fs::exists(filePath);

    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    if (!fileAlreadyExists) {
        outFile << "message_type,symbol,ask_exchange_code,ask_prize,ask_size,"
                   "bid_exchange_code,bid_prize,bid_size,quote_condition,"
                   "timestamp,tape\n";
    }

    for (const auto& quote : quotes) {
        outFile << escape_csv(quote.message_type) << "";
        outFile << escape_csv(quote.symbol) << ",";
        outFile << escape_csv(quote.ask_exchange_code) << ",";
        outFile << quote.ask_prize << ",";
        outFile << quote.ask_size << ",";
        outFile << escape_csv(quote.bid_exchange_code) << ",";
        outFile << quote.bid_prize << ",";
        outFile << quote.bid_size << ",";

        std::ostringstream conditionStream;
        for (size_t i = 0; i < quote.quote_condition.size(); ++i) {
            conditionStream << quote.quote_condition[i];
            if (i < quote.quote_condition.size() - 1) {
                conditionStream << ";";
            }
        }
        outFile << escape_csv(conditionStream.str()) << ",";
        outFile << escape_csv(quote.timestamp) << ",";
        outFile << escape_csv(quote.tape) << "\n";
    }

    outFile.close();
}
