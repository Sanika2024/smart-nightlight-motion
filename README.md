# Smart Nightlight Motion System (Tinkercad + Arduino)
A motion-activated smart lighting prototype built on Tinkercad using Arduino Uno, PIR sensor, and slide switch.  
- Lights remain OFF during daytime.  
- At night: lights stay DIM to save power.  
- On motion detection: lights turn FULL BRIGHT for 5 seconds, then return to dim.  
- Demonstrates power saving using duty cycle analysis.   

# Tools & Components
- Arduino Uno  
- PIR Sensor  
- LDR / Slide Switch (time-based control)  
- LEDs (PWM)  
- Tinkercad Simulator  

## How to Run
1. Open [Tinkercad](https://www.tinkercad.com).  
2. Create a new Arduino simulation.  
3. Connect PIR, slide switch, and LEDs as per circuit diagram.  
4. Upload Smart_Lighting.ino into Arduino IDE block.  
5. Run simulation and check Serial Monitor.  