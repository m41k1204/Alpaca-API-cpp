# Documentación de TradeAPI

Este documento ofrece una descripción general de las funciones de TradeAPI, detallando cada uno de sus atributos (parámetros) y proporcionando ejemplos de uso en bloques de código.

- **`get_account()`**
  - **Descripción:** Recupera los detalles de la cuenta realizando una solicitud GET al endpoint `/account`.
  - **Atributos:** No recibe parámetros adicionales.
  - **Ejemplo:**
    ```cpp
    Account cuenta = api.get_account();
    std::cout << "ID de la Cuenta: " << cuenta.id << std::endl;
    ```

---

- **`submit_order(const bool stock, const std::string& symbol, const int qty, const std::string& side, const std::string& type, const std::string& time_in_force, const double limit_price, const double stop_price, const std::string& client_order_id) const`**
  - **Descripción:** Envía una nueva orden al API.
  - **Atributos:**
    - **`stock`**: `true` para órdenes de acciones, `false` para opciones.
    - **`symbol`**: Símbolo del activo (ticker).
    - **`qty`**: Cantidad de acciones o contratos.
    - **`side`**: Lado de la orden ("buy" o "sell").
    - **`type`**: Tipo de orden (por ejemplo, "market", "limit", "stop", "stop_limit").
    - **`time_in_force`**: Duración de la orden (por ejemplo, "day", "gtc").
    - **`limit_price`**: Precio límite (requerido para órdenes limit).
    - **`stop_price`**: Precio de stop (requerido para órdenes stop o stop_limit).
    - **`client_order_id`**: Identificador de la orden asignado por el cliente (opcional).
  - **Ejemplo:**
    ```cpp
    // Enviar una orden de mercado para comprar 5 acciones de AAPL.
    Order ordenMercado = api.submit_order(true, "AAPL", 5, "buy", "market", "day", 0.0, 0.0, "orden001");
    std::cout << "Estado de la orden: " << ordenMercado.status << std::endl;

    // Enviar una orden limit para vender 10 acciones de TSLA.
    Order ordenLimit = api.submit_order(true, "TSLA", 10, "sell", "limit", "day", 750.50, 0.0, "orden002");
    std::cout << "Estado de la orden: " << ordenLimit.status << std::endl;
    ```

---

- **`list_orders(const std::string& status, int limit, const std::string& after, const std::string& until, const std::string& direction, const std::string& symbols, const std::string& side) const`**
  - **Descripción:** Recupera una lista de órdenes aplicando filtros opcionales.
  - **Atributos:**
    - **`status`**: Filtra por estado de la orden (por ejemplo, "open", "closed").
    - **`limit`**: Número máximo de órdenes a retornar.
    - **`after`**: Recupera órdenes creadas después de esta marca de tiempo.
    - **`until`**: Recupera órdenes creadas hasta esta marca de tiempo.
    - **`direction`**: Dirección de ordenamiento ("asc" o "desc").
    - **`symbols`**: Símbolos (separados por comas) para filtrar las órdenes.
    - **`side`**: Filtra las órdenes por lado ("buy" o "sell").
  - **Ejemplo:**
    ```cpp
    std::vector<Order> ordenes = api.list_orders("open", 5, "", "", "desc", "AAPL,TSLA", "");
    for (const auto& orden : ordenes) {
      std::cout << "ID Orden: " << orden.id << " - Estado: " << orden.status << std::endl;
    }
    ```

---

- **`get_order(const std::string& order_id)`**
  - **Descripción:** Recupera información detallada de una orden específica usando su ID único.
  - **Atributos:**
    - **`order_id`**: El identificador único de la orden.
  - **Ejemplo:**
    ```cpp
    Order orden = api.get_order("order_id_123");
    std::cout << "Detalles de la orden: " << orden.toJson() << std::endl;
    ```

---

- **`get_order_by_client_order_id(const std::string& client_order_id)`**
  - **Descripción:** Recupera detalles de una orden utilizando un ID asignado por el cliente.
  - **Atributos:**
    - **`client_order_id`**: El identificador de la orden asignado por el cliente.
  - **Ejemplo:**
    ```cpp
    Order orden = api.get_order_by_client_order_id("client_order_abc");
    std::cout << "Detalles de la orden: " << orden.toJson() << std::endl;
    ```

---

- **`cancel_order(const std::string& order_id)`**
  - **Descripción:** Cancela una orden existente identificada por su ID.
  - **Atributos:**
    - **`order_id`**: El identificador único de la orden a cancelar.
  - **Ejemplo:**
    ```cpp
    api.cancel_order("order_id_123");
    std::cout << "Orden cancelada exitosamente." << std::endl;
    ```

---

- **`list_positions()`**
  - **Descripción:** Recupera una lista de las posiciones actuales en la cuenta.
  - **Atributos:** No recibe parámetros adicionales.
  - **Ejemplo:**
    ```cpp
    std::vector<Position> posiciones = api.list_positions();
    for (const auto& pos : posiciones) {
      std::cout << "Símbolo: " << pos.symbol << " - Cantidad: " << pos.qty << std::endl;
    }
    ```

---

- **`get_position(const std::string& symbol)`**
  - **Descripción:** Recupera detalles de la posición para un activo específico, identificado por su símbolo.
  - **Atributos:**
    - **`symbol`**: El símbolo (ticker) del activo.
  - **Ejemplo:**
    ```cpp
    Position posicion = api.get_position("AAPL");
    std::cout << "Posición para AAPL: " << posicion.qty << " acciones." << std::endl;
    ```

---

- **`get_latest_quotes_stocks(const std::string& symbols, const std::string& currency) const`**
  - **Descripción:** Obtiene las últimas cotizaciones de acciones.
  - **Atributos:**
    - **`symbols`**: Lista de símbolos de acciones, separados por comas.
    - **`currency`**: La moneda (por ejemplo, "USD") en la que se cotizan las acciones.
  - **Ejemplo:**
    ```cpp
    std::vector<Quote> cotizaciones = api.get_latest_quotes_stocks("AAPL,TSLA", "USD");
    for (const auto& cotizacion : cotizaciones) {
      std::cout << "Símbolo: " << cotizacion.symbol << " - Precio: " << cotizacion.price << std::endl;
    }
    ```

---

- **`get_latest_quotes_options(const std::string& symbols) const`**
  - **Descripción:** Obtiene las últimas cotizaciones de opciones.
  - **Atributos:**
    - **`symbols`**: Lista de símbolos de opciones, separados por comas.
  - **Ejemplo:**
    ```cpp
    std::vector<Quote> cotizacionesOpciones = api.get_latest_quotes_options("AAPL_OPT,TSLA_OPT");
    for (const auto& cotizacion : cotizacionesOpciones) {
      std::cout << "Símbolo de opción: " << cotizacion.symbol << " - Precio: " << cotizacion.price << std::endl;
    }
    ```

---

- **`get_latest_trades_stocks(const std::string &symbols, const std::string &currency) const`**
  - **Descripción:** Recupera los datos de las últimas operaciones (trades) para acciones.
  - **Atributos:**
    - **`symbols`**: Lista de símbolos de acciones, separados por comas.
    - **`currency`**: La moneda de negociación (por ejemplo, "USD").
  - **Ejemplo:**
    ```cpp
    std::vector<Trade> operaciones = api.get_latest_trades_stocks("AAPL,TSLA", "USD");
    for (const auto& trade : operaciones) {
      std::cout << "Trade - Símbolo: " << trade.symbol << ", Precio: " << trade.price << std::endl;
    }
    ```

---

- **`get_latest_trades_options(const std::string &symbols) const`**
  - **Descripción:** Recupera los datos de las últimas operaciones (trades) para opciones.
  - **Atributos:**
    - **`symbols`**: Lista de símbolos de opciones, separados por comas.
  - **Ejemplo:**
    ```cpp
    std::vector<Trade> tradesOpciones = api.get_latest_trades_options("AAPL_OPT,TSLA_OPT");
    for (const auto& trade : tradesOpciones) {
      std::cout << "Trade - Símbolo de opción: " << trade.symbol << ", Precio: " << trade.price << std::endl;
    }
    ```

---

- **`change_order_by_client_order_id(const std::string& client_order_id, std::optional<int> qty, std::optional<std::string> time_in_force, std::optional<double> limit_price, std::optional<double> stop_price)`**
  - **Descripción:** Modifica una orden existente identificada por un ID asignado por el cliente.
  - **Atributos:**
    - **`client_order_id`**: El identificador de la orden asignado por el cliente.
    - **`qty`**: *(Opcional)* Nueva cantidad para la orden.
    - **`time_in_force`**: *(Opcional)* Nuevo valor para el tiempo en vigor (por ejemplo, "day", "gtc").
    - **`limit_price`**: *(Opcional)* Nuevo precio límite.
    - **`stop_price`**: *(Opcional)* Nuevo precio de stop.
  - **Ejemplo:**
    ```cpp
    // Modificar una orden existente actualizando la cantidad y el precio límite.
    Order ordenModificada = api.change_order_by_client_order_id("client_order_abc", 20, std::nullopt, 150.75, std::nullopt);
    std::cout << "Orden modificada: " << ordenModificada.toJson() << std::endl;
    ```

---

## Primeros Pasos

Asegúrate de incluir los headers necesarios y enlazar contra **libcurl** y **jsoncpp** al compilar tu aplicación. Por ejemplo:
```bash
g++ -std=c++17 -o miaplicacion main.cpp Tradeapi.cpp -lcurl -ljsoncpp
