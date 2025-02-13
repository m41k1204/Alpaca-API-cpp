# Documentación de TradeAPI

Este documento ofrece una descripción general de las funciones de TradeAPI, detallando cada uno de sus atributos (parámetros) y proporcionando ejemplos de uso en bloques de código.

- **`submit_order_stock(const std::string& symbol, const int qty, const std::string& side, const std::string& type, const std::string& time_in_force, const double limit_price, const double stop_price, const std::string& client_order_id) const`**
  - **Descripción:** Envía una orden de acciones al API. Construye el payload en formato JSON con los detalles de la orden y realiza una solicitud POST al endpoint `/orders`. Se utiliza para enviar órdenes de compra o venta de acciones.
  - **Atributos:**
    - **`symbol`**: Símbolo de la acción (ticker) a operar.
    - **`qty`**: Cantidad de acciones a comprar o vender.
    - **`side`**: Lado de la orden ("buy" o "sell").
    - **`type`**: Tipo de orden (por ejemplo, "market", "limit", "stop", "stop_limit").
    - **`time_in_force`**: Duración de la orden (por ejemplo, "day", "gtc").
    - **`limit_price`**: Precio límite, requerido si el tipo es "limit".
    - **`stop_price`**: Precio de stop, requerido si el tipo es "stop" o "stop_limit".
    - **`client_order_id`**: Identificador de la orden asignado por el cliente.
  - **Ejemplo de uso:**
    ```cpp
    // Enviar una orden de mercado para comprar 100 acciones de AAPL.
    Order ordenAccion = api.submit_order_stock("AAPL", 100, "buy", "market", "day", 0.0, 0.0, "orden_stock_001");
    std::cout << "Orden de acciones enviada, estado: " << ordenAccion.status << std::endl;

    // Enviar una orden limit para vender 50 acciones de MSFT con un precio límite de 300.50.
    Order ordenLimitAccion = api.submit_order_stock("MSFT", 50, "sell", "limit", "day", 300.50, 0.0, "orden_stock_002");
    std::cout << "Orden limit enviada, estado: " << ordenLimitAccion.status << std::endl;
    ```

---

- **`submit_order_option(const std::string& symbol, const int qty, const std::string& side, const std::string& type, const std::string& time_in_force, const double limit_price, const double stop_price, const std::string& client_order_id) const`**
  - **Descripción:** Envía una orden de opciones al API. Similar a la función de acciones, construye un payload JSON con los detalles de la orden y realiza una solicitud POST al endpoint `/orders`. Se utiliza para enviar órdenes de compra o venta de opciones.
  - **Atributos:**
    - **`symbol`**: Símbolo de la opción a operar.
    - **`qty`**: Cantidad de contratos a comprar o vender.
    - **`side`**: Lado de la orden ("buy" o "sell").
    - **`type`**: Tipo de orden (por ejemplo, "market", "limit", "stop", "stop_limit").
    - **`time_in_force`**: Duración de la orden (por ejemplo, "day", "gtc").
    - **`limit_price`**: Precio límite, requerido si el tipo es "limit".
    - **`stop_price`**: Precio de stop, requerido si el tipo es "stop" o "stop_limit".
    - **`client_order_id`**: Identificador de la orden asignado por el cliente.
  - **Ejemplo de uso:**
    ```cpp
    // Enviar una orden de mercado para comprar 10 contratos de opción de AAPL.
    Order ordenOpcion = api.submit_order_option("AAPL_OPT", 10, "buy", "market", "day", 0.0, 0.0, "orden_opt_001");
    std::cout << "Orden de opciones enviada, estado: " << ordenOpcion.status << std::endl;

    // Enviar una orden limit para vender 5 contratos de opción de TSLA con un precio límite de 15.75.
    Order ordenLimitOpcion = api.submit_order_option("TSLA_OPT", 5, "sell", "limit", "day", 15.75, 0.0, "orden_opt_002");
    std::cout << "Orden limit de opciones enviada, estado: " << ordenLimitOpcion.status << std::endl;
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


