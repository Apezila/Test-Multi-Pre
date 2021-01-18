
void ENC () {
  int change1=0;
  int change2=0;
  int change3=0;
  int change4=0;
  int change5=0;
  int change6=0;
  int change7=0;
  int change8=0;

      int ColorBar1 = tft.setColor(rgbtable[v1Amt][0],rgbtable[v1Amt][1],rgbtable[v1Amt][2]);
      int ColorBar2 = tft.setColor(rgbtable[v2Amt][0],rgbtable[v2Amt][1],rgbtable[v2Amt][2]);
      int ColorBar3 = tft.setColor(rgbtable[v3Amt][0],rgbtable[v3Amt][1],rgbtable[v3Amt][2]);
      int ColorBar4 = tft.setColor(rgbtable[v4Amt][0],rgbtable[v4Amt][1],rgbtable[v4Amt][2]);
      int ColorBar5 = tft.setColor(rgbtable[v5Amt][0],rgbtable[v5Amt][1],rgbtable[v5Amt][2]);
      int ColorBar6 = tft.setColor(rgbtable[v6Amt][0],rgbtable[v6Amt][1],rgbtable[v6Amt][2]);
      int ColorBar7 = tft.setColor(rgbtable[v7Amt][0],rgbtable[v7Amt][1],rgbtable[v7Amt][2]);
      int ColorBar8 = tft.setColor(rgbtable[v8Amt][0],rgbtable[v8Amt][1],rgbtable[v8Amt][2]);

  int newA1=mcp.digitalRead(v1Clk);
  int newB1=mcp.digitalRead(v1Dta);
      if (newA1 != v1OldA || newB1 != v1OldB) {
      if(v1OldA == HIGH && newA1==LOW && newB1 == HIGH && v1OldB == HIGH){
        change1 =2;
      }
      if (v1OldB == HIGH && newB1==LOW && newA1 == HIGH && v1OldA == HIGH){
        change1 =1;
      }      
   if(change1==2){     
        v1Amt++;
      if (v1Amt>99){
        v1Amt=99;        
      }
      tft.fillRectangle(52,46,(v1Amt+52),50, ColorBar1);
      Serial.println(v1Amt);
   }
      else if (change1==1){       
        v1Amt--;
        if (v1Amt<0){
          v1Amt=0;         
        }
        tft.fillRectangle(52,46,(152-100)+v1Amt,50, ColorBar1);
        tft.fillRectangle(v1Amt+52,46,152,50, COLOR_BLACK);
        Serial.println(v1Amt);  
   }      
   v1OldA = newA1;
   v1OldB = newB1;
  }

  int newA2=mcp.digitalRead(v2Clk);
  int newB2=mcp.digitalRead(v2Dta);
      if (newA2 != v2OldA || newB2 != v2OldB) {
      if(v2OldA == HIGH && newA2==LOW && newB2 == HIGH && v2OldB == HIGH){
        change2 =2;
      }
      if (v2OldB == HIGH && newB2==LOW && newA2 == HIGH && v2OldA == HIGH){
        change2=1;
      }      
   if(change2==2){     
        v2Amt++;
      if (v2Amt>99){
        v2Amt=99;        
      }
      tft.fillRectangle(52,58,(v2Amt+52),62, ColorBar2);
      Serial.println(v2Amt);
   }
      else if (change2==1){       
        v2Amt--;
        if (v2Amt<0){
          v2Amt=0;         
        }
        tft.fillRectangle(52,58,(152-100)+v2Amt,62, ColorBar2);
        tft.fillRectangle(v2Amt+52,58,152,62, COLOR_BLACK);
        Serial.println(v2Amt);  
   }      
   v2OldA = newA2;
   v2OldB = newB2;
  }

  int newA3=mcp.digitalRead(v3Clk);
  int newB3=mcp.digitalRead(v3Dta);
      if (newA3 != v3OldA || newB3 != v3OldB) {
      if(v3OldA == HIGH && newA3==LOW && newB3 == HIGH && v3OldB == HIGH){
        change3 =2;
      }
      if (v3OldB == HIGH && newB3==LOW && newA3 == HIGH && v3OldA == HIGH){
        change3 =1;
      }      
   if(change3==2){     
        v3Amt++;
      if (v3Amt>99){
        v3Amt=99;        
      }
      tft.fillRectangle(52,70,(v3Amt+52),74, ColorBar3);
      Serial.println(v3Amt);
   }
      else if (change3==1){       
        v3Amt--;
        if (v3Amt<0){
          v3Amt=0;         
        }
        tft.fillRectangle(52,70,(152-100)+v3Amt,74, ColorBar3);
        tft.fillRectangle(v3Amt+52,70,152,74, COLOR_BLACK);
        Serial.println(v3Amt);  
   }      
   v3OldA = newA3;
   v3OldB = newB3;
  }

  int newA4=mcp.digitalRead(v4Clk);
  int newB4=mcp.digitalRead(v4Dta);
      if (newA4 != v4OldA || newB4 != v4OldB) {
      if(v4OldA == HIGH && newA4==LOW && newB4 == HIGH && v4OldB == HIGH){
        change4 =2;
      }
      if (v4OldB == HIGH && newB4==LOW && newA4 == HIGH && v4OldA == HIGH){
        change4 =1;
      }      
   if(change4==2){     
        v4Amt++;
      if (v4Amt>99){
        v4Amt=99;        
      }
      tft.fillRectangle(52,82,(v4Amt+52),86, ColorBar4);
      Serial.println(v4Amt);
   }
      else if (change4==1){       
        v4Amt--;
        if (v4Amt<0){
          v4Amt=0;         
        }
        tft.fillRectangle(52,82,(152-100)+v4Amt,86, ColorBar4);
        tft.fillRectangle(v4Amt+52,82,152,86, COLOR_BLACK);
        Serial.println(v4Amt);  
   }      
   v4OldA = newA4;
   v4OldB = newB4;
  }

  int newA5=mcp.digitalRead(v5Clk);
  int newB5=mcp.digitalRead(v5Dta);
      if (newA5 != v5OldA || newB5 != v5OldB) {
      if(v5OldA == HIGH && newA5==LOW && newB5 == HIGH && v5OldB == HIGH){
        change5 =2;
      }
      if (v5OldB == HIGH && newB5==LOW && newA5 == HIGH && v5OldA == HIGH){
        change5 =1;
      }      
   if(change5==2){     
        v5Amt++;
      if (v5Amt>99){
        v5Amt=99;        
      }
      tft.fillRectangle(52,94,(v5Amt+52),98, ColorBar5);
      Serial.println(v5Amt);
   }
      else if (change5==1){       
        v5Amt--;
        if (v5Amt<0){
          v5Amt=0;         
        }
        tft.fillRectangle(52,94,(152-100)+v5Amt,98, ColorBar5);
        tft.fillRectangle(v5Amt+52,94,152,98, COLOR_BLACK);
        Serial.println(v5Amt);  
   }      
   v5OldA = newA5;
   v5OldB = newB5;
  }

  int newA6=mcp.digitalRead(v6Clk);
  int newB6=mcp.digitalRead(v6Dta);
      if (newA6 != v6OldA || newB6 != v6OldB) {
      if(v6OldA == HIGH && newA6==LOW && newB6 == HIGH && v6OldB == HIGH){
        change6 =2;
      }
      if (v6OldB == HIGH && newB6==LOW && newA6 == HIGH && v6OldA == HIGH){
        change6 =1;
      }      
   if(change6==2){     
        v6Amt++;
      if (v6Amt>99){
        v6Amt=99;        
      }
      tft.fillRectangle(52,124,(v6Amt+52),128, ColorBar6);
      int FV2_S0 = v6Amt;
      FV2_S0 = map(FV2_S0, 0, 99, 0, 255);
      //analogWrite(FV_S0, FV2_S0);
      Serial.println(v6Amt);
   }
      else if (change6==1){       
        v6Amt--;
        if (v6Amt<0){
          v6Amt=0;         
        }
        tft.fillRectangle(52,124,(152-100)+v6Amt,128, ColorBar6);
        tft.fillRectangle(v6Amt+52,124,152,128, COLOR_BLACK);
        Serial.println(v6Amt);  
   }      
   v6OldA = newA6;
   v6OldB = newB6;
  }

  int newA7=mcp.digitalRead(v7Clk);
  int newB7=mcp.digitalRead(v7Dta);
      if (newA7 != v7OldA || newB7 != v7OldB) {
      if(v7OldA == HIGH && newA7==LOW && newB7 == HIGH && v7OldB == HIGH){
        change7 =2;
      }
      if (v7OldB == HIGH && newB7==LOW && newA7 == HIGH && v7OldA == HIGH){
        change7 =1;
      }      
   if(change7==2){     
        v7Amt++;
      if (v7Amt>99){
        v7Amt=99;        
      }
   }
      else if (change7==1){       
        v7Amt--;
        if (v7Amt<0){
          v7Amt=0;         
        }          
   }      
        int FV2_S1 = v7Amt;
        FV2_S1 = map(FV2_S1, 0, 99, 0, 255);
        //analogWrite(FV_S1, FV2_S1);
        tft.fillRectangle(52,136,52+v7Amt,140, ColorBar7);
        tft.fillRectangle(v7Amt+52,136,152,140, COLOR_BLACK);
        Serial.println(v7Amt);
   v7OldA = newA7;
   v7OldB = newB7;
  }

  int newA8=mcp.digitalRead(v8Clk);
  int newB8=mcp.digitalRead(v8Dta);
      if (newA8 != v8OldA || newB8 != v8OldB) {
      if(v8OldA == HIGH && newA8==LOW && newB8 == HIGH && v8OldB == HIGH){
        change8 =2;
      }
      if (v8OldB == HIGH && newB8==LOW && newA8 == HIGH && v8OldA == HIGH){
        change8 =1;
      }      
   if(change8==2){     
        v8Amt++;
      if (v8Amt>99){
        v8Amt=99;        
      }
   }
      else if (change8==1){       
        v8Amt--;
        if (v8Amt<0){
          v8Amt=0;         
        }         
   }      
        int FV2_S2 = v8Amt;
        FV2_S2 = map(FV2_S2, 0, 99, 0, 255);
        //analogWrite(FV_S2, FV2_S2);
        tft.fillRectangle(52,148,v8Amt+52,152, ColorBar8);
        tft.fillRectangle(v8Amt+52,148,152,152, COLOR_BLACK);
        Serial.println(v8Amt);
   v8OldA = newA8;
   v8OldB = newB8;
  }
  
}


      

void FxTypePrint(int fxcount) {

 Fxtype = fxcount; //global

  switch (fxcount) {
    
    case 0:   
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "CHORUS - REVERB   ", COLOR_CYAN); 
      digitalWrite(PB5, LOW);
      digitalWrite(PB4, LOW);
      digitalWrite(PB3, LOW); 
      break;
    
    case 1:  
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "FLANGER - REVERB  ", COLOR_CYAN);    
      digitalWrite(PB5, HIGH);
      digitalWrite(PB4, LOW);
      digitalWrite(PB3, LOW);
      break;
    
    case 2: 
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "TREMOLO - REVERB  ", COLOR_CYAN);
      digitalWrite(PB5, LOW);
      digitalWrite(PB4, HIGH);
      digitalWrite(PB3, LOW);     
      break;
    
    case 3:  
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "ECHO - REVERB     ", COLOR_CYAN);
      digitalWrite(PB5, HIGH);
      digitalWrite(PB4, HIGH);
      digitalWrite(PB3, LOW);     
      break;
    
    case 4:  
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "Vibrato - REVERB  ", COLOR_CYAN);
      digitalWrite(PB5, LOW);
      digitalWrite(PB4, LOW);
      digitalWrite(PB3, HIGH);     
      break;
    
    case 5:  
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "WAH - REVERB      ", COLOR_CYAN);
      digitalWrite(PB5, HIGH);
      digitalWrite(PB4, LOW);
      digitalWrite(PB3, HIGH);     
      break;
    
    case 6:  
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "Phasor - REVERB  ", COLOR_CYAN); 
      digitalWrite(PB5, LOW);
      digitalWrite(PB4, HIGH);
      digitalWrite(PB3, HIGH);  
      break;
    
    case 7: 
      tft.setFont(Terminal6x8);
      tft.drawText(20, 110, "SHIMMER PITCH   ", COLOR_CYAN); 
      digitalWrite(PB5, HIGH);
      digitalWrite(PB4, HIGH);
      digitalWrite(PB3, HIGH);    
      break;
    
  }
}
void SetPress() {
     
    eep.write(preset +100 , AMP_button);
    delay(5);
    eep.write(preset + 200, v1Amt);
    delay(5);
    eep.write(preset + 300, v2Amt);
    delay(5);
    eep.write(preset + 400, v3Amt);
    delay(5);
    eep.write(preset + 500, v4Amt);
    delay(5);
    eep.write(preset + 600, v5Amt);
    delay(5);
    eep.write(preset + 700, v6Amt);
    delay(5);
    eep.write(preset + 800, v7Amt);
    delay(5);
    eep.write(preset + 900, v8Amt);
    delay(5);
    eep.write(preset + 1000, FX_button);
    delay(5);
    eep.write(preset + 1050, LOOP_button);
    delay(5);
    eep.write(preset + 1060, SIM_button);
    delay(5);
    tft.clear();
    tft.setFont(Terminal12x16);
    tft.drawText(70, 50, "S A V E", COLOR_RED);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_WHITE);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_RED);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_WHITE);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_RED);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_WHITE);
    delay(100);
    tft.drawText(70, 50, "S A V E", COLOR_RED);
    
    eep.write(0, preset);
    delay(10);
    //preset = eep.read(900);
    delay(1000);
    tft.clear();
    MainDisplay();     
}
