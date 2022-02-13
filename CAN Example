#include <mcp_can.h>
#include <SPI.h>

#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
    #define SERIAL SerialUSB
#else
    #define SERIAL Serial
#endif

MCP_CAN CAN0(53); // Set CS to pin 53

unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];

void setup()
{
  Serial.begin(1000000);
  START_INIT:

  // Initialize MCP2515 running at 16MHz with a baudrate of 1000kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_1000KBPS, MCP_16MHZ) == CAN_OK) 
      Serial.println("MCP2515 Initialized Successfully!");
  else{ 
       Serial.println("Error Initializing MCP2515...");
       Serial.println("Init CAN BUS Shield again");
       delay(100);
       goto START_INIT;
  }
  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}
 

void loop()
{
    buf[0] = 0x7F;
    buf[1] = 0xFF;
    buf[2] = 0x8E;
    buf[3] = 0x30;
    buf[4] = 0x08;
    buf[5] = 0x33;    // 0 deg for big m
    buf[6] = 0x38; 
    buf[7] = 0x71;
  
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  CAN0.sendMsgBuf(0x01, 0, 8, buf);
  CAN0.sendMsgBuf(0x02, 0, 8, buf);
  CAN0.sendMsgBuf(0x03, 0, 8, buf);
  CAN0.sendMsgBuf(0x04, 0, 8, buf);
  CAN0.sendMsgBuf(0x05, 0, 8, buf);
  CAN0.sendMsgBuf(0x06, 0, 8, buf);
  delay(5000);   // send data per 5000ms

    buf[0] = 0xEE;
    buf[1] = 0x65;
    buf[2] = 0x8E;
    buf[3] = 0x30;
    buf[4] = 0x08;
    buf[5] = 0x33;    
    buf[6] = 0x38; 
    buf[7] = 0x71;

  CAN0.sendMsgBuf(0x01, 0, 8, buf);
  CAN0.sendMsgBuf(0x02, 0, 8, buf);
  CAN0.sendMsgBuf(0x03, 0, 8, buf);
  CAN0.sendMsgBuf(0x04, 0, 8, buf);
  CAN0.sendMsgBuf(0x05, 0, 8, buf);
  CAN0.sendMsgBuf(0x06, 0, 8, buf);
  delay(3000);
  
}
