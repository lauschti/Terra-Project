DEMO:
https://wokwi.com/projects/477422322800369665

💣 Bomb Defusal Game (Work in Progress)

An interactive Arduino puzzle game inspired by Keep Talking and Nobody Explodes. The goal is to defuse various modules by finding the correct combination of switches, potentiometers, and buttons.

⚠️ Current Game Status: The project is still under active development, but the current version is fully playable!


🎮 What Works (Playable Modules)

•	Module 1 (Potentiometer): Validates analog input values against target ranges.

•	Module 2 (Toggle Switches): Checks for a specific switch combination.

•	Module 4 (Push Buttons): Distinguishes between the correct and incorrect button.

•	Module 5 (Secret Module): Checks a hidden toggle switch combination.

•	Error Tracking & Feedback:

o	Status LED gives visual feedback for correct/incorrect inputs.

o	Incorrect attempts increment the internal error counter (fehler).


🔑 Solution / How to Defuse

Module	Pin / Input	Target State / Solution

Module 1 (Poti)	Button D2	All 3 Potentiometers (A1, A2, A3) set between 20 and 30

Module 2 (Toggle)	Button D3	Pins 4–7: 4=LOW, 5=HIGH, 6=LOW, 7=LOW

Module 4 (Buttons)	Button D8 vs D9	Press D8 for Correct / D9 triggers Error

Module 5 (Secret)	Button D12	Pins 10–11: 10=LOW, 11=HIGH


⏳ Work in Progress / Planned Features

•	Keypad & Cable Modules: Hardware pins are initialized; reading logic will be added next.

•	Game Over Logic: Triggering a defusal failure after reaching 3 errors.

•	Display / Timer: Adding a digital countdown display.


🛠️ Hardware Requirements

•	Microcontroller: Arduino Mega 2560 (due to high pin count)

•	Inputs: 6× Toggle Switches, 5× Push Buttons, 3× Potentiometers, 1× Keypad (4x4)

•	Outputs: Status LEDs (Green / Red)


🚀 How to Run
1.	Upload the code to your Arduino Mega (or set up a simulation on Wokwi).
2.	Open the Serial Monitor at 9600 baud.
3.	Set the switches/potis according to the solution table, then press the corresponding module button (D2, D3, D8, D12) to check your answer.
