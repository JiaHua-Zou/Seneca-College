-- ***********************
-- Name: Jia Hua Zou
-- ID: 114383193
-- Date: Oct 25,2020.
-- Purpose: Lab 04 DBS311
-- ***********************

-- Q1 SOLUTION --
SELECT
    city
FROM
    locations
MINUS
SELECT
    l.city
FROM
    locations l, warehouses w
WHERE
    l.location_id = w.location_ID;

-- Q2 SOLUTION --
SELECT
    pc.category_id, pc.category_name, count(p.product_id) as "COUNT(*)"
FROM
    product_categories pc
INNER JOIN
    products p
    ON pc.category_id = p.category_id
WHERE
    p.category_id =5
GROUP BY
   pc.category_id, pc.category_name 
UNION ALL
SELECT
    pc.category_id, pc.category_name, count(p.product_id)
FROM
    product_categories pc
INNER JOIN
    products p
    ON pc.category_id = p.category_id
WHERE
    p.category_id =1
GROUP BY
   pc.category_id, pc.category_name
UNION ALL
SELECT
    pc.category_id, pc.category_name, count(p.product_id)
FROM
    product_categories pc
INNER JOIN
    products p
    ON
        pc.category_id = p.category_id
WHERE
    p.category_id =2
GROUP BY
   pc.category_id,
   pc.category_name;
   
-- Q3 SOLUTION --
SELECT
    product_id
FROM
    products
INTERSECT
SELECT
    product_id
FROM
    inventories
WHERE
    quantity < 5;
    
-- Q4 SOLUTION --
SELECT
    w.warehouse_name, l.state
FROM 
    warehouses w
LEFT JOIN locations l
    ON w.location_id =l.location_id
UNION 
SELECT
    w.warehouse_name, l.state
FROM 
    warehouses w
RIGHT JOIN locations l
    ON w.location_id =l.location_id;