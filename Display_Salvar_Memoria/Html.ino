// HTML web page to handle 3 input fields (input1, input2, input3)

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>

<meta http-equiv='refresh' content='60'/>
<meta http-equiv='content-type' content='text/html; charset=UTF-8'/>


  <title>ESP Quatroio Display</title><style>

  body {width:px;
  margin:0 
  auto;
  font-family:arial;
  font-size:14px;
  text-align:center;color:#00008B;
  background-color:#F7F2Fd;}
  
  ul{list-style-type:none;margin:0;
  padding:0;
  overflow:hidden;
  background-color:#d8d8d8;
  font-size:14px;}

  li{float:left;
  border-right:1px solid #bbb;
  }
  last-child {
  border-right:none;
  }
  
  li a{display: block;
  padding:2px 12px;
  text-decoration:none;
  }
  li a:hover{
    background-color:#FFFFFF;
  }
  section {
    font-size:16px;
    }
  p {
    background-color:#E3D1E2;font-size:16px;
    }
 div.header,div.footer{padding:0.5em;
 color:white;
 background-color:gray;clear:left;
 }
 h1{
  background-color:#d8d8d8;
  font-size:26px;
  }
  
  h2{
    color:#9370DB;
    font-size:22px;
    line-height:65%;
    }
h3{
  color:#9370DB;font-size:16px;
  line-height:55%;
  }
   table{
    font-family:arial,sans-serif;
    font-size:16px;
    border-collapse:collapse;
    width:100%;
    height:100%;
    }  
td {
  border:0px solid black;
  text-align:center;
  padding:2px;
  }
 th {
  border:0px solid black;
  text-align:center;
  padding:2px;font-size:22px;
  }
.style1 {
  text-align:center;
  font-size:50px;
  background-color:#D8BFD8;
  height:57px;
  }
.style2 {text-align:center;font-size:16px;
background-color:#ADD8E6;
color:#0066ff;
height:25px;
}
.style3 {
  text-align:center;
  font-size:78px;
  background-color:#FFE4B5;
  height:107px;
  }

 .style4 {
  text-align:center;
  font-size:16px;
  background-color:#FFE4B5;
  height:30px;
  }   
   .style5 {
    text-align:center;
    font-size:20px;
    background-color:#D9BFD9;
    }
  .style6 td {
    border:0px solid black;
    text-align:right;
    padding:0px;
    font-size:14px;
    background-color:#B0C4DE;
    color:#0066ff;
    height:20px;
    } 
.style7 {
  text-align:center;
  font-size:12px;
  background-color:#F7F2Fd;width:100%;
  }
.style8 {
  text-align:center;
  border:0px solid black;
  padding:2px;color:#990099;
  }
.style9 {
  text-align:center;
  font-size:14px;
  color:blue;
  }
  img.imgdisplay {
    display:block;
    margin-left:auto;
    margin-right:auto;
    } 
sup {
  vertical-align:super;
  font-size:26px;
  }
   sup1{
    vertical-align:super;
    font-size:10px;
    } 
        
  </style></head>
  <body>
  <h1>Message configuration</h1>
  <h2>
Enter the command "config" to configure the message.</h2>  
  
<!----------------------------------------------------------> 
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
  input1: <input type="text" name="input1">
  <input type="submit" value="Submit">
  </form><br>
  </body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void InitHtml(){
  WiFi.softAP(ssid);
  IPAddress local_IP(192, 168, 4, 100); // Use the same adress here as defualt softAP
  IPAddress gateway(192, 168, 4, 10);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAP(ssid);
  Serial.print(F("Use this URL to connect: http://")); Serial.println(WiFi.softAPIP().toString() + "/"); // Print the IP address

  server.begin(); 
  Serial.println(F("Webserver started..."));
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Send web page with input fields to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
    }

    else {
      inputMessage = "No message sent";
      inputParam = "none";    }   
      Serial.println(inputMessage);
      
      if(inputMessage){
        Serial.print("Html passou");
      }
      
//==================================================================================

if(conf == 1){  
writeFile(inputMessage , "/state.txt");
message = inputMessage;
Serial.print ("recebi:");
conf = 0 ;

}else{
Serial.println(configurar );
}

if (inputMessage == "config" || inputMessage == "Config"){ 
conf = 1;
message = "Quatroio diz: tudo pronto para configurar ...";
Serial.print("Correto!Digite um novo Texto.");
configurar = "";
}
      
      //==================================================================================
    
    request->send(200, "text/html", "The data was successfully saved:!( " 
                                     + inputParam + ") with value: " + inputMessage +
                                     "<br><a href=\"/\">Return to Home Page</a>"+ "<br><h2>alvaroxramos@gmail.com</a>");
  });


  
  server.onNotFound(notFound);
  server.begin();
  
}
