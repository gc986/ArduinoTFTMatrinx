//Цветной графический дисплей 3.2 TFT 480x320 MEGA http://iarduino.ru/shop/Displei/cvetnoy-graficheskiy-displey-3-2-tft-480x320.html

#include <UTFT.h>                              // подключаем библиотеку UTFT
UTFT myGLCD(TFT32MEGA, 38,39,40,41);           // объявляем объект myGLCD класса библиотеки UTFT указывая тип дисплея TFT32MEGA и номера выводов Arduino к которым подключён дисплей: RS, WR, CS, RST. Выводы параллельной шины данных не указываются
//          TFT32MEGA_2                        // если изображение на дисплее отображается зеркально, значит для инициализации Вашего дисплея, нужно указать не TFT32MEGA, а TFT32MEGA_2.
                                               // (тип TFT32MEGA - для дисплеев на базе чипа ILI9481, а тип TFT32MEGA_2 - для дисплеев на базе чипа HX8357С).
extern uint8_t BigFont[];                      // подключаем большой шрифт
                                               //
void setup(){         
  // инициализируем генератор псевдослучайных чисел
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
   myGLCD.InitLCD();                           // инициируем дисплей
}                                              //
                                               //
void loop(){                                   //
   myGLCD.setColor(0, 255, 0); 
   myGLCD.setFont(BigFont);                    // устанавливаем большой шрифт
   myGLCD.clrScr();                            // стираем всю информацию с дисплея
   
  // !!!ARRAYS!!!
  int arrX[12];
  int arrY[12];

  int arrX_[12];
  int arrY_[12];

  for(int i = 0 ; i < 12 ; i++){
    arrX[i] = random(60);
    arrY[i] = random(30)*16;

    arrX_[i] = arrX[i];
    arrY_[i] = arrY[i]-(16*10);
  }

   while(true){

      // !!!ARRAYS!!!
      for(int i = 0 ; i < 12 ; i++){
        myGLCD.print(70, arrX[i], arrY[i], 0);
        arrY[i]+=16;
        // 1_
        myGLCD.print(" ", arrX_[i], arrY_[i], 0);
        arrY_[i]+=16;
      }

      delay(100);

     // !!!ARRAYS!!!
     for(int i = 0 ; i < 12 ; i++){
       if(arrY[i]>320){
          arrY[i] = -16;
          arrX[i] = random(30)*16;
       }
       if(arrY_[i]>320){
          arrY_[i] = arrY[i]-(16*10);
          arrX_[i] = arrX[i];
       }
     }

   }
}
