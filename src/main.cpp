/*
 * @Author: leo-windows lion24161582@gmail.com
 * @Date: 2023-07-21 13:27:44
 * @LastEditors: leo-windows lion24161582@gmail.com
 * @LastEditTime: 2023-07-22 16:14:33
 * @FilePath: \CH4_Interruptc:\Users\Leo\Documents\PlatformIO\Projects\CH6_WIFI_IOT\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 1. 引入WIFIAP函數庫
#include "WiFi.h"
#include "WebServer.h"
// 引入伺服器port
WebServer sever(80);
const char *ssid = "turbo0306-2.4G" ; 
const char *password = "0229450018" ; 

void handleRoot(){
  String HTML = "<!DOCTYPE html > \
                  <html>\
                    <head>\
                    <meta charset='utf-8'> \
                    </head>\
                      <body>慢慢長路，總要從第一步開始</body>\
                  </html>";

  sever.send(200,"text/html",HTML) ; 
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  // 設定軟體基地台
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid,password);
  // 判斷是否連線
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".") ; 
  }
  
  // 顯示當前地址
  Serial.print("WIFI ADDRESS");
  Serial.println(WiFi.localIP()); ; 

  // 設定伺服器
  sever.on("/",handleRoot); 
  sever.on("/about",[](){
    sever.send(200,"text/html","我是Leo開發的喔");
  });

  sever.onNotFound([](){
  sever.send(404,"text/html","不能載入HTML喔 請檢察問題") ; 
  });

  sever.begin();

  
}

void loop()
{
  // put your main code here, to run repeatedly:
  sever.handleClient() ; 
}
