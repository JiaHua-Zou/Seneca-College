SET SERVEROUTPUT ON
-- reset the new orders and order_items table-
DROP TABLE new_orders;
DROP TABLE new_order_items;
CREATE TABLE new_orders AS SELECT * FROM orders;
CREATE TABLE new_order_items AS SELECT * FROM order_items;
/
-- find_customer –
CREATE OR REPLACE PROCEDURE find_customer(id IN NUMBER, found OUT NUMBER) AS
BEGIN
    SELECT COUNT(*)
    INTO found
    FROM customers
    WHERE customer_id = id;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        found := 0;
END;
/
 --find_product -
CREATE OR REPLACE PROCEDURE find_product(id IN NUMBER, price OUT products.list_price%TYPE) AS
BEGIN
    SELECT list_price
    INTO price
    FROM products
    WHERE product_id = id;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        price := 0;
END;
/
--new_order_item -
CREATE OR REPLACE PROCEDURE add_order_item(orderId IN new_order_items.order_id%type,
                                           itemId IN new_order_items.item_id%type,
                                           productId IN new_order_items.product_id%type,
                                           quantity IN new_order_items.quantity%type,
                                           price IN new_order_items.unit_price%type) AS
BEGIN
    INSERT INTO new_order_items
        (order_id, item_id, product_id, quantity, unit_price)
    VALUES
        (orderId, itemId, productId, quantity, price);
END;
/
-- add_order -
CREATE OR REPLACE PROCEDURE add_order(customerId IN NUMBER,  new_order_id OUT NUMBER) AS
BEGIN
    SELECT MAX(order_id)
    INTO new_order_id
    FROM new_orders;
    
    new_order_id := new_order_id +1;
    
    INSERT INTO new_orders
        (order_id, customer_id, status, salesman_id, order_date)
    VALUES
        (new_order_id, customerId, 'Shipped', 56, SYSDATE);
END;
/