// 모듈을 추출합니다.
var socketio = require('socket.io');
var express = require('express');
var http = require('http');
var ejs = require('ejs');
var fs = require('fs');
var mongoose = require('mongoose');
var db = mongoose.connection;

// 웹 서버를 생성합니다.
var app = express();
app.use(express.static('public'));

// 웹 서버를 실행합니다.
var server = http.createServer(app);
server.listen(8000, function () {
    console.log('server running at http://127.0.0.1:8000');
});

/*var mongoClient = new MongoClient(new Server('localhost', 27017, {'native_parer': true}));
var db = mongoClient.db('dicon2016_rank');*/

// 라우트를 수행합니다.
app.get('/', function (request, response) {
    fs.readFile('html/index.html', function (error, data) {
        response.send(data.toString());
    });
});

app.get('/game', function (request, response) {
    fs.readFile('html/gameScene.html', 'utf8', function (error, data) {
        response.send(data.toString());
        /*response.send(ejs.render(data, {
            room: request.params.room
        }));*/
    });
});

app.get('/rank', function (request, response) {
    /*db.collection.findAll({}, function(err, doc) {
        if(err) throw err;
        response.send(ejs.render(data, {
            ranks: doc
        }));
    });*/
});

app.get('/credit', function (request,response) {
    fs.readFile('html/credit.html', function (error, data) {
        response.send(data.toString());
    });
})

// 소켓 서버를 생성합니다.
var io = socketio.listen(server);
io.sockets.on('connection', function (socket) {

    var nickname;
    var min, sec;

    socket.on('join', function (data) {
        nickname = prompt("닉네임을 입력해주세요");
        socket.join(data);
        roomId = data;
    });

    socket.on('finish', function (_min, _sec) {
        min = _min;
        sec = _sec;
    });
});
