-- ***********************
-- Name: Jia Hua, Zou
-- ID: 114383193
-- Date:  Oct 1,2020.
-- Purpose: Lab 02 DBS311
-- ***********************

-- Q1 SOLUTION --
SELECT 
    job_title ,
    count(job_title)AS "EMPLOYEES"
FROM 
    employees
GROUP BY 
    job_title
ORDER BY 
    count(job_title);

-- Q2 Solution –
SELECT 
    max(credit_limit) AS "HIGH", 
    min(credit_limit) AS "LOW", 
    round(avg(credit_limit),2) AS "AVERAGE" , 
    max(credit_limit) - min(credit_limit) AS "HIGH Low Difference"
FROM 
    customers;

-- Q3 Solution –
SELECT 
    order_id, 
    sum(quantity) AS "TOTAL_ITEMS", 
    sum(unit_price * quantity) AS "TOTAL_AMOUNT"
FROM 
    order_items
HAVING 
    sum(unit_price * quantity) > 1000000
GROUP BY 
    order_id
ORDER BY 
    3 desc;

-- Q4 Solution –
SELECT 
    w.warehouse_id,
    w.warehouse_name, 
    sum(quantity)
FROM
    inventories i, 
    warehouses w
WHERE 
    w.warehouse_id = i.warehouse_id
GROUP BY 
    w.warehouse_name, 
    w.warehouse_id
ORDER BY 
    w.warehouse_id;

-- Q5 Solution –
SELECT 
    c.customer_id, 
    c.name, 
    count(o.order_id) AS "total number OF orders"
FROM 
    customers c left join orders o ON c.customer_id = o.customer_id
WHERE
    c.name LIKE 'O%e%'
    OR c.name LIKE '%t'
GROUP BY
    c.customer_id, 
    c.name
ORDER BY
    3 DESC;

-- Q6 Solution –
SELECT 
    p.category_id, 
    sum(oi.quantity * p.list_price) AS "TOTAL_AMOUNT", 
    round(avg(oi.quantity * p.list_price),2) AS "AVERAGE_AMOUNT"
FROM
    order_items oi, 
    products p
WHERE
    oi.product_id = p.product_id
GROUP BY
    p.category_id;