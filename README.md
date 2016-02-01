# poseiduino

Let's build a submarine! In a bottle.

Read my diary at https://github.com/poseiduino/poseiduino/wiki 

# The vision

We send a small submarine underwater, it stays their for a while, takes some data and returns to the surface.

We need a plastic bottle, an arduino, a motor, a servo, and some sensors.

## The Process 

- Set elevator to go down
- Start motor. The ship goes underwater. 
- Stop motor.
- Take data.
- Set elevator to go up again.
- Start motor
- Wait for connected to USB to print data to Serial.

[[https://github.com/poseiduino/poseiduino/wiki/images/poseiduino_dive_sketch.jpg]]
 
## The Laboratory /  The Experiments

I started with very basic experiments: investigating sensors (photoresistor), send data to thingspeak.com <http://www.thingspeak.com> (or a self-hosted instance), analyzing data, ... 

Find a demo and download the results: https://thingspeak.com/channels/81896

## Construction

Done so far: I started soldering my own shields instead of using breadboards. I could minimize the photoresistor setting to a 4x4 dot square. Plan of the circuits follow ...     

Thinking about the bottle ...

## My Setting

* NanoESP - Arduino Nano compatible board with wifi: http://iot.fkainka.de/
* Arduino Uno
* Raspberry Pi

## Code

Sketches and skripts are slightly revised or combined copies from other tutorials, mainly from arduino.cc . 
Compare for NanoESP and Thingspeak: http://iot.fkainka.de/day-19

## Related Github Projects

* Thingspeak: https://github.com/iobridge/ThingSpeak
* PySerial: https://github.com/pyserial/pyserial
