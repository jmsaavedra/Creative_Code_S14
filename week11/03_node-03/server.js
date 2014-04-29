var http = require("http");
var url = require("url");
var fs = require("fs");
var port = 8080;

var index, about;


fs.readFile('./index.html', function(err,data){
	
	if(err) throw err;
	index = data;
	
});

fs.readFile('./about.html', function(err,data){
	
	if(err) throw err;
	about = data;
});

http.createServer(function(request,response){
	
	var pathname = url.parse(request.url).pathname;
	
	console.log("Full Request URL: "+request.url);

	console.log("Request for "+ pathname + " received");
	
	if(pathname=="/" || pathname== "/index.html"){ 
		response.writeHead(200, {"Content-Type": "text/html"});
		response.write(index);
	
	}else if(pathname=="/about.html"){ 
		response.writeHead(200, {"Content-Type": "text/html"});
		response.write(about);
	
	}else{

		response.writeHead(404, {"Content-Type": "text/html"});
		response.write("Page Not Found");
	}

	response.end();
	
}).listen(port);

console.log("Server Running on Port "+port);
