// 1. 引入WIFI
#include "WiFi.h"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin("turbo0306-2.4G","0229450018");
  //顯示連接狀態
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  


}

void loop()
{
  // put your main code here, to run repeatedly:
}
