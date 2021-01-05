/*********************************************************************************
* WEB322 – Assignment 05
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Jia Hua, Zou Student ID: 114383193 Date: Dec 7,2020
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
const exphbs = require("express-handlebars");
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

/*************************************************************************************/
//Handlebars setup with helpers
app.engine('.hbs', exphbs({ 
  extname: '.hbs',
  helpers: {
    navLink: function(url, options){
      return '<li' +
      ((url == app.locals.activeRoute) ? ' class="active" ' : '') + 
      '><a href="' + url + '">' + options.fn(this) + '</a></li>';
     },
    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
        throw new Error("Handlebars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
        return options.inverse(this);
      } else {
        return options.fn(this);
      }
    }
  } 
}));
app.set('view engine', '.hbs');
/*************************************************************************************/
//fixes the navigation bar
  app.use(function(req,res,next){
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
   });
/*************************************************************************************/

/*************************************************************************************/

  app.get("/", function(req,res){
    res.render('home');
  });

  app.get("/about", function(req,res){
    //res.sendFile(path.join(__dirname,"/views/about.html"));
    res.render('about');
  });
  
  app.get("/employees/add", function(req,res){
    data.getDepartments()
    .then((data) =>{
      res.render("addEmployee", {departments: data});
    })
    .catch(() =>{
      res.render("addEmployee", {departments: []});
    })
  });
  
  //direct to addimage.html.
  app.get("/images/add", function(req,res){
    //res.sendFile(path.join(__dirname,"/views/addImage.html"));
    res.render('addImage');
  });
/*************************************************************************************/
  app.get("/departments/add" , (req, res) => {
    res.render("addDepartment");
  });

  app.post("/departments/add",function(req,res){
    data.addDepartment(req.body)
    .then(() => {
      res.redirect("/departments")
    })
    .catch(() => {
      res.render({message: "no results"});
    })
  });

  app.post("/department/update", function(req,res){
    data.updateDepartment(req.body)
    .then(res.redirect("/departments"))
    .catch(() => {
      res.render({message: "no results"});
    })
  });

  app.get("/department/:departmentId", function(req,res){
    data.getDepartmentById(req.params.departmentId)
    .then((data)=>{
      if(data.length >0) res.render("department", {department:data});
      else res.status(404).send("Department Not Found");
    })
    .catch(()=>{res.status(404).send("Department Not Found")})
  });

  app.get("/department/:departmentId", function(req,res){
    data.updateDepartment(res.params.body)
    .then((data) =>{
      res.redirect("/departments")
    })
    .catch(() => {
      res.status(404).send("Department Not Found")
    })
  });
/*************************************************************************************/
//post images
app.post("/images/add", upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
});
//save and recall images
app.get("/images",function(req, res){
  fs.readdir(__dirname+"/public/images/add", function(err, data) {
    res.render("images", { images: data, title: "Images" });
  })
});
/*************************************************************************************/
/*************************************************************************************/
  //Adding employees and redirecting it to the emplyoee list
  app.post("/employees/add", function(req, res){
    data.addEmployee(req.body)
    .then(res.redirect("/employees"))
    .catch((err) => res.json({"Message": err}))
  });

  app.get("/employees", function(req,res){
    if(req.query.status){ //This will match the url /employees?status="value".
      data.getEmployeesByStatus(req.query.status)
    .then((data)=>{
      if(data.length > 0) res.render("employees", {employees: data});
      else res.render("employees",{ message: "no results" });
    })
    .catch((err) => {
      res.render({message: "no results"});
    })
  }
  else if(req.query.department){ //This will match the url /employees?department="value".
    data.getEmployeesByDepartment(req.query.department)
    .then((data)=>{
      if(data.length > 0) res.render("employees", {employees: data});
      else res.render("employees",{ message: "no results" });
    })
    .catch((err) => {
      res.render({message: "no results"});
    })
  }
  else if(req.query.manager){ //This will match the url /employees?manager="value".
    data.getEmployeesByManager(req.query.manager)
    .then((data)=>{
      if(data.length > 0) res.render("employees", {employees: data});
      else res.render("employees",{ message: "no results" });
    })
    .catch((err) => {
      res.render({message: "no results"});
    })
  }
  else{ //display the table for all employees
    data.getAllEmployee(req.res)
    .then((data) => {
      if(data.length > 0) res.render("employees", {employees: data});
      else res.render("employees",{ message: "no results" });
    })
    .catch(() => {
      res.render({message: "no results"});
    })
  }
});
/*************************************************************************************/

//need ":" to idenfity what to grab.
app.get("/employee/:empNum", (req, res) => {
  // initialize an empty object to store the values
  let viewData = {};
  data.getEmployeeByNum(req.params.empNum).then((data) => {
    if (data) {
      viewData.employee = data; //store employee data in the "viewData" object as "employee"
    } else {
      viewData.employee = null; // set employee to null if none were returned
    }
    }).catch(() => {
        viewData.employee = null; // set employee to null if there was an error
    }).then(data.getDepartments)
    .then((data) => {
      viewData.departments = data; // store department data in the "viewData" object as "departments"
  // loop through viewData.departments and once we have found the departmentId that matches
  // the employee's "department" value, add a "selected" property to the matching
  // viewData.departments object
    for (let i = 0; i < viewData.departments.length; i++) {
      if (viewData.departments[i].departmentId == viewData.employee.department) {
        viewData.departments[i].selected = true;
      }
    }
    }).catch(() => {
      viewData.departments = []; // set departments to empty if there was an error
    }).then(() => {
      if (viewData.employee == null) { // if no employee - return an error
        res.status(404).send("Employee Not Found");
    } else {
      res.render("employee", { viewData: viewData }); // render the "employee" view
    }
    });
 });
 
//Delete employee by finding the Id
app.get("/employees/delete/:empNum", function(req,res){
  data.deleteEmployeeByNum(req.params.empNum)
  .then(() =>{
    res.redirect("/employees")
  })
  .catch(()=>{
    res.status(500).send("Unable to Remove Employee / Employee not found")
  })
})
//Delete department by Id
app.get("/department/delete/:departNum", function(req,res){
  data.deletedepartmentById(req.params.departNum)
  .then(() =>{
    res.redirect("/departments")
  })
  .catch(()=>{
    res.status(500).send("Unable to Remove Department / Department not found")
  })
})

//Updates the information about the selected employee.
app.post("/employee/update", (req,res) =>{
  data.updateEmployee(req.body)
  .then(res.redirect("/employees"))
});

app.get("/managers", function(req,res){
  data.getManagers().then((data) =>{
    res.json(data);
  });
});
//THIS NEEDS FIXING!!! NOT SHOWING NO RESULT MESSAGE!!!!
app.get("/departments", function(req,res){
  data.getDepartments()
  .then((data) =>{
    if(data.length >0) res.render("departments", {departments: data});
    else res.render("departments",{message: "no results"});
  })
  .catch(() =>{
    res.render({ message: "no results" });
  });
});
/*************************************************************************************/
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