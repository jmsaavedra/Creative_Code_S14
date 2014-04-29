
var http = require("http"); //require the NODE.js http Module
var port = 8080;
var num = 0;

http.createServer(function(request, response){

	//console.log("req: "+ JSON.stringify(request.headers));

	response.writeHead(200, {"Content-Type": "text/plain", //"text/html", "text/json"
							 "Accept-Charset": "utf-8" });

	console.log(request.url);

	num++;
	response.write("<h1>Hello World!</h1> \n");
	response.end("Request Number= "+num);

}).listen(port);

console.log("Started Server on Port "+port);
