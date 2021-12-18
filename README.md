# Serial Geiger
Simple arduino translator for J305 based geiger counters (For example: RadiationD v1.1 Cajoe)

## Table of contents
- What is SerialGeiger?
- Why would you want to use SerialGeiger?
- How do I set it up?
- How does it work?
- What are the output units?

## What is SerialGeiger?

SerialGeiger is a VERY simple interface for your Arduino to
a Geiger Counter equipped with a J305ß Geiger Müller tube.
It converts the counts per minute of the Counter to Microsieverts/h.

## Why would you want to use SerialGeiger?

To have a very simple and modifiable interface to your home-made or cheaply
purchased GeigerCounter without using an OLED display.

## How do I set it up?

Flash the included Platform.IO project to your Arduino and connect the output pin of
your Geiger counter to an ISR Pin on your Arduino. (In this case it's PIN 2 on the Mega2560)

## How does it work?

The program waits for falling edge voltages on the ISR pin and counts the clicks like that.
Then the CPM (Counts per minute) get converted to uSv/h.

## What are the output units?

The output units are:
- Microsievert per hour
- Counts per Minute
