//****************************************************************
// UVG BE3015-Digital 2
// Almacenamiento SD // Aura Campaneros 211054
//****************************************************************
//****************************************************************
// Librerías
//****************************************************************
#include <Arduino.h>
#include <SPI.h>
#include <SD.h> 
//****************************************************************
// Definición de etiquetas
//****************************************************************
#define chipSelect 5 //CS de la SD
//****************************************************************
// Prototipos de funciones
//****************************************************************
void menu(void);
void imagen(const char* imagenASCII);
void imagenNueva(String imagenUsuario);
String usuario();
//****************************************************************
// Variables Globales
//****************************************************************
int opcion=0; // variable que almacena lo que ingresa el usuario
File myFile;
File myFile2; 
//****************************************************************
// Configuración
//****************************************************************
void setup()
{
  Serial.begin(115200); //Iniciar comunicación Serial
  Serial.println("Almacenamiento SD");
  Serial.println("Inicializando la tarjeta SD. . .");
  pinMode(chipSelect, OUTPUT); //se indica que el GPIO5 es salida 
  if(!SD.begin(chipSelect)){   // Inicializar la SD 
    Serial.println("¡Inicialización fallida!");
    return;
  }
  Serial.println("Inicialización realizada.");
  menu();
}
//****************************************************************
// Loop Principal
//****************************************************************
void loop() {
 if (Serial.available()) {
    opcion = Serial.parseInt();
    switch (opcion) {
      case 1:
        Serial.println(" ");
        imagen("/mariposa.txt");
        Serial.println(" ");
        menu();
        break;
      case 2:
        Serial.println(" ");
        imagen("/honguito.txt");
        Serial.println(" ");
        menu();
        break;
      case 3:
        Serial.println(" ");
        imagen("/flor.txt");
        Serial.println(" ");
        menu();
        break;
      case 4:
        Serial.println(" ");
        imagenNueva("/imagen_creada.txt");
        Serial.println(" ");
        Serial.println("*********Has creado la siguiente imagen*********");
        imagen("/imagen_creada.txt");
        Serial.println(" ");
        menu();
        break;
    }
  }
}
//****************************************************************
// Funciones
//****************************************************************
void menu(void) //Función que contine el menú
{
  Serial.println("Elige una opción:");
  Serial.println("1. Mostrar imagen 1");
  Serial.println("2. Mostrar imagen 2");
  Serial.println("3. Mostrar imagen 3");
  Serial.println("4. Crea tu propia imagen");
}

void imagen(const char* imagenASCII) // Función que abre y lee el archivo en la SD
{
  //Se abre el archivo para leer 
  myFile = SD.open(imagenASCII);
  if(myFile){
    Serial.println(imagenASCII);
    while(myFile.available()){
      Serial.write(myFile.read());
    }
    //Cerrar el archivo
    myFile.close();
  }
  else{
    //Si el archivo no se abrió, imprima un error
    Serial.print("Error al abrir la imagen:");
    Serial.println(imagenASCII);
  }
}

String usuario() { //Lee lo que el usuario ingresa al monitor serial
  String recibir = "";
  char caracter;
  while (true) {
    if (Serial.available()) {
      caracter = Serial.read();
      if (caracter == '\n') {
        break;
      } else {
        recibir += caracter;
      }
    }
  }
  return recibir;
}

void imagenNueva(String imagenUsuario) // Función para escribir en un archivo de la SD
{
  String comandos;  // Variable que almacena la cadena de acaracteres de la imagen
  Serial.println("***************Creando tu propia imagen***************");
  Serial.println("*Ingresa los comandos de tu nueva imagen");
  Serial.println("*Al finalizar, escribe 'FIN' en una lina aparte ");
  while(true){
    String lineFinal = usuario();
    if(lineFinal=="FIN"){
      break;
    }
    comandos += lineFinal + "\n"; // // Añade un salto de línea después de cada línea ingresada
  }
  //Escribe la información en un nuevo archivo
  myFile2 = SD.open(imagenUsuario, FILE_WRITE);
  if(myFile2){
    
    myFile2.println(comandos);
    //Cerrar el archivo
    myFile2.close();
    Serial.println("Imagen Creada");

  }
  else{
    //Si no se puede guardar la imagen, imprima un error
    Serial.print("Error al crear la imagen");
  }
}
//****************************************************************
