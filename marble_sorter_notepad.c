/* Marble Sorter using NXT
IET Final Project
Made by Rajdeep Singh
*/

#define THRESHOLD 40 //defines the threshold between a dark and light marble

// Define Variables

int control_motor; // Motor that releases the ball
int aim_motor;     // Motor that diverts the path of the marbles
int cooldown;      // Cooldown, a period of complete stillness -- to make sure the laws of physics takes place
int ramp_id;		// A unique way for identifying the two seperate paths of that ramp.
                //IMPORTANT: 100 = Light Marble Ramp, 1 = Dark Marble Ramp

/*
---------------------------------MAIN PROGRAM-----------------------------------

Motor B --> Marble Regulator
Motor A --> Ramp initializer for light colored marble
Motor C --> Ramp initializer for light colored marble
*/

task main(){
     ramp_id = 1;
     control_motor = 1000; //change this accordingly
     aim_motor = 1000;     //change this accordingly
     cooldown = 1000;     //change this accordingly
     SetSensorLight(IN_1); // initialize light sensor
     repeat(10) // repeats all the code below 10 times (x10 marbles to be sorted)
     {
     // RAMP TO LIGHT COLORED MARBLE BIN
      if (Sensor(IN_1) > THRESHOLD && ramp_id == 100){
         TextOut(0, LCD_LINE1, "white"); // prints out the color of the marble sensed
         // Release the marble
         OnFwd(OUT_B, 75);
         Wait(control_motor);
         Off(OUT_B);
         Wait(cooldown);
         ramp_id = 100; //initialized the ramp's position to light marble BIN
         }
      else if (Sensor(IN_1) > THRESHOLD && ramp_id != 100){
           TextOut(0, LCD_LINE1, "white s"); // prints out the color of the marble sensed
           // Change the ramp to the right BIN
           OnFwd(OUT_A, 75);
           Wait(aim_motor);
           Off(OUT_A);
           Wait(cooldown);
           ramp_id = 100; //initialized the ramp's position to light marble BIN
      }
      // RAMP TO DARK COLORED MARBLE BIN
      else if (Sensor(IN_1) <= THRESHOLD && ramp_id != 1){
           TextOut(0, LCD_LINE1, "black s"); // prints out the color of the marble sensed
           // Change the ramp to the right BIN
           OnFwd(OUT_C, 75);
           Wait(aim_motor);
           Off(OUT_C);
           Wait(cooldown);
           ramp_id = 1;//initialized the ramp's position to dark marble BIN
		   }
      else if (Sensor(IN_1) <= THRESHOLD && ramp_id = 1){
         TextOut(0, LCD_LINE1, "black"); // prints out the color of the marble sensed
         // Release the marble
         OnFwd(OUT_B, 75);
         Wait(control_motor);
         Off(OUT_B);
         Wait(cooldown);
         ramp_id = 1;//initialized the ramp's position to dark marble BIN
         }
		// If everthing else fails,
      else{
           TextOut(0, LCD_LINE1, "AN ERROR OCCURED. MARBLE RELEASED RAMDOMLY");
           // Releases the marble randomly (something that we don't want to do)
           OnFwd(OUT_B, 75);
           Wait(control_motor);
           Off(OUT_B);
           Wait(cooldown);
      }
     }
}
