Smart Shopping Cart  
====================  

The Smart Shopping Cart is an innovative project designed to revolutionize the shopping experience by automating product selection using embedded systems and robotics. This repository contains everything you need to build, program, and operate the Smart Shopping Cart.  

--------------------------------------------------------------------------------

Overview  
========  

The Smart Shopping Cart comprises three main components:  

1. User Interface Module  
   - Components: OLED Display, Arduino UNO R3, Push Buttons.  
   - Functionality:  
     - Displays the shopping mart's product list on the OLED display.  
     - Navigate through the product list using buttons (Up, Down, Select).  
     - Finalize the shopping list and send it to the Line-Follower module.  

2. Line-Follower with RFID Reader Module  
   - Components: IR Sensors, RFID Reader, Arduino UNO R3, L298N Motor Driver, BO Motors.  
   - Functionality:  
     - Guides the cart along a pre-defined path using IR sensors.  
     - Reads RFID tags near products and matches them with the shopping list.  
     - Signals the Robotic Arm module to pick up the identified product.  

3. Robotic Arm Module (Under Development)  
   - Components: Servo Motors, Arduino UNO R3.  
   - Functionality:  
     - Picks up and places products into the cart when signaled by the Line-Follower module.  

--------------------------------------------------------------------------------

Files in the Repository  
=======================  

1. adafruit_ssd1306_cart.ino  
   - Manages the User Interface, including the OLED display and button interactions for product selection.  

2. Interface-Line-RFID_Code.ino  
   - Controls the cart’s movement, IR sensors, and RFID reader for product identification.  

3. RFID-read_and_save.ino  
   - Detects and logs RFID values to replace with your project’s RFID codes.  

4. Robo_Arm_Test.ino  
   - Controls the robotic arm for picking and placing products. (Connections with the cart Arduino are pending.)  

--------------------------------------------------------------------------------

Hardware Setup  
==============  

- Connections: Refer to port declarations in each code file for detailed wiring instructions.  
- Assemble the hardware as described in the overview and ensure proper connections for smooth operation.  

--------------------------------------------------------------------------------

How to Run the Project  
======================  

1. Prepare the Hardware:  
   - Assemble the User Interface, Line-Follower module, and Robotic Arm module.  
   - Connect the components as specified in the code.  

2. Upload the Code:  
   - Upload the `.ino` files to the respective Arduino boards:  
     - User Interface: adafruit_ssd1306_cart.ino  
     - Line-Follower: Interface-Line-RFID_Code.ino  
     - RFID Setup: RFID-read_and_save.ino  
     - Robotic Arm: Robo_Arm_Test.ino  

3. Start the System:  
   - Power on the system.  
   - Use the User Interface to create a shopping list.  
   - Let the cart navigate and pick up products automatically!  

--------------------------------------------------------------------------------

Current Status  
==============  

- Working:  
  - User Interface Module.  
  - Line-Follower with RFID Reader Module.  
  - Robotic Arm (independent operation).  

- Under Development:  
  - Communication between the Cart Arduino and Robotic Arm Arduino.  
  - Expected update: few weeks.  

--------------------------------------------------------------------------------

Contributions and Feedback  
==========================  

Contributions, suggestions, and improvements are always welcome!  
Feel free to contact me: muralikrishna.professional1@gmail.com  

--------------------------------------------------------------------------------

License  
=======  

This project is open-source. Feel free to use, modify, and share it with proper attribution.  

Happy Building!  
