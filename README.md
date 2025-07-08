# Fatigue Life Calculation Tool

## Overview

This repository contains a C++ console application designed to calculate the fatigue life of mechanical components, specifically utilizing the Goodman criterion. The tool takes into account various factors such as material properties (ultimate tensile strength, yield strength), surface finish, size, reliability, and stress concentration points to determine the factor of safety and predict whether a component will have infinite life under given loading conditions.

This code was developed as part of a Machine Design Project (MDPS352) focusing on the design and analysis of a 'FLY PRESS', and further extended with bonus tasks (MDPS355) related to Finite Element Analysis, code development, and prototyping.

## Features

- **Material Property Input**: Allows users to input ultimate tensile strength (Su) and yield strength (Sy).
- **Endurance Limit Calculation**: Calculates the estimated endurance limit (Se') based on material properties.
- **Modification Factors**: Incorporates surface finish factor (Ka), size factor (Kb), and reliability factor (Kc) to determine the modified endurance limit (Se).
- **Stress Concentration Analysis**: Accounts for stress concentration effects using theoretical stress concentration factor (Kt) and notch sensitivity (Qn) to calculate the fatigue stress concentration factor (Ke).
- **Loading Conditions**: Supports calculation for different loading scenarios:
    - Bar in tension or simple compression with a transverse hole.
    - Rectangular bar with a transverse hole in bending.
    - Notched rectangular bar in tension or simple compression.
- **Goodman Criterion**: Applies the Goodman fatigue criterion to determine the factor of safety (n).
- **Life Prediction**: Predicts if the component has infinite life based on the calculated factor of safety.

## Getting Started

### Prerequisites

To compile and run this application, you will need a C++ compiler (e.g., g++).

### Compilation

Navigate to the directory containing the `main.cpp` (or equivalent) file and compile using your C++ compiler:

```bash
g++ main.cpp -o fatigue_calculator -std=c++11 -lm
```

### Usage

Run the compiled executable from your terminal:

```bash
./fatigue_calculator
```

The program will then prompt you to enter the required parameters step-by-step:

1.  **Ultimate tensile strength (Su)** in MPa.
2.  **Yield strength (Sy)** in MPa.
3.  **Surface finish choice**: Select from Ground (1), Machined or cold-rolled (2), Hot-rolled (3), or As-forged (4).
4.  **Diameter (d)** in mm (enter 0 if not applicable).
5.  **Reliability (%)**: Enter 50, 90, 99, 99.9, 99.99, or 99.999 (enter 0 if not applicable).
6.  **Stress concentration point type**: Select Bar in tension/compression with transverse hole (1), Rectangular bar with transverse hole in bending (2), or Notched rectangular bar in tension/compression (3).
7.  **Theoretical stress concentration factor (Kt)**.
8.  **Notch sensitivity (Qn)**.

Depending on your choice for stress concentration point type, you will be prompted for additional parameters such as maximum/minimum force, maximum/minimum moment, thickness, width, hole diameter, or notch radius.

Finally, the program will output the calculated factor of safety (n) and indicate whether the part has infinite life.

## Project Context

This code is a component of a larger academic project:

-   **MDPS352 Project: FLY PRESS**: The primary machine design project involved the comprehensive design and analysis of a 'FLY PRESS'. This fatigue calculation tool was developed to support the structural integrity analysis of components within this machine.
-   **MDPS355 Bonus Tasks**: Further development included bonus tasks related to Finite Element Analysis (FEA) for more detailed stress analysis, additional code development, and the prototyping phase of the project.

## Team Members

-   Ahmed Mostafa Elsayed
-   Khaled Ayman Abdelazeem
-   Omar Sobhy Ellethy
-   Waleed Ashraf

## License

[Consider adding a license here, e.g., MIT, Apache 2.0, etc.]






live
