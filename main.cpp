#include <iostream>
#include "src/TradeApi/Tradeapi.h"
#include "src/Quote/QuoteToCSV.h"
#include "src/Trade/TradeToCSV.h"

#include <cstdlib>


using namespace std;


int main() {

    vector<Order> ordenes;
    vector<Position> posiciones;
    vector<Quote> lQuotes;
    vector<Trade> lTrades;
    Order lOrden;
    //Position lPosTemp;

    bool lContinua = true;
    char lBehaviour, lModifica, lContinuaT;
    string lActivo, lTicker, lTipo, lTiempo, lIdOrden, lSide, lStatus, lTickers;
    int lQty, lCantMax;
    double lPrecio;

    cout << "Set de pruebas para trade con API de ALPACA" << endl;

    std::string PaperEndPoint = "paper-api.alpaca.markets";
    std::string RealEndPoint = "api.alpaca.markets";
    // std::string KeyID = "";
    // std::string SecretKey = "";

    Tradeapi api;                                   // Se define api como un Tradeapi
    api.init(PaperEndPoint, KeyID, SecretKey);      // Cambiar PaperEndPoint o RealEndPoint dependiendo del caso

    lTrades = api.get_latest_trades_stocks("AAPL");
    for (const auto& trade : lTrades) {
        std::cout << "Trade - Símbolo: " << trade.symbol << ", Precio: " << trade.trade_price << ", Timestamp: " << trade.timestamp << ::endl;
    }
    cout << "\n";
    cout << "\n";

    lTrades = api.get_historical_data_stocks("AAPL", 2, 10);
    for (const auto& trade : lTrades) {
        std::cout << "Trade - Símbolo: " << trade.symbol << ", Precio: " << trade.trade_price << ", Timestamp: " << trade.timestamp << ::endl;
    }


    // while (lContinua) {
    //     cout << "Definir instrucción (B=Buy, S=Sell, M=Modify, C=Cancel, L=ListOrders, G=GetOrder, "
    //             "P=ListPositions, E=GetPositionDetail, Q=LatestQuotes, T=LatestTrades ) : ";
    //     cin >> lBehaviour;
    //     if ((lBehaviour == 'B') || (lBehaviour == 'S')) {
    //         cout << "Indicar si es S=Stock u O=Option :";
    //         cin >> lActivo;
    //         cout << "Indicar el Ticker                :";
    //         cin >> lTicker;
    //         cout << "Indicar la Cantidad              :";
    //         cin >> lQty;
    //         cout << "Indicar si es MKT o LMT          :";
    //         cin >> lTipo;
    //         if (lTipo == "LMT") {
    //             cout << "Indicar si es el precio límite   :";
    //             cin >> lPrecio;
    //         }
    //         else lPrecio = 0;
    //         cout << "Indicar si es DAY o GTC          :";
    //         cin >> lTiempo;
    //         if (lTiempo =="DAY") lTiempo = "day";
    //         else if (lTiempo == "GTC") lTiempo = "gtc";
    //         if (lBehaviour == 'B') lSide = "buy";
    //         else lSide = "sell";
    //         if (lTipo == "MKT") lTipo = "market";
    //         else lTipo = "limit";
    //         if (lActivo == "S") {
    //             // Envia la orden de Stock ------------------- OK
    //             lOrden = api.submit_order_stock(lTicker, lQty, lSide, lTipo, lTiempo, lPrecio, 0.0, "");
    //             cout << "Detalle de la orden puesta : " << lOrden.json << endl;
    //         }
    //         else if (lActivo == "O") {
    //             // Enviar una orden de mercado para comprar 10 contratos de opción de AAPL.
    //             lOrden = api.submit_order_option(lTicker, lQty, lSide, lTipo, lTiempo, lPrecio);
    //             cout << "Detalle de la orden puesta : " << lOrden.json << endl;
    //         }
    //     }
    //     else if (lBehaviour == 'M') {
    //         cout << "Escriba el id de la orden que quiere modificar :";
    //         cin >> lIdOrden;
    //         cout << "Indique que modificar (Q=Qty, P=Precio)        :";
    //         cin >> lModifica;
    //         if (lModifica == 'Q') {
    //             cout << "Escriba la nueva QTY :";
    //             cin >> lQty;
    //             lOrden = api.change_order_by_order_id(lIdOrden,lQty, nullopt, nullopt, nullopt);
    //             cout << "Orden modificada: " << lOrden.json << endl;
    //
    //         }
    //         else if (lModifica == 'P') {
    //             cout << "Escriba el nuevo Precio :";
    //             cin >> lPrecio;
    //             lOrden = api.change_order_by_order_id(lIdOrden,nullopt, nullopt, lPrecio, nullopt);
    //             cout << "Orden modificada: " << lOrden.json << endl;
    //         }
    //     }
    //     else if (lBehaviour == 'C') {
    //         cout << "Escriba el id de la orden a cancelar :";
    //         cin >> lIdOrden;
    //         lOrden = api.cancel_order(lIdOrden);
    //         cout << "Orden cancelada exitosamente :" << lOrden.status << endl;
    //     }
    //     else if (lBehaviour == 'L') {
    //         cout << "Escriba el status de las ordenes a listar (open/closed) :";
    //         cin >> lStatus;
    //         cout << "Escriba la lista de Tickers separados por coma (,)      :";
    //         cin >> lTickers;
    //         cout << "Escriba la cantidad máxima de ordenes a listar          :";
    //         cin >> lCantMax;
    //         cout << "Escriba si son buy/sell                                 :";
    //         cin >> lSide;
    //         ordenes.clear();
    //         if (lStatus == "all") lTickers = "";
    //         ordenes = api.list_orders(lStatus, lCantMax, "", "", "desc", lTickers, lSide);
    //         for (const auto& orden : ordenes) {
    //             cout << "ID Orden: " << orden.json << endl << endl;
    //         }
    //     }
    //     else if (lBehaviour == 'G') {
    //         cout << "Escriba el Client Order ID a consultar :";
    //         cin >> lIdOrden;
    //         lOrden = api.get_order(lIdOrden);
    //         cout << "Detalles de la orden: " << lOrden.json << endl << endl;
    //     }
    //     else if (lBehaviour == 'P') {
    //         posiciones.clear();
    //         posiciones = api.list_positions();
    //         for (const auto& pos : posiciones) {
    //             cout << pos.json << endl << endl;
    //         }
    //     }
    //     else if (lBehaviour == 'E') {
    //         cout << "Indicar el Ticker                :";
    //         cin >> lTicker;
    //         Position posicion = api.get_position(lTicker);
    //         cout << posicion.json << endl << endl;
    //     }
    //     else if (lBehaviour == 'Q') {
    //         cout << "Indicar si es S=Stock u O=Option  :";
    //         cin >> lActivo;
    //         cout << "Indicar Tickers separados por (,) :";
    //         cin >> lTickers;
    //         lQuotes.clear();
    //         if (lActivo == "S") {
    //             lQuotes = api.get_latest_quotes_stocks(lTickers);
    //             for (const auto& lQuote : lQuotes) {
    //                 cout << "Ticker :" << lQuote.symbol << " - Precio Ask: " << lQuote.ask_price  << " - Precio Bid: " << lQuote.bid_price << " - Timestamp: " << lQuote.timestamp << endl;
    //                 //cout << cotizacion. << endl << endl;
    //             }
    //         }
    //         else if (lActivo == "O") {
    //             lQuotes = api.get_latest_quotes_options(lTickers);
    //             for (const auto& lQuote : lQuotes) {
    //                 cout << "Ticker Opción:" << lQuote.symbol << " - Precio Ask: " << lQuote.ask_price  << " - Precio Bid: " << lQuote.bid_price << " - Timestamp: " << lQuote.timestamp << endl;
    //             }
    //         }
    //     }
    //     else if (lBehaviour == 'T') {
    //         cout << "Indicar si es S=Stock u O=Option  :";
    //         cin >> lActivo;
    //         cout << "Indicar Tickers separados por (,) :";
    //         cin >> lTicker;
    //         lTrades.clear();
    //         if (lActivo == "S") {
    //             lTrades = api.get_latest_trades_stocks(lTicker);
    //             for (const auto& trade : lTrades) {
    //                 cout << "Trade - Símbolo: " << trade.symbol << " - Precio: " << trade.trade_price << " - Volumen: " << trade.trade_size << " - Timestamp: " << trade.timestamp << endl;
    //             }
    //         }
    //         else if (lActivo == "O") {
    //             lTrades = api.get_latest_trades_options(lTicker);
    //             for (const auto& trade : lTrades) {
    //                 cout << "Trade - Ticker Opción: " << trade.symbol << " - Precio: " << trade.trade_price << " - Volumen: " << trade.trade_size << " - Timestamp: " << trade.timestamp << endl;
    //
    //             }
    //         }
    //     }
    //     cout << endl << "----------------------------------------------------------------------------------" << endl;
    //     cout << "Realizamos otra operación ? (S/N) :";
    //     cin >> lContinuaT;
    //     if (lContinuaT == 'N') lContinua = false;
    // }





    return 0;
}
