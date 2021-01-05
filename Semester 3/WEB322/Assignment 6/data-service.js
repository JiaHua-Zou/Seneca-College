/*********************************************************************************
* WEB322 – Assignment 05
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Dec 7,2020
*
* 
*
********************************************************************************/
const Sequelize = require('sequelize');
//Parameter database, user, password
var sequelize = new Sequelize('dejfl9vjv9stv5', 'khzkwejbuqcqhn', 'a08102f24ea15b69fc29bb55cb90fe764cca1723a36eeafd54fc0bd610f7dcf4', {
    host:'ec2-34-231-56-78.compute-1.amazonaws.com',
    dialect:'postgres',
    port:5432,
    dialectOptions:{
        ssl: {
            require: true,
            rejectUnauthorized: false }
    } 
});

var Employee = sequelize.define('Employee', {
    employeeNum: {
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    firstName:Sequelize.STRING,
    lastName:Sequelize.STRING,
    email:Sequelize.STRING,
    SSN:Sequelize.STRING,
    addressStreet:Sequelize.STRING,
    addressCity:Sequelize.STRING,
    addressState:Sequelize.STRING,
    addressPostal:Sequelize.STRING,
    maritalStatus:Sequelize.STRING,
    isManager:Sequelize.BOOLEAN,
    employeeManagerNum:Sequelize.INTEGER,
    status:Sequelize.STRING,
    department:Sequelize.INTEGER,
    hireDate:Sequelize.STRING
});

var Department = sequelize.define('Department', {
    departmentId:{
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    departmentName:Sequelize.STRING
});


module.exports.initialize = function(){
    return new Promise((resolve,reject) => {
        sequelize.sync()
        .then(() => {
            resolve("Connected!");
        })
        .catch(() =>{
            reject("unable to sync the database"); 
        });     
    });
};

module.exports.getAllEmployee = function(){
    return new Promise((resolve,reject) => {
        Employee.findAll()
        .then((data) =>{ 
            data = data.map(value => value.dataValues);
            resolve(data); })
        .catch(() =>{reject("no results returned"); });     
    });
};

module.exports.getManagers = function(){
    return new Promise((resolve,reject) => {
        reject();
    });
};

module.exports.getDepartments = function(){
    return new Promise((resolve, reject) => {
        Department.findAll()
        .then((data)=> {
            data = data.map(value => value.dataValues)
            resolve(data)})
        .catch(()=>reject("no results returned"))
    });
};  

module.exports.addEmployee =function(employeeData){
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (var i in employeeData) {
        if(employeeData[i] == ""){
            employeeData[i]= null;
        }
    }
    return new Promise((resolve, reject)=>{
        Employee.create(employeeData)
        .then(() =>{resolve()})
        .catch(() =>{reject("unable to create employee")});
    });
}

module.exports.getEmployeesByStatus = function(status){
    return new Promise((resolve,reject) =>{
        Employee.findAll({
            where: {
                status: status
            }
        })
        .then((data) =>{ 
            data = data.map(value => value.dataValues)
            resolve(data)
        })
        .catch(() =>{reject("no results returned"); });
    });
}

module.exports.getEmployeesByDepartment = function(department){
    return new Promise((resolve,reject) =>{
        Employee.findAll({
            where: {
                department: department
            }
        })
        .then((data) =>{ 
            data = data.map(value => value.dataValues)
            resolve(data)
        })
        .catch(() =>{reject("no results returned"); });
    });
}

module.exports.getEmployeesByManager = function(manager){
    return new Promise((resolve,reject) =>{
        Employee.findAll({
            where: {
                employeeManagerNum: manager
            }
        })
        .then((data) =>{ 
            data = data.map(value => value.dataValues)
            resolve(data)
        })
        .catch(() =>{reject("no results returned"); });
    });
}

module.exports.getEmployeeByNum = function(num){
    return new Promise((resolve, reject) => {
        Employee.findAll({
            where: {
                employeeNum: num
            }
        })
        .then((data) =>{ 
            data = data.map(value => value.dataValues)
            resolve(data[0])
        })
        .catch(() =>{reject("no results returned"); });
    });
}

//another way to declare the functions using arrow notation
module.exports.updateEmployee= (employeeData) =>{
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (var i in employeeData) {
        //using (prop in employeeData) gives error when deleting the manager's num.
        if(employeeData[i] == "")
            employeeData[i] = null;
    }
    return new Promise((resolve, reject) => {
        Employee.update(employeeData, {
            where: {
                employeeNum: employeeData.employeeNum
            }
        })
        .then(()=>{resolve()})
        .catch(()=>{reject("unable to update employee");})
    });
}

module.exports.addDepartment = (departmentData) =>{
    return new Promise((resolve, reject) => {
        for(var i in departmentData){
            if(departmentData[i] ==""){
                departmentData[i]=null;
            }
        }
        Department.create(departmentData)
        .then(()=>resolve())
        .catch(()=>reject("unable to create employee"))
    });
}

module.exports.updateDepartment =(departmentData) =>{
    return new Promise((resolve,reject) =>{
        for (var i in departmentData) {
            if(departmentData[i] == ""){
                departmentData[i] = null;
            }
        }
        Department.update(departmentData, { where:{ departmentId: departmentData.departmentId} })
        .then(() =>{resolve()})
        .catch(() =>{ reject({message: "unable to update department"})
        })
    });
}

module.exports.getDepartmentById =(id) =>{
    return new Promise((resolve, reject) =>{
        Department.findAll({
            where: {
                departmentId: id
            }
        })
        .then((data)=>{
            data = data.map(value => value.dataValues)
            resolve(data)
        })
        .catch(() => {
            reject({message: "no results returned"});
        })
    });
}

module.exports.deleteEmployeeByNum =(empNum) =>{
    return new Promise((resolve,reject) => {
        Employee.destroy({
            where: {
                employeeNum: empNum
            }
        })
        .then(() =>{resolve()})
        .catch(()=> {
            reject({message: "Unable to destroy employee"})
        })
    });
}

module.exports.deletedepartmentById =(departNum) =>{
    return new Promise((resolve,reject) => {
        Department.destroy({
            where: {
                departmentId: departNum
            }
        })
        .then(() =>{resolve()})
        .catch(()=> {
            reject({message: "Unable to destroy department"})
        })
    });
}