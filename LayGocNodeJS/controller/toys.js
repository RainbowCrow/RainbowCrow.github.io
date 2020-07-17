var mysql = require('mysql');

var con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: 'gch18120',
    database: "library"//After create database, add this to add table.
});

module.exports = {
    library: async (req, res) => {
        con.connect(function () {
            con.query("SELECT * FROM toys", function (err, toys) {
                if (err) throw err;
                res.render('toys/library', { toys });
            });
        })
    },
    detail: async (req, res) => {
        con.connect(function () {
            var id = req.query.id;
            var query = "SELECT * FROM toys WHERE toyid = ?";
            con.query(query, [id], function (err, toy) {
                if (err) throw err;
                res.render('toys/detail', { toy });
            });
        });
    },
    doUpdate: async (req, res) => {
        let id = req.body.id;
        let toy = req.body.toy;
        let price = req.body.price;
        let amount = req.body.amount;

        let query = 'UPDATE toys SET toy = ' + mysql.escape(toy) + ', price = ' + price + ', amount = ' + amount + ' WHERE toyid =' + id;

        con.connect(function () {
            con.query(query, function (err, result) {
                if (err) throw err;
                else console.log("Update succeess.");
            });
        });
        res.redirect('/');
    },
    delete: async (req, res) => {
        let id = req.body.id;
        var query = "DELETE FROM toys WHERE toyid = " + id;
        con.connect(function () {
            con.query(query, function (err, result) {
                if (err) throw err;
                else console.log("Delete success.");
            });
        });
        res.redirect('/');
    },
    insert: function (req, res) {
        res.render('toys/insert');
    },
    doInsert: (req, res) => {
        let toyid = req.body.toyid;
        let toy = req.body.toy;
        let price = req.body.price;
        let amount = req.body.amount;

        let value = [
            [parseInt(toyid), toy, parseInt(price), parseInt(amount)]
        ];

        let query = "INSERT INTO toys VALUES ?"
        con.connect(function () {
            con.query(query, [value], function (err, result) {
                if (err) throw err;
                else console.log("Insert success");
            })
        });
        res.redirect('/');
    },

    doSearch: (req,res) => {
        let name = req.body.namesearch;
        let query = "SELECT * FROM toys WHERE toy LIKE '%" + name +"%'";
        con.connect(function () {
            con.query(query, function (err, toys) {
                if (err) throw err;
                console.log({toys});
                res.render('toys/library', { toys });
            });
        })
    }
};
