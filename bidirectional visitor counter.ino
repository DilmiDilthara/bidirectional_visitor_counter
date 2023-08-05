#include <Bounce.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


int led = 2;
int in = 0;
int out = 0;
int total =0;

Bounce button1 = Bounce (6,1);
Bounce button2 = Bounce (7,1);


void setup() {
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("In: ");
  lcd.setCursor(10,0);
  lcd.print("Out: ");
  lcd.setCursor(0,1);
  lcd.print("Total Inside: ");
  

}

void loop() {
  if(button1.update()){
    if(button1.risingEdge()){
    in++;
    digitalWrite(2, HIGH);
    }
  }

    if(button2.update()){
      if(button2.risingEdge()){
        out++;
    }
  }

  total = in-out;

  lcd.setCursor(3,0);
  lcd.print(in);

  lcd.setCursor(14,0);
  lcd.print(out);

  lcd.setCursor(14,1);
  lcd.print(total);
 
}
