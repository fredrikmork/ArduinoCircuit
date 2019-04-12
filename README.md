# ArduinoCircuit
1. Initially, the system is in the LOCKED🔒 The red LED is on when the system is in a LOCKED state.  
2. When motion is detected, the yellow LED must be switched on; and the system is in a state WAITING for:  
      The user to do two pushes on the buttons. After each push, the yellow LED should blink shortly.  
3. If the order it correct, then system will become UNLOCKED🔓, and the green LED is switched on.  
4. If the order it not correct, the red LED should blink and the system will go back to a LOCKED state.
5. After a certain amount of time in the UNLOCKED state, the system should automatically enter the LOCKED state.
6. (Not yet implemented)If a user is idle for x seconds, the system will go back to LOCKED state.
