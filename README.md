# Design and Implementation of DC- DC Boost Converter with High Step Up Ratio

## Project Overview
This repository contains the simulation models and documentation for a high step-up DC-DC converter designed for renewable energy systems. [cite_start]Conventional boost converters suffer from severe conduction losses and voltage stress at extreme duty ratios[cite: 52]. [cite_start]To mitigate this, this project integrates a coupled inductor and an auxiliary active-clamp resonant circuit to mathematically guarantee Zero Voltage Switching (ZVS) for the main switch and Zero Current Switching (ZCS) for the auxiliary switch[cite: 53, 54].

## System Specifications
* [cite_start]**Input Voltage:** 24 V [cite: 356]
* [cite_start]**Output Voltage:** 120 V [cite: 357]
* [cite_start]**Rated Power:** 100 W [cite: 358]
* [cite_start]**Switching Frequency:** 25 kHz [cite: 359]

## Tools & Hardware
* [cite_start]**Simulation:** MATLAB Simulink (Open-loop and Closed-loop PI control) [cite: 59]
* [cite_start]**Control Circuitry:** Arduino Microcontroller [cite: 242]
* [cite_start]**Gate Driver:** TC4427 high-speed driver IC [cite: 95]
* [cite_start]**Magnetic Components:** Custom manually wound coupled inductor using an E 36/18/11 Ferrite Core (20-22 AWG copper enameled wire) [cite: 403, 438]

## Files Included
*(Upload your .slx Simulink files, Arduino code, and project PDF here)*
