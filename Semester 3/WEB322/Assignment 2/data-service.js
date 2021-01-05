/*********************************************************************************
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Oct 5,2020
*
* Online (Heroku) Link: 
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