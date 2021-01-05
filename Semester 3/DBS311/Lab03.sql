-- ***********************
-- Name: Jia Hua, Zou
-- ID: 114383193
-- Date: Oct 10,2020.
-- Purpose: Lab 03 DBS311
-- ***********************

-- Q1 SOULTION --
SELECT 
    last_name, hire_date
FROM
    employees
WHERE
    hire_date > to_date('01-04-2016', 'dd-mm-yyyy') AND
    hire_date < (SELECT hire_date
                FROM employees
                WHERE employee_id =107)
ORDER BY hire_date, employee_id;

-- Q2 SOULTION --
SELECT name, credit_limit
FROM customers
WHERE credit_limit <= (SELECT min(credit_limit)
                        FROM customers)
ORDER BY customer_id;

-- Q3 SOULTION --
SELECT
    category_id, product_id, product_name, list_price
FROM
    products

WHERE list_price IN (SELECT max(list_price)
                            FROM products
                            GROUP BY category_id)
ORDER BY 
    category_id, product_id;
    
-- Q4 SOULTION --
SELECT
    p.category_id, pc.category_name
FROM
    products p, product_categories pc

WHERE 
    p.category_id =pc.category_id AND
    p.list_price IN (SELECT max(list_price)
                    FROM products);
                    
-- Q5 SOULTION --
SELECT
    product_name, list_price
FROM
    products
WHERE
    category_id = 1 AND
    list_price < any(SELECT min(list_price)
                    FROM products
                    GROUP BY category_id)
ORDER BY list_price desc, product_id;

-- Q6 SOULTION --
SELECT
    max(list_price)
FROM
    products
WHERE
    category_id in (select category_id
                    FROM products
                    WHERE list_price in ( SELECT min(list_price)
                                        FROM products)
                    );