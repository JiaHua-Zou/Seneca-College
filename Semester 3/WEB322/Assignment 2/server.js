/*********************************************************************************
* WEB322 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Oct 5,2020
*
* Online (Heroku) Link: https://calm-hollows-52387.herokuapp.com/
*
********************************************************************************/ 
var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();
var path = require("path");
var data = require("./data-service");
// Step 3  adding additional roues *********************************
// call this function after the http server starts listening for requests
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
  }

  //use for css.
app.use(express.static(__dirname, +'/public'));
  
// setup another route to listen on /about
app.get("/", function(req,res){
    res.sendFile(path.join(__dirname,"/views/home.html"));
  });

  app.get("/about", function(req,res){
    res.sendFile(path.join(__dirname,"/views/about.html"));
  });

app.get("/employees", function(req,res){
  data.getAllEmployee().then((data) =>{
    res.json(data);
  });
});

app.get("/managers", function(req,res){
  data.getManagers().then((data) =>{
    res.json(data);
  });
});

app.get("/departments", function(req,res){
  data.getDepartments().then((data) =>{
    res.json(data);
  });
});

//custom 404 error.
  app.use((req, res) => {
    res.status(404).send("Page Not Found");
  });

// setup http server to listen on HTTP_PORT
data.initialize().then(function() {
  app.listen(HTTP_PORT, onHttpStart);
})
.catch(function(err){
  console.log("Unable to start" + err);
})