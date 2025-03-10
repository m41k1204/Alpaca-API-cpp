# Alpaca API C++ Client Library

This C++ library is designed to interact with the [Alpaca Markets API](https://alpaca.markets/), enabling developers to programmatically trade stocks, access market data, and manage portfolios with a focus on simplicity and performance.

## 📚 Features
- **REST API Integration**: Interact with Alpaca's RESTful API for account management, placing orders, and querying market data.
- **WebSocket Support**: Subscribe to real-time updates for trades, quotes, and account information.
- **Order Management**: Create, retrieve, update, and cancel stock orders efficiently.
- **Data Retrieval**: Access historical and real-time market data.
- **Portfolio Management**: View account details, positions, and portfolio summaries.

---

## ⚙️ Prerequisites

- C++17 or higher
- CMake (version 3.10+)
- [cURL](https://curl.se/) for HTTP requests
- [nlohmann/json](https://github.com/nlohmann/json) for JSON processing
- [WebSocket++](https://github.com/zaphoyd/websocketpp) for WebSocket communication

> Ensure you have an Alpaca account and API keys ready to use.

---

## 🛠️ Installation

### 1. Clone the Repository
```bash
git clone https://github.com/m41k1204/Alpaca-API-cpp.git
cd Alpaca-API-cpp
```

### 2. Configure the Build System
```bash
mkdir build
cd build
cmake ..
```

### 3. Build the Project
```bash
make
```

### 4. Run the Application
```bash
./AlpacaApiApp
```

---

## 🔑 Configuration

Create a `.env` file or directly configure your API keys in the `main.cpp` file:
```cpp
#define APCA_API_KEY "your_api_key"
#define APCA_API_SECRET_KEY "your_secret_key"
#define APCA_API_BASE_URL "https://paper-api.alpaca.markets"
```

> **Note:** For production, switch the `APCA_API_BASE_URL` to the live trading endpoint.

---

## 🚀 Usage Examples

### Place a New Order
```cpp
Order order;
order.symbol = "AAPL";
order.qty = 10;
order.side = "buy";
order.type = "market";
order.time_in_force = "gtc";
api.place_order(order);
```

### Get Account Information
```cpp
Account account = api.get_account();
std::cout << "Account Balance: " << account.cash << std::endl;
```

### Subscribe to WebSocket
```cpp
api.subscribe_to_trades("AAPL", [](const Trade& trade) {
    std::cout << "Trade Price: " << trade.price << std::endl;
});
```

---

## 🧩 Project Structure

```
├── src
│   ├── AlpacaApi.cpp     # Core API logic
│   ├── AlpacaApi.h       # API interface definitions
│   └── main.cpp          # Example usage and entry point
├── include
│   └── AlpacaApi.h       # Public headers
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```

---

## ✅ Testing

To run tests, use the provided testing framework (e.g., Google Test) if available:
```bash
make test
```

Ensure that API keys used for testing have limited permissions.

---

## 📄 Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Create a pull request.

---

## ⚖️ License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 📞 Support

For issues and feature requests, please open an [issue](https://github.com/m41k1204/Alpaca-API-cpp/issues).

> **Note:** This project is a community contribution and is not officially maintained by Alpaca Markets.

---

## 📚 References
- [Alpaca API Documentation](https://alpaca.markets/docs/api-references/)
- [cURL Documentation](https://curl.se/docs/)
- [nlohmann/json](https://github.com/nlohmann/json)
- [WebSocket++](https://github.com/zaphoyd/websocketpp)

