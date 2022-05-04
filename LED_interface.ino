int knob = A0;
int button = 2;
int x;
int soil,set;
int knob_value()
{ 
    x = analogRead(knob);
    if (x>= 0 && x<= 200){x=1;}
    else if (x > 200 && x <= 400){x=2;}
    else if (x > 600 && x <= 800){x=3;}
    else if (x > 800 && x <= 1000){x=4;}
    else if (x > 1000){x=5;}
    return x; 
}
void menu()
{ 
  while(1) 
  {   set=0;
      x = knob_value()
      switch (x)
      { 
           case 1: tft.setTextWrap(false);
                  tft.fillScreen(ST77XX_BLACK);
                  tft.setCursor(0,0);
                  tft.setTextColor(ST77XX_GREEN);
                  tft.setTextSize(4);
                  tft.println("MENU");
                  tft.setTextSize(2);
                  tft.setTextColor(ST77XX_BLUE);
                  tft.println("-Select Crop");  
                  tft.setTextColor(ST77XX_GREEN);
                  tft.println("-View conditions");
                  tft.println("-Exit");
                  if( digitalRead(button))
                  { 
                    while(set==0)
                    {
                      x= knob_value()
                      switch(x)
                      {
                       case 1:  tft.setTextWrap(false);
                                tft.fillScreen(ST77XX_BLACK);
                                tft.setCursor(0,0);
                                tft.setTextColor(ST77XX_GREEN);
                                tft.setTextSize(4);
                                tft.println("Select crop");
                                tft.setTextSize(2);
                                tft.setTextColor(ST77XX_BLUE);
                                tft.println("-Chilli");  
                                tft.setTextColor(ST77XX_GREEN);
                                tft.println("-Tomato");
                                tft.println("-Strawberry");
                                tft.println("-Cucumber");
                                tft.println("-BACK");
                                if(digitalRead(button))
                                { 
                                  soil = 40;
                                  set=1;  
                                }
                                break; 
                         case 2:tft.setTextWrap(false);
                                tft.fillScreen(ST77XX_BLACK);
                                tft.setCursor(0,0);
                                tft.setTextColor(ST77XX_GREEN);
                                tft.setTextSize(4);
                                tft.println("Select crop");
                                tft.setTextSize(2);
                                tft.println("-Chilli");  
                                tft.setTextColor(ST77XX_BLUE);
                                tft.println("-Tomato");
                                tft.setTextColor(ST77XX_GREEN);
                                tft.println("-Strawberry");
                                tft.println("-Cucumber");
                                tft.println("-BACK");
                                if(digitalRead(button))
                                { 
                                  soil = 60;
                                  set=1;  
                                }
                                break;
                       case 3:  tft.setTextWrap(false);
                                tft.fillScreen(ST77XX_BLACK);
                                tft.setCursor(0,0);
                                tft.setTextColor(ST77XX_GREEN);
                                tft.setTextSize(4);
                                tft.println("Select crop");
                                tft.setTextSize(2);
                                tft.println("-Chilli");  
                                tft.println("-Tomato");
                                tft.setTextColor(ST77XX_BLUE);
                                tft.println("-Strawberry");
                                tft.setTextColor(ST77XX_GREEN);
                                tft.println("-Cucumber");
                                tft.println("-BACK");
                                if(digitalRead(button))
                                { 
                                  soil = 50;
                                  set=1;  
                                }
                                break;
                       case 4:  tft.setTextWrap(false);
                                tft.fillScreen(ST77XX_BLACK);
                                tft.setCursor(0,0);
                                tft.setTextColor(ST77XX_GREEN);
                                tft.setTextSize(4);
                                tft.println("Select crop");
                                tft.setTextSize(2);
                                tft.println("-Chilli");  
                                tft.println("-Tomato");
                                tft.println("-Strawberry");
                                tft.setTextColor(ST77XX_BLUE);
                                tft.println("-Cucumber");
                                tft.setTextColor(ST77XX_GREEN);
                                tft.println("-BACK");
                                if(digitalRead(button))
                                { 
                                  soil = 80;
                                  set=1;  
                                }
                                break;
                         case 5:  tft.setTextWrap(false);
                                tft.fillScreen(ST77XX_BLACK);
                                tft.setCursor(0,0);
                                tft.setTextColor(ST77XX_GREEN);
                                tft.setTextSize(4);
                                tft.println("Select crop");
                                tft.setTextSize(2);
                                tft.println("-Chilli");  
                                tft.println("-Tomato");
                                tft.println("-Strawberry");
                                tft.println("-Cucumber");
                                tft.setTextColor(ST77XX_BLUE);
                                tft.println("-BACK");
                                if(digitalRead(button))
                                { 
                                  
                                  set=1;  
                                }
                                break;
                      }
                      
                    } 
                  }
           case 2: tft.setTextWrap(false);
                    tft.fillScreen(ST77XX_BLACK);
                    tft.setCursor(0,0);
                    tft.setTextColor(ST77XX_GREEN);
                    tft.setTextSize(4);
                    tft.println("MENU");
                    tft.setTextSize(2);
                    tft.setTextColor(ST77XX_GREEN);
                    tft.println("-Select Crop");
                    tft.setTextColor(ST77XX_BLUE);
                    tft.println("-View conditions");
                    tft.setTextColor(ST77XX_GREEN);
                    tft.println("-Exit");        
            case 3: tft.setTextWrap(false);
                    tft.fillScreen(ST77XX_BLACK);
                    tft.setCursor(0,0);
                    tft.setTextColor(ST77XX_GREEN);
                    tft.setTextSize(4);
                    tft.println("MENU");
                    tft.setTextSize(2);
                    tft.setTextColor(ST77XX_GREEN);
                    tft.println("-Select Crop");
                    tft.println("-View conditions");
                    tft.setTextColor(ST77XX_BLUE);
                    tft.println("-Exit");
                  
       }
  }
}
void setup()
{
  pinMode(button,INPUT);
  pinMode(knob,INPUT);
  Serial.begin(9600);

}

void loop()
{
 

delay(100);

}
