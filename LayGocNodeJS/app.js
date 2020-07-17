var http = require('http');
const express = require('express'); //Thêm module express vào project.
const app = express(); //Khởi tạo một app mới sử dụng module express
// const port = 3000;  //tên cổng để chạy ứng dụng NodeJS 

app.use(express.static(require('path').join(__dirname, "public")))

var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: 'gch18120',
  database: "mydb"//After create database, add this to add table.
});

con.connect(function (err) {
  if (err) throw err;
  console.log("Connected!");
});

var bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));

// const engines = require('consolidate');
// app.engine('hbs', engines.handlebars);

app.set('views', './views'); // Thư mục views nằm cùng cấp với file app.js
app.set('view engine', 'ejs'); // Sử dụng hbs làm view engine

const toys_Route = require('./routes/toys');
app.use('/', toys_Route);

app.listen(process.env.PORT || 3000, function () {
    console.log("Your app running on port 3000");
})