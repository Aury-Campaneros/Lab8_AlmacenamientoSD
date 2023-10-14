//****************************************************************
// UVG BE3015-Digital 2
// Almacenamiento SD
//****************************************************************
//****************************************************************
// Librerías
//****************************************************************
#include <Arduino.h>
//****************************************************************
// Definición de etiquetas
//****************************************************************

//****************************************************************
// Prototipos de funciones
//****************************************************************
void menu(void);
//****************************************************************
// Variables Globales
//****************************************************************
int opcion=0; // variable que almacena lo que ingresa el usuario
//****************************************************************
// ISR: Interrupciones
//****************************************************************
// void IRAM_ATTR ISR(){
//
//}
//****************************************************************
// Configuración
//****************************************************************
void setup()
{
  Serial.begin(115200); //Iniciar comunicación Serial
  Serial.println("Almacenamiento SD");
  menu();
}
//****************************************************************
// Loop Principal
//****************************************************************
void loop() {
//Prelab-08 - Menú
 if (Serial.available()) {
    opcion = Serial.parseInt();
    switch (opcion) {
      case 1:
        Serial.println(" ");
        Serial.println("Has seleccionado la opción 1");
        Serial.println(" ");
        menu();
        break;
      case 2:
        Serial.println(" ");
        Serial.println("Has seleccionado la opción 2");
        Serial.println(" ");
        menu();
        break;
      case 3:
        Serial.println(" ");
        Serial.println("Has seleccionado la opción 3");
        Serial.println(" ");
        menu();
        break;
    }
  }
}
//****************************************************************
// Funciones
//****************************************************************
void menu(void)
{
  Serial.println("Elige una opción:");
  Serial.println("1. Mostrar imagen 1");
  Serial.println("2. Mostrar imagen 2");
  Serial.println("3. Mostrar imagen 3");
}