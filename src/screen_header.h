#include <Nextion.h>


const int SPEAKER = 32;
String TOKEN_QRCODE = "Xipy6LQYz8ELjtqGr9YEaZU5spid8K8tjx";
static unsigned long lastTimeDateCheck = 0;



char buffer[200] = {0};
int CURRENT_PAGE;
unsigned long millisInactivePayment = millis();
unsigned long millisReceiverPayment = millis();

String SERVER_TIME = "";


NexPage splashPage           = NexPage(0, 0, "splash");

NexPage qrcodePage           = NexPage(1, 0, "qrcode");
NexText txtQR                = NexText(1, 6, "qr0");
NexText txtServerTime        = NexText(1, 9, "t2");
NexText txtAddress           = NexText(1, 1, "t0");

NexPage successPage          = NexPage(2, 0, "success");
NexText txtAmount            = NexText(2, 8, "t1");
NexText txtHash              = NexText(2, 7, "qr0");
