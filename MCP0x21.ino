void BUTTON () {
     
   AMPState = mcpx.digitalRead(AMP_buttonPin);
    if (AMPState != lastAMPState) {
    if ( AMPState == LOW) {
       AMP_button++;
       if(AMP_button > 2)AMP_button =0; 
    }
       amptype = AMP_button ;
       AmpTypePrint(amptype);
    }
    lastAMPState = AMPState;
       
   FXState = mcpx.digitalRead(FX_buttonPin);
    if (FXState != lastFXState) {
    if ( FXState == LOW) {
       FX_button++;
       if(FX_button > 7)FX_button =0; 
    }
       Fxtype = FX_button;
       FxTypePrint(Fxtype);
   }
      lastFXState = FXState; 

   LOOPState = mcpx.digitalRead(LOOP_buttonPin);
    if (LOOPState != lastLOOPState) {
    if ( LOOPState == LOW) {
       LOOP_button++;
       if(LOOP_button > 1)LOOP_button =0; 
    }
   }
   lastLOOPState = LOOPState;

   SIMState = mcpx.digitalRead(SIM_buttonPin);
    if (SIMState != lastSIMState) {
    if ( SIMState == LOW) {
       SIM_button++;
       if(SIM_button > 1)SIM_button =0; 
    }
   }
   lastSIMState = SIMState;

   OUTState = mcpx.digitalRead(OUT_buttonPin);
    if (OUTState != lastOUTState) {
    if ( OUTState == LOW) {
       OUT_button++;
       if(OUT_button > 1)OUT_button =0; 
    }
   }
   lastOUTState = OUTState;

   
    if (LOOP_button == 0) {
        digitalWrite(PB11, HIGH);
        tft.setFont(Terminal6x8);
        tft.drawText(200, 164, "ON  ", COLOR_WHITE);
     }
     else {
        digitalWrite(PB11, LOW ); 
        tft.setFont(Terminal6x8);
        tft.drawText(200, 164, "OFF", COLOR_WHITE);  
     }

     if (SIM_button == 0) {
        digitalWrite(PC14, HIGH);
        tft.setFont(Terminal6x8);
        tft.drawText(134, 164, "ON  ", COLOR_WHITE);
     }
     else {
        digitalWrite(PC14, LOW ); 
        tft.setFont(Terminal6x8);
        tft.drawText(134, 164, "OFF", COLOR_WHITE);  
     }
    
    if (OUT_button == 0) {
        mcpx.digitalWrite(LED_BYPASS,LOW);
        mcpx.digitalWrite(LED_Pedal,LOW);
        mcpx.digitalWrite(LED_PRE,HIGH);
        digitalWrite(PA6, HIGH);
        tft.setFont(Terminal6x8);
        tft.drawText(35, 164, "PreAmp", COLOR_WHITE);
     }
      if (OUT_button == 1){
        mcpx.digitalWrite(LED_PRE,LOW);
        mcpx.digitalWrite(LED_Pedal,HIGH);
        digitalWrite(PA6, LOW);
        tft.setFont(Terminal6x8);
        tft.drawText(35, 164, "Pedal   ", COLOR_WHITE);
       if (Bypasstype== 0) {
          mcpx.digitalWrite(LED_BYPASS,HIGH); 
          digitalWrite(PC13,LOW);
          }
          if (Bypasstype== 1) {
          mcpx.digitalWrite(LED_BYPASS,LOW);
          digitalWrite(PC13,HIGH);
          }
       }
}
      
     

void BypassClick(){
   if (OUT_button == 0) {
    mcpx.digitalWrite(LED_BYPASS,HIGH);
    delay(30);
    mcpx.digitalWrite(LED_BYPASS,LOW);
   }
   if (OUT_button == 1) {
    Bypasstype++;
    if(Bypasstype >1)Bypasstype =0;  
    Serial.println(Bypasstype);      
   }
}    
