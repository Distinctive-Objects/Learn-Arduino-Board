/***************************************************
  DFPlayer - A Mini MP3 Player For Arduino
  <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
  This example shows the all the function of library for DFPlayer.

  Created 2016-12-07
  By [Angelo qiao](Angelo.qiao@dfrobot.com)

  GNU Lesser General Public License.
  See <http://www.gnu.org/licenses/> for details.
  All above must be included in any redistribution
 ****************************************************/


#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini myDFPlayer;

char Choice;
int paused = 0;

void setup()
{
  //Establish the pins which will be used for Serial communication
  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);  // speed, type, RX, TX
  //Start the communication with the microcontroller
  Serial.begin(115200);
  
  // DFPlayer tends to take 3-5 seconds to startup - a quick note to remind you
  Serial.println();
  Serial.println(F("Initializing DFPlayer module ... Wait 3-5 seconds!"));

  //The following routine tells us whether serial communication is established.  It will not proceed until communication has been established.

  if (!myDFPlayer.begin(mySoftwareSerial))  
  {
    Serial.println(F("Player not functioning:"));
    Serial.println(F("1. Check the DFPlayer Mini connections"));
    Serial.println(F("2. Insert an SD card"));
    while (true);
  }

  Serial.println();
  Serial.println(F("DFPlayer now ready"));

 // This sets the intial parameters for the player
  myDFPlayer.setTimeOut(500); //Timeout serial 500ms
  myDFPlayer.volume(10); //Volume (0-30)
  myDFPlayer.EQ(0); //Standard equaliser setup
  menu_update();//displays the player menu choices
}

void loop()
{

  //Waits for data entry via serial
  while (Serial.available() > 0)
  {
    Choice = Serial.read();

    if ((Choice >= '1') && (Choice <= '9'))
    {
      Serial.print("Play Track No.");
      Serial.print(Choice);
      Choice = Choice - 48;
      myDFPlayer.play(Choice);
      menu_update();
    }

    //Reproduction
    //Stop

    if (Choice == 's')
    {
      myDFPlayer.stop();
      Serial.println("Music Stopped!");
      menu_update();
    }

    //Pause or continue the music
    if (Choice == 'p')
    {
      paused = !paused;

      if (paused == 0)
      {
        Serial.println("Continue...");
        myDFPlayer.start();
      }

      if (paused == 1)
      {
        Serial.println("Music Paused!");
        myDFPlayer.pause();
      }

      menu_update();
    }


    //Increases volume
    if (Choice == '+')
    {
      myDFPlayer.volumeUp();
      Serial.print("Current volume:");
      Serial.println(myDFPlayer.readVolume());
      menu_update();
    }

    if (Choice == '<')
    {
      myDFPlayer.previous();
      Serial.println("Previous:");
      Serial.print("Current track:");
      Serial.println(myDFPlayer.readCurrentFileNumber() - 1);
      menu_update();
    }

    if (Choice == '>')
    {
      myDFPlayer.next();
      Serial.println("next:");
      Serial.print("Current track:");
      Serial.println(myDFPlayer.readCurrentFileNumber() + 1);
      menu_update();
    }

    //Decreases volume
    if (Choice == '-')
    {
      myDFPlayer.volumeDown();
      Serial.print("Current Volume:");
      Serial.println(myDFPlayer.readVolume());
      menu_update();
    }

  }


}

void menu_update() {
  Serial.println();
  Serial.println(F("=================================================================================================================================="));
  Serial.println(F("Commands:"));
  Serial.println(F(" [1-3] To select the MP3 file"));
  Serial.println(F(" [s] stopping reproduction"));
  Serial.println(F(" [p] pause/continue music"));
  Serial.println(F(" [+ or -] increases or decreases the volume"));
  Serial.println(F(" [< or >] forwards or backwards the track"));
  Serial.println();
  Serial.println(F("================================================================================================================================="));
}
