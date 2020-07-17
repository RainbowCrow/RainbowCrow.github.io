const express = require('express');
const toys_router = express.Router();

const toys_controller = require('../controller/toys');

toys_router.get('/', toys_controller.library) // Lấy hàm ở key index
toys_router.get('/detail', toys_controller.detail)
toys_router.post('/doUpdate', toys_controller.doUpdate)
toys_router.post('/delete', toys_controller.delete)
toys_router.get('/insert', toys_controller.insert)
toys_router.post('/doInsert', toys_controller.doInsert)
toys_router.post('/doSearch', toys_controller.doSearch)

module.exports = toys_router;