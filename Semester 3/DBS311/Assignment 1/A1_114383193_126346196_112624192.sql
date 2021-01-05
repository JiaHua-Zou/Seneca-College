-- ***********************
-- Names: 
-- Jia Hua Zou, 114383193
-- Dongun Cho 126346196 
-- Yuri Falcao 112624192
--
-- Date: Oct 30,2020.
-- Purpose: Assignment 1 - DBS311
-- ***********************

-- Question 1 ? Display employees in Sept order by most recent. Geting employee id, full name, jobtitle and hire date
-- Q1 SOLUTION --
rpad(first_name || ', ' || last_name, 25, ' '),
job_title AS "job",
to_char(last_day(hire_date), '[fmMonth ddTH "of" yyyy]') AS "hiredate" 
FROM employees 
WHERE EXTRACT(MONTH FROM hire_date) 
IN (9)
ORDER BY hire_date DESC;
SELECT employee_id AS "Employee Number",
(last_name||', ' || first_name) AS "Full Name",
job_title AS "Job Title",
to_char(hire_date, '[fmMonth ddth "of" yyyy]') AS "Start Date"
FROM employees
WHERE extract(MONTH FROM hire_date) IN (9)
ORDER BY hire_date DESC;


-- Question 2 ? Display total sale per sales person, Order with no salesman id, consider id as 0. Get employee id and total sale
-- Q2 SOLUTION --
SELECT
    NVL(o.salesman_id, 0) AS "Employee Number",
    TO_CHAR(SUM(oi.unit_price * oi.quantity), '$999,999,999.90') AS "Total Sale"
FROM
    order_items oi,
    orders o
WHERE
    o.order_id = oi.order_id
GROUP BY
    o.salesman_id
ORDER BY
    NVL(o.salesman_id, 0);

-- Question 3 ? Display customers that the value of their customer id is value 35-45. Get customer id, name and total number of orders. Order by total orders
-- Q3 SOLUTION --
SELECT 
    c.customer_id AS "Customer ID",
    c.name,
    COUNT(o.order_id) AS "Total Orders"
FROM
    customers c
LEFT JOIN
    orders o
    ON o.customer_id = c.customer_id
WHERE
    c.customer_id BETWEEN 35 AND 45
GROUP BY
    c.customer_id,
    c.name
ORDER BY
    COUNT(o.order_id);

-- Question 4 ? . Display customer ID, customer name, and the order ID and the order date of all.orders for customer whose ID is 44.
-- Q4 SOLUTION --
SELECT
    c.customer_id AS "Customer Id",
    c.name AS "Name",
    o.order_id AS "Order Id",
    o.order_date AS "Order Date",
    SUM(oi.quantity) AS "Total Items",
    TO_CHAR(SUM(oi.unit_price * oi.quantity), '$999,999,999.99') AS "Total Amount"
FROM
    customers c,
    orders o,
    order_items oi
WHERE
    c.customer_id = o.customer_id and
    o.order_id = oi.order_id and
    c.customer_id = 44
GROUP BY
    c.customer_id,
    c.name,
    o.order_id,
    o.order_date
ORDER BY
    SUM(oi.unit_price * oi.quantity) desc;

-- Question 5 ? Display customer Id, name, total number of orders, the total number of items ordered, and the total order amount for customers who have more than 30 orders.
-- Sort the result based on the total number of orders.
-- Q5 SOLUTION --
SELECT
    c.customer_id AS "Customer Id",
    c.name AS "Name",
    COUNT(o.order_id) AS "Total Number of Orders",
    SUM(oi.quantity) AS "Total Items",
    TO_CHAR(SUM(oi.unit_price * oi.quantity), '$999,999,999.99') AS "Total Amount"
FROM
    customers c,
    orders o,
    order_items oi
WHERE
    c.customer_id = o.customer_id AND
    o.order_id = oi.order_id
HAVING
    COUNT(o.order_id) > 30
GROUP BY
    c.customer_id,
    c.name
ORDER BY
    COUNT(o.order_id);

-- Question 6 ? Display Warehouse Id, warehouse name, product category Id, product category name, and the lowest product standard cost for this combination
-- Q6 SOLUTION --
SELECT
    w.warehouse_id AS "Warehouse ID",
    w.warehouse_name AS "Warehouse Name",
    pc.category_id AS "Category ID",
    pc.category_name AS "Category Name",
    TO_CHAR(MIN(p.standard_cost), '$999,999.99') AS "Lowest Cost"
FROM
    warehouses w,
    product_categories pc,
    inventories i,
    products p
WHERE
    w.warehouse_id = i.warehouse_id AND
    i.product_id = p.product_id AND
    p.category_id = pc.category_id
HAVING
    MIN(p.standard_cost) < 200 OR
    MIN(p.standard_cost) > 500
GROUP BY
    w.warehouse_id,
    w.warehouse_name,
    pc.category_id,
    pc.category_name
ORDER BY
    w.warehouse_id,
    w.warehouse_name,
    pc.category_id,
    pc.category_name;
-- *************************************************************** NOT DONE
-- Question 7 ? Display the total number of orders per month. Sort the result from January to December.
-- Q7 SOLUTION --
SELECT
    TO_CHAR(TO_DATE(the_month, 'MM'), 'Month') AS "Month",
    counts AS "Number of Orders"
FROM
    (SELECT
        EXTRACT(MONTH 
                    FROM
                        order_date) AS the_month,
        COUNT(*) AS counts 
    FROM
        orders 
    GROUP BY
        EXTRACT(MONTH 
                    FROM
                        order_date)
    )
ORDER BY
    the_month
;

-- Question 8 ? Display product Id, product name for products that their list price is more than any highest product standard cost per warehouse outside Americas regions
-- Q8 SOLUTION --
SELECT
    product_id AS "Product ID",
    product_name AS "Product Name",
    TO_CHAR(list_price, '$999,999.99') AS "Price"
FROM
    products
WHERE
    list_price > Any (SELECT
                        MAX(p.standard_cost)
                    FROM
                           regions r --region_id
                        LEFT JOIN
                            countries c -- region_id, country_id
                            ON r.region_id = c.region_id
                        LEFT JOIN
                            locations l -- country_id, location_id
                            ON c.country_id = l.country_id
                        LEFT JOIN
                            warehouses w --location_id, warehouse_id
                            ON l.location_id = w.location_id
                        LEFT JOIN
                            inventories i --warehouse_id, product_id
                            ON w.warehouse_id = i.warehouse_id
                        LEFT JOIN
                            products p --product_id
                            ON i.product_id = p.product_id
                    WHERE
                        r.region_name NOT LIKE 'Americas'
                    GROUP BY
                        w.warehouse_id
                    )
ORDER BY
    list_price DESC;

-- Question 9 ? Write a SQL statement to display the most expensive and the cheapest product (list price). Display product ID, product name, and the list price.
-- Q9 SOLUTION --
SELECT
    product_id AS "Product ID",
    product_name AS "Product Name",
    TO_CHAR(list_price, '$999,999.99') AS "Price"
FROM
    products
WHERE
    list_price = any(SELECT
                        MAX(list_price)
                    FROM
                        products)
    OR
    list_price = any(SELECT
                        MIN(list_price)
                    FROM
                        products);
--********************************************************* Not DONE
-- Question 10 ? Write a SQL query to display the number of customers with total order amount over
-- the average amount of all orders, the number of customers with total order amount
-- under the average amount of all orders, number of customers with no orders, and
-- the total number of customers.
-- Q10 SOLUTION --
SELECT 'Number of customers with total purchase amount over average: ' 
|| COUNT(*) AS "Customer Report" 
FROM (
   SELECT c.customer_id,
   SUM(oi.quantity*oi.unit_price) AS total_amount 
   FROM customers c 
   INNER JOIN orders o 
   ON c.customer_id = o.customer_id 
   INNER JOIN order_items oi 
   ON oi.order_id = o.order_id 
   GROUP BY c.customer_id)
WHERE total_amount > (
   SELECT AVG(quantity*unit_price) 
   FROM order_items) 
UNION ALL
SELECT 'Number of customers with total purchase amount below average: ' 
|| COUNT(*) 
FROM (
   SELECT c.customer_id,
   SUM(oi.quantity*oi.unit_price) AS total_amount 
   FROM customers c 
   INNER JOIN orders o 
   ON c.customer_id = o.customer_id 
   INNER JOIN order_items oi 
   ON oi.order_id = o.order_id 
   GROUP BY c.customer_id )
WHERE total_amount < (
   SELECT AVG(quantity*unit_price) 
   FROM order_items) 
UNION ALL
SELECT 'Number of customers with no orders: ' 
|| COUNT(*) 
FROM (
   SELECT customer_id 
   FROM customers minus 
   SELECT customer_id 
   FROM orders)
UNION ALL
SELECT 'Total number of customers: ' 
|| COUNT(*) 
FROM (
   SELECT customer_id 
   FROM customers 
   UNION
   SELECT customer_id 
   FROM orders);  