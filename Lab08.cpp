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
//****************************************************************
// Variables Globales
//****************************************************************
int opcion=0; // variable que almacena lo que ingresa el usuario
File myFile; 
//****************************************************************
// Configuración
//****************************************************************
void setup()
{
  Serial.begin(115200); //Iniciar comunicación Serial
  Serial.println("Almacenamiento SD");
  //SPI.setModule(0); //selecciona el modulo o para utilizar el SPI0
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
//****************************************************************