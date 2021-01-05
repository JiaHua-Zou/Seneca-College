/*********************************************************************************
* WEB322 – Assignment 03
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Oct 20,2020
*
* 
*
********************************************************************************/
// fs can read and write to files.
const fs=require("fs");

var departments =[];
var employees =[];

module.exports.initialize = function(){
    return new Promise((resolve,reject) => {
        fs.readFile("./data/employees.json", (err, data) =>{
            if(err)
                reject("Unable to read file");
            employees= JSON.parse(data);    
            
            fs.readFile("./data/departments.json",(err,data) => {
                if(err)
                    reject("Unable to read file");
                departments =JSON.parse(data);
            });
            resolve(departments);
        });
    });
};

module.exports.getAllEmployee = function(){
    return new Promise((resolve,reject) => {
        if(employees.length == 0)
            reject("no results returned");
        resolve(employees);
    });
};

module.exports.getManagers = function(){
    return new Promise((resolve,reject) => {
        var filterManager = [];
        for (let i = 0; i < employees.length; i++) {
            if(employees[i].isManager == true)
                filterManager.push(employees[i]);
        }
        if(employees.length == 0)
            reject("no results returned");
        resolve(filterManager);
    });
};

module.exports.getDepartments = function(){
    return new Promise ((resolve, reject) => {
        if(departments.length ==0)
            reject("no results returned");
        resolve(departments);
    });
};

module.exports.addEmployee =function(employeeData){
    return new Promise((resolve, reject)=>{
        if(employeeData.length ==0){
            reject("no results");
        }
        else{
            if (employeeData.isManager != true)
                employeeData.isManager = false;
                employeeData.employeeNum=employees.length+1;
                employees.push(employeeData);
        }
        resolve(employees);
    });
}

module.exports.getEmployeesByStatus = function(status){
    return new Promise((resolve,reject) =>{
        var newEmployees = [];
        for (let i = 0; i < employees.length; i++) {
            if(status == employees[i].status)
                newEmployees.push(employees[i]);
        }
        if(newEmployees.length == 0)
            reject("no results returned");

        resolve(newEmployees);
    });
}

module.exports.getEmployeesByDepartment = function(department){
    return new Promise((resolve,reject) =>{
        var newEmployees = [];
        for (let i = 0; i < employees.length; i++) {
           if(department == employees[i].department)
                newEmployees.push(employees[i]);
        }
        if(newEmployees.length == 0)
            reject("no results returned");

        resolve(newEmployees);
    });
}

module.exports.getEmployeesByManager = function(manager){
    return new Promise((resolve,reject) =>{
        var newEmployees = [];
        for (let i = 0; i < employees.length; i++) {
           if(manager == employees[i].employeeManagerNum)
                newEmployees.push(employees[i]);
        }
        if(newEmployees.length == 0)
            reject("no results returned");

        resolve(newEmployees);
    });
}

module.exports.getEmployeeByNum = function(num){
    return new Promise((resolve,reject) =>{
        var newEmployees = [];
        for (let i = 0; i < employees.length; i++) {
           if(num == employees[i].employeeNum)
                newEmployees.push(employees[i]);
        }
        if(newEmployees.length == 0)
            reject("no results returned");

        resolve(newEmployees);
    });
}