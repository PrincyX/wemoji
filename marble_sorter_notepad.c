/* Marble Sorter using NXT
IET Final Project
Made by Rajdeep Singh
*/

#define THRESHOLD 45 //defines the threshold between a dark and light marble

// Define Variables

int control_motor; // Motor that releases the ball
int aim_motor;     // Motor that diverts the path of the marbles
int cooldown;      // Cooldown, a period of complete stillness -- to make sure the laws of physics takes place
int ramp_id;		// A unique way for identifying the two seperate paths of that ramp.
                //IMPORTANT: 100 = Light Marble Ramp Config., 1 = Dark Marble Ramp Config.
int ralmotsp;
int rampmove;
/*
---------------------------------MAIN PROGRAM-----------------------------------
Motor B --> Marble Regulator
Motor A --> Ramp initializer for light colored marble
Motor C --> Ramp initializer for dark colored marbles
*/

task main(){

     // Initialize Variables
     ramp_id = 100; //initialize ramp to light
     control_motor = 250; //change this accordingly
     aim_motor = 550;     //change thiss accordingly
     cooldown = 2000;     //change this accordingly
     ralmotsp = 100;
     rampmove = 100;
     SetSensorLight(IN_1); // initialize light sensor
     
     repeat(20) // repeats all the code below 10 times (x10 marbles to be sorted)
     {
     // RAMP TO LIGHT COLORED MARBLE BIN         +
      if (Sensor(IN_1) > THRESHOLD && ramp_id == 100){
         TextOut(0, LCD_LINE1, "white"); // prints out the color of the marble sensed
         TextOut(0, LCD_LINE2, THRESHOLD);
         // Release the marble
         OnFwd(OUT_B, ralmotsp);
         Wait(200);
         Off(OUT_B);
         Wait(cooldown);
         ramp_id = 100; //initialized the ramp's position to light marble BIN
         }
      else if (Sensor(IN_1) > THRESHOLD && ramp_id != 100){
           TextOut(0, LCD_LINE1, "white s"); // prints out the color of the marble sensed
           TextOut(0, LCD_LINE2, THRESHOLD);
           // Change the ramp to the right BIN
              //move c motor out
           OnRev(OUT_C, 100);
           Wait(rampmove);
           Off(OUT_C);
           Wait(cooldown);
           //move a motor in
           OnFwd(OUT_A, 100);
           Wait(rampmove);
           Off(OUT_A);
           Wait(cooldown);
           ramp_id = 100; //initialized the ramp's position to light marble BIN
           // Release the marble
         OnFwd(OUT_B, ralmotsp);
         Wait(200);
         Off(OUT_B);
         Wait(cooldown);
      }
      // RAMP TO DARK COLORED MARBLE BIN
      else if (Sensor(IN_1) <= THRESHOLD && ramp_id != 1){
           TextOut(0, LCD_LINE1, "black s"); // prints out the color of the marble sensed
           TextOut(0, LCD_LINE2, THRESHOLD);
           // Change the ramp to the BIN
              //move a motor out
           OnRev(OUT_A, 100);
           Wait(200);
           Off(OUT_A);
           Wait(cooldown);
           //move C motor in
           OnFwd(OUT_C, 100);
           Wait(rampmove);
           Off(OUT_C);
           Wait(cooldown);
           ramp_id = 1;//initialized the ramp's position to dark marble BIN
           // Release the marble
         OnFwd(OUT_B, ralmotsp);
         Wait(control_motor);
         Off(OUT_B);
         Wait(cooldown);
		   }
      else if (Sensor(IN_1) <= THRESHOLD && ramp_id = 1){
         TextOut(0, LCD_LINE1, "black"); // prints out the color of the marble sensed
         TextOut(0, LCD_LINE2, THRESHOLD);
         // Release the marble
         OnFwd(OUT_B, ralmotsp);
         Wait(control_motor);
         Off(OUT_B);
         Wait(cooldown);
         ramp_id = 1;//initialized the ramp's position to dark marble BIN
         }
		// If an unexpected error occurs,
      else{
         TextOut(0, LCD_LINE1, "AN ERROR OCCURED. MARBLE RELEASED RAMDOMLY");
         TextOut(0, LCD_LINE2, THRESHOLD);
         // Releases the marble randomly (something that we don't want to do)
         OnFwd(OUT_B, ralmotsp);
         Wait(control_motor);
         Off(OUT_B);
         Wait(cooldown);
      }
     }
}
