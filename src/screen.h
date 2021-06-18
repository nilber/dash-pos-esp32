#include <screen_header.h>
#include <ArduinoJson.h>

void initScreen(){
     nexInit();
     delay(1000);
}


void show_page(int i){
    millisInactivePayment = millis();
    CURRENT_PAGE = i;
    switch (i)
    {
    case 0:
        splashPage.show();
        break;
    case 1:
        qrcodePage.show();
        strcpy(buffer, TOKEN_QRCODE.c_str());
        txtQR.setText(buffer);
        txtAddress.setText(buffer);

        strcpy(buffer, SERVER_TIME.c_str());        
        txtServerTime.setText(buffer);
        break;
    case 2:
        successPage.show();
        break;
    }

}


void sound(){
    pinMode(SPEAKER, OUTPUT);
    digitalWrite(SPEAKER, HIGH);
    delay(100);
    digitalWrite(SPEAKER, LOW);
    delay(100);
    digitalWrite(SPEAKER, HIGH);
    delay(100);
    digitalWrite(SPEAKER, LOW);
    delay(100);
    digitalWrite(SPEAKER, HIGH);
    delay(100);
    digitalWrite(SPEAKER, LOW);
    delay(100);
    digitalWrite(SPEAKER, HIGH);
    delay(100);
    digitalWrite(SPEAKER, LOW);
}


void newMsgScreen(String msg){
    

    Serial.println("Chegou => " + msg);

    String cmd = getValue(msg, '|', 0);
    
    if (cmd.equals("OK")){
        show_page(1);
    }else if (cmd.equals("4")){
         SERVER_TIME = getValue(msg, '|', 1);

         if (CURRENT_PAGE == 1){
            strcpy(buffer, SERVER_TIME.c_str());        
            txtServerTime.setText(buffer);
         }
        
    }else if (cmd.equals("3")){                
        String json = getValue(msg, '|', 1);
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);

        String txid =  doc["txid"];        
        String amount =  doc["amount"];
        
        show_page(2);

        strcpy(buffer, txid.c_str()); 
        txtHash.setText(buffer);  

        strcpy(buffer, amount.c_str()); 
        txtAmount.setText(buffer);  

        millisReceiverPayment = millis();
        sound();
    }
}



void bannerScreenLoop(){
    int timeBase = 10000;

    long timeNowDiff = millis() - millisReceiverPayment;
    if(CURRENT_PAGE == 2){
        if (timeNowDiff < (timeBase * 1.5)){
            // Serial.println(timeNowDiff);
            // String i_str = String(15 - (timeNowDiff/1000));
            // const char* tempoReset = i_str.c_str();

            // strcpy(buffer, tempoReset); 
            // txtTempoReset.setText(buffer);
        }else{
            show_page(1);
        }        
    }
}