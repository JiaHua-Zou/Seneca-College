-- ***********************
-- Name: Jia Hua Zou
-- ID: 114383193
-- Date: Nov11,2020
-- Purpose: Lab 5 DBS311
-- ***********************
SET SERVEROUTPUT ON

-- Question 1 – Write a store procedure that get an integer number and prints
-- Q1 SOLUTION –
CREATE OR REPLACE PROCEDURE findEven(num IN number) AS
BEGIN
    if MOD(num,2) =0 THEN
        DBMS_OUTPUT.PUT_LINE ('The number is even');
    ELSE
        DBMS_OUTPUT.PUT_LINE ('The number is odd');
    END IF;
END;
/
BEGIN
    findEven(10);
END;
/
-- Question 2 – Create a stored procedure named find_employee. This procedure gets an employee number
-- and prints the following employee information:
-- Q2 SOLUTION –
CREATE OR REPLACE PROCEDURE find_employee(employeeNum IN number) AS
employee_count Number;
e_firstName employees.first_name%type;
e_lastName employees.last_name%type;
e_email employees.email%type;
e_phone employees.phone%type;
e_hireDate employees.hire_date%type;
e_jobTitle employees.job_title%type;
BEGIN
    select COUNT(*) INTO employee_count
    FROM employees
    WHERE employee_id = employeeNum;
    IF employee_count = 0 THEN
        DBMS_OUTPUT.put_line('No Result!');
    ELSE
        SELECT last_name, first_name, email, phone, hire_date, job_title
        INTO e_lastName, e_firstName, e_email, e_phone, e_hireDate, e_jobTitle
        FROM employees
        WHERE employee_id = employeeNum;
        DBMS_OUTPUT.put_line('First name: ' || e_firstName);
        DBMS_OUTPUT.put_line('Last name: ' || e_lastName);
        DBMS_OUTPUT.put_line('Email: ' || e_email);
        DBMS_OUTPUT.put_line('Phone: ' || e_phone);
        DBMS_OUTPUT.put_line('Hire date: ' || e_hireDate);
        DBMS_OUTPUT.put_line('Job title: ' || e_jobTitle);
    END IF;
EXCEPTION
WHEN TOO_MANY_ROWS THEN
    DBMS_OUTPUT.PUT_LINE ('TOO MANY ROWS ERRORS!');
WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE ('NO DATA FOUND!');
WHEN OTHERS THEN 
    DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
BEGIN
    find_employee(107);
END;
/
-- Question 3 – Update all the Price list with the matching category id in the products table.
-- Q3 SOLUTION –
CREATE OR REPLACE PROCEDURE update_price_by_cat(categoryUpdate products.category_id%TYPE, amount products.list_price%TYPE) AS
num_product NUMBER;
rows_updated NUMBER;

BEGIN
    SELECT count(*)
    INTO num_product
    FROM products
    WHERE category_id = categoryUpdate;
    IF num_product = 0 THEN
        DBMS_OUTPUT.put_line('No Result!');
    ELSIF amount > 0 THEN
        UPDATE products
        SET list_price = list_price + amount
        WHERE category_id = categoryUpdate;
        rows_updated := sql%rowcount;
        DBMS_OUTPUT.PUT_LINE ('ROWS: ' || rows_updated);
    END IF;
EXCEPTION
WHEN OTHERS
  THEN 
      DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
BEGIN
    update_price_by_cat(1,5);
END;
/
-- Question 4 – Write a store procedure that get an integer number and prints
-- Q4 SOLUTION –
CREATE OR REPLACE PROCEDURE update_price_under_avg AS
avg_price NUMBER;
BEGIN
    SELECT AVG(list_price)
    INTO avg_price
    FROM products;
    IF avg_price <= 1000 THEN
        update products
        Set list_price = list_price *1.02
        WHERE list_price < avg_price;
        DBMS_OUTPUT.PUT_LINE ('Rows Affected: ' || sql%rowcount);
    elsif avg_price > 1000 THEN
        update products
        Set list_price = list_price *1.01
        WHERE list_price < avg_price;
        DBMS_OUTPUT.PUT_LINE ('Rows Affected: ' || sql%rowcount);
    END IF;
EXCEPTION
WHEN TOO_MANY_ROWS THEN
    DBMS_OUTPUT.PUT_LINE ('TOO MANY ROWS ERRORS!');
WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE ('NO DATA FOUND!');
WHEN OTHERS THEN 
    DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
BEGIN
    update_price_under_avg;
END;
/
-- Question 5 – COUNT all products that is fair, expensive and cheap.
-- cheap is (avg_price - min_price) / 2
-- expensive is (max_price - avg_price) / 2
-- fair is between (avg_price - min_price) / 2 and (max_price - avg_price) / 2
-- Q5 SOLUTION –
CREATE OR REPLACE PROCEDURE product_price_report AS
avg_price NUMBER;
max_price NUMBER;
min_price NUMBER;
cheap_count NUMBER;
exp_count NUMBER;
fair_count NUMBER;
BEGIN
    SELECT AVG(list_price), MAX(list_price), MIN(list_price)
    INTO avg_price, max_price, min_price
    FROM products;
    
    -- cheap price
    SELECT COUNT(*)
    INTO cheap_count
    FROM products
    WHERE list_price < ((avg_price - min_price) /2);
    
    -- expensive price
     SELECT COUNT(*)
     INTO exp_count
    FROM products
    WHERE list_price > ((max_price - avg_price) /2);

    --fair price
    SELECT COUNT(*)
    INTO fair_count
    FROM products
    WHERE list_price > ((avg_price - min_price) /2) AND list_price < ((max_price - avg_price) - 2);
    
    DBMS_OUTPUT.PUT_LINE ('Cheap: ' || cheap_count);
    DBMS_OUTPUT.PUT_LINE ('Fair: ' || fair_count);
    DBMS_OUTPUT.PUT_LINE ('Expensive: ' || exp_count);
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE ('TOO MANY ROWS ERRORS!');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE ('NO DATA FOUND!');
    WHEN OTHERS THEN 
        DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
BEGIN
    product_price_report;
END;
/