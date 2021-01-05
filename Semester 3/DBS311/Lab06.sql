-- ***********************
-- Name: Jia Hua Zou
-- ID: 114383193
-- Date: Nov 16,2020.
-- Purpose: Lab 6 DBS311
-- ***********************
SET SERVEROUTPUT ON

-- Question 1 – Write a store procedure that gets an integer number n and calculates and displays its factorial
-- Q1 SOLUTION –
CREATE OR REPLACE PROCEDURE factorial(num NUMBER) AS
fac number :=1;
newnum number:= num;
BEGIN
    IF(newnum < 0) THEN
        dbms_output.put_line('ERROR! Number is 0!');
    ELSIF (newnum =0) THEN
        dbms_output.put_line('Factorial: 1');
    ELSE
       WHILE newnum > 0 LOOP
        fac := fac * newnum;
        newnum := newnum -1;
        END LOOP;
        dbms_output.put_line('Factorial: ' || fac);
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
   factorial(5);
END;
/
-- Question 2 – Selected employee start with 10k salary. Calculate the total salary total years working. Each year is increase by 5%.
-- Q2 SOLUTION –
CREATE OR REPLACE PROCEDURE calculate_salary(employ_id employees.employee_id%TYPE) AS
hire_date employees.hire_date%TYPE;
first_name employees.first_name%TYPE;
last_name employees.last_name%TYPE;
salary NUMBER;
yr_work NUMBER;
BEGIN
    salary := 10000;
    SELECT first_name, last_name, hire_date
    INTO first_name, last_name, hire_date
    FROM employees
    WHERE employee_id = employ_id;
    DBMS_OUTPUT.PUT_LINE ('First Name: '||first_name);
    DBMS_OUTPUT.PUT_LINE ('Last Name: '||last_name);
    SELECT (EXTRACT(YEAR
                    FROM sysdate) -
            EXTRACT(YEAR
                    FROM hire_date))
    INTO yr_work
    FROM dual;
    
    FOR i IN 1..yr_work LOOP salary := salary * 1.05;
    END LOOP;
     DBMS_OUTPUT.PUT_LINE ('Salary: $'|| to_char(salary, '$999,999.99'));
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
   calculate_salary(107);
END;
/
-- Question 3 – Display warehouse id, name, city and state. If state is null diplay "no state". warehouse ID is 1-9. Use loop no cursors.
-- Q3 SOLUTION –
CREATE OR REPLACE PROCEDURE warehouses_report AS
warehouse_id warehouses.warehouse_id%TYPE;
warehouse_name warehouses.warehouse_name%TYPE;
city locations.city%TYPE;
state locations.state%TYPE;
BEGIN
    FOR i IN 1..9 LOOP
        SELECT warehouse_id, warehouse_name, city, nvl(state, 'no state')
        INTO warehouse_id, warehouse_name, city, state
        FROM warehouses w
        LEFT JOIN locations l
        ON l.location_id = w.location_id
        WHERE warehouse_id = i;
        
        DBMS_OUTPUT.PUT_LINE('Warehouse ID: ' || warehouse_id);
        DBMS_OUTPUT.PUT_LINE ('Warehouse name: ' || warehouse_name);
        DBMS_OUTPUT.PUT_LINE ('City: ' || city);
        DBMS_OUTPUT.PUT_LINE ('State: ' || state);
        DBMS_OUTPUT.PUT_LINE ('');
    END LOOP;
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE ('TOO MANY ROWS ERRORS!');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE ('NO DATA FOUND!');
    WHEN OTHERS THEN 
        DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
BEGIN warehouses_report;
END;
/