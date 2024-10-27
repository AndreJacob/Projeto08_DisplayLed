void DisplayMensage(){

if (Serial.available ()> 0) {
if(conf == 1){  
message =  Serial.readString (); // leia o byte recebido:
writeFile(message , "/state.txt");
Serial.print ("recebi:");
conf = 0 ;
}else{
configurar =  Serial.readString ();
Serial.print("  Passou  ");
Serial.println(configurar );
}

if (configurar == "config" ||configurar == "Config"){ 
conf = 1;
message = "Quatroio diz: tudo pronto para configurar ...";
Serial.print("Correto!Digite um novo Texto.");
configurar = "";
}
 }   
display_message(message); // Display the message
  
}
