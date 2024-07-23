#include <LedControl.h>   
#define dataPin0   4   
#define dataClock0 3   
#define dataLoad0  2   

LedControl matrix_unidades = LedControl(dataPin0,dataClock0,dataLoad0,1);

int pot = A2;
int potval = 0;

byte pacman1[8]= {
  B00111110,
  B01000001,
  B10010001,
  B10000010,
  B10000101,
  B10000010,
  B01000001,
  B00111110
};
byte pacman2[8]= {	
  B00111100,				
  B01000010,
  B10010001,
  B10000001,
  B10001111,
  B10000001,
  B01000010,
  B00111100
};

unsigned long update_delay;

//Prototipos de funciones
int display_number(unsigned char number);

void setup(){
  Serial.begin(9600); //Inicio la comunicacion serial a 9600 baudios.
  matrix_unidades.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  matrix_unidades.setIntensity(0,15);  //Brilo a la mitad 
  matrix_unidades.clearDisplay(0);    //limpio el display
  Serial.println("Uso del controlador led max7219 y una matriz led");
}


void loop() {
  potval = analogRead(pot);
  update_delay = potval;
  for(int i =0; i<2;i++){
    display_number(i);
    delay(update_delay);
  }
}

int display_number(unsigned char number){

  switch (number){
    case (0):{
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,pacman1[i]);
      }
      break;
    }  
    case (1):{
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,pacman2[i]);
      }
      break;
    }  
  }
}