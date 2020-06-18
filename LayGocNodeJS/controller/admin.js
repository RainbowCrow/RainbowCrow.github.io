var MongoClient = require('mongodb').MongoClient;
var url = 'mongodb+srv://RbCrow:gch18120@cluster0-snylr.mongodb.net/test';

module.exports = {
    index: function (req, res) {
        res.render('admin/home');
    },
    hire_return: async (req, res) => {
        let client = await MongoClient.connect(url);
        let dbo = client.db("Library");
        let results = await dbo.collection("Renters").find({}).toArray();
        res.render('admin/renter', { renters: results });
    },
    add_renter: function (req, res) {
        res.render('admin/insert');
    },
    doAdd: async (req, res) => {
        let date = req.body.date;
        let renter = req.body.renter;
        let bookid = req.body.bookid;
        let amount = req.body.amount;

        var ObjectID = require('mongodb').ObjectID;
        let client = await MongoClient.connect(url);
        let dbo = client.db("Library");

        let result = await dbo.collection("Books").findOne({}, { projection: { bookid: bookid } });
        let result1 = await dbo.collection("Books").findOne({ "_id": ObjectID(result._id) }); //lấy sách.

        let newRenter = { date: date, renter: renter, amount: amount, book: result1.name };
        let newAmount = result1.amount - amount;
        let decrease_amount = { $set: { amount: newAmount }};
        await dbo.collection("Renters").insertOne(newRenter);
        await dbo.collection("Books").updateOne({"_id": ObjectID(result._id)}, decrease_amount);
        let results = await dbo.collection("Renters").find({}).toArray();
        res.render('admin/renter', { renters: results });
    },
};
