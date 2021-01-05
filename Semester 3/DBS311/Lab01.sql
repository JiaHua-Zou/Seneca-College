-- ***********************
-- Name: Jia Hua, Zou
-- ID: 114383193
-- Date: sept 23, 2020.
-- Purpose: Lab 01 DBS311
-- ***********************

-- Q1 SOLUTION --
SELECT to_char(sysdate+1, 'Month" "dd" of year "yyyy') AS "Tomorrow"
FROM dual;

-- Q2 SOLUTION --
SELECT product_id , product_name, list_price, round(list_price*1.02,0 )as "New Price", round(list_price*1.02,0 )-list_price as "Price Differece" 
FROM products
WHERE category_id = 2 OR category_id =3 OR category_id =5
ORDER BY category_id, product_id;

-- Q3 SOLUTION --
SELECT last_name || ', ' || first_name || ' is ' || job_title AS "Employee Info"
FROM employees
WHERE manager_id =2
ORDER BY employee_id;

-- Q4 SOLUTION --
SELECT last_name ,hire_date, TRUNC((sysdate - hire_date)/365,0) AS "Years Worked"
FROM employees
where hire_date < to_date('1-OCT-16','dd-mm-yy')
ORDER BY hire_date;

-- Q5 SOLUTION --
SELECT last_name , hire_date, TO_CHAR(next_day(hire_date+366,'Tuesday'), 'Day ", "month "the "ddspth "of year " YYYY') AS "Review Date"
FROM employees
WHERE hire_date > to_date('1-JAN-16','dd-mm-yy')
ORDER BY next_day(hire_date+366,'Tuesday');

-- Q6 SOLUTION --
SELECT warehouses.warehouse_id, warehouses.warehouse_name, locations.city, nvl(state, 'Unknown') AS State
FROM warehouses, locations
WHERE warehouses.location_id = locations.location_id
ORDER BY warehouse_id;