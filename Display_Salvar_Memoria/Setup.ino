
void Initialize(){
//=====================
openFS();

 // no primeiro upload de programa o arquivo state.txt deve ser criado com o conteúdo "off"
 // no segundo upload a linha deve ser comentada.
  
 //writeFile("Quatroio", "/state.txt");
 message = readFile("/state.txt");


//=======================  
  Serial.begin(115200); // initialize serial communications

  matrix.setIntensity(2);    // Use a value between 0 and 15 for brightness
  matrix.setRotation(0, 1);  // The first display is position upside down
  matrix.setRotation(1, 1);  // The first display is position upside down
  matrix.setRotation(2, 1);  // The first display is position upside down
  matrix.setRotation(3, 1);  // The first display is position upside down
  wait    = 25;
  //message = "Message Board (C) D.L.Bird 2017";

  display_message(message); // Display the message
  wait    = 50;
   
  
}
