/*********************************************************************************
* WEB322 – Assignment 03
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Oct 20,2020
*
* Online (Heroku) Link: https://calm-hollows-52387.herokuapp.com/
*
********************************************************************************/ 
var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();
var path = require("path");
var data = require("./data-service");
var multer = require("multer");
var bodyParser = require("body-parser");
const exphbs = require('express-handlebars');
const fs = require("fs");

// Step 3  adding additional roues *********************************
// call this function after the http server starts listening for requests
function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}

//use for css.
app.use(express.static(__dirname, +'/public'));
//setup the static folder that static resources can load from
app.use(express.static("./public/"));
//set the middleware for urlencoded form data.
app.use(bodyParser.urlencoded({ extended: true }));

const storage = multer.diskStorage({
  destination: "./public/images/add", //Where to save the file
  filename: function (req, file, cb) {
    // we write the filename as the current date down to the millisecond
    // in a large web service this would possibly cause a problem if two people
    // uploaded an image at the exact same time. A better way would be to use GUID's for filenames.
    // this is a simple example.
    cb(null, Date.now() + path.extname(file.originalname));
  }
});
const upload = multer({ storage: storage });

//post images
  app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
  });

app.get("/", function(req,res){
    res.sendFile(path.join(__dirname,"/views/home.html"));
  });

  app.get("/about", function(req,res){
    res.sendFile(path.join(__dirname,"/views/about.html"));
  });
  
  app.get("/employees/add", function(req,res){
    res.sendFile(path.join(__dirname,"/views/addEmployee.html"));
  });
  
  //direct to addimage.html.
  app.get("/images/add", function(req,res){
    res.sendFile(path.join(__dirname,"/views/addImage.html"));
  });

  //save and recall images
  app.get("/images",function(req, res){
    fs.readdir(__dirname+"/public/images/add", function(err, data) {
      res.send({images: data}); 
    })
  });

app.post("/employees/add", function(req, res){
    data.addEmployee(req.body).then(res.redirect("/employees"))
    .catch((err) => res.json({"Message": err}))

});

app.get("/employees", function(req,res){
  if(req.query.status){ //This will match the url /employees?status="value".
    data.getEmployeesByStatus(req.query.status)
    .then((data)=>{
      res.json(data);
    })
  }
  else if(req.query.department){ //This will match the url /employees?query="value".
    data.getEmployeesByDepartment(req.query.department)
    .then((data)=>{
      res.json(data);
    })
  }
  else if(req.query.manager){ //This will match the url /employees?manager="value".
    data.getEmployeesByManager(req.query.manager)
    .then((data)=>{
      res.json(data);
    })
  }
  else{
    data.getAllEmployee(req.res)
    .then((data)=>{
      res.json(data);
    })
  }
});

//need ":" to idenfity what to grab.
app.get("/employee/:ID", function(req,res){
  data.getEmployeeByNum(req.params.ID)
  .then((data)=>{
    res.json(data);
  })
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