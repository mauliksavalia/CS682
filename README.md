# Project 6: Smart Recharging Platform for Drones and Ultracapacitors

**Code Documentation:** [SensorAndML-Documentation](https://mauliksavalia.github.io/SensorAndML-Documentation/index.html)

## Problem Statement
Develop an integrated electro-mechanical system that combines circuitry, electronics, communication, and programming skills to manage and automate the process of exchanging batteries in a drone. The system must be capable of signaling the drone when it is ready to receive a new battery, safely releasing and retrieving the spent battery upon the drone's landing, charging the retrieved battery, and replacing it with a fully charged one.

## Introduction
We've developed a unique system for automated drone battery management, integrating piezoelectric pressure sensors, IR sensors, current and voltage sensors, along with machine learning. This system automates battery swapping and charging, ensuring efficient and reliable drone operation. We're excited to demonstrate how this project works.

**Videos of Sensors Working:** [Google Drive Link](https://drive.google.com/drive/folders/1AxMasG1DAn7S7FXbqJBiqWYhx8WE8ldV?usp=share_link)

## How IR and Piezo Sensors Work Integrated
In our project, we are going to use 2 IR and 2 Piezo Sensors Integrated with an LCD display where it is activated when all 4 sensors are activated simultaneously. For this use the file: `IRSensors/2IRand2PiezoSensorsWithLCD.ino`.

### Steps:
1. Connect 2 IR sensors, 2 Piezo Electric sensors, and a 20x4 LCD to the Arduino board.
2. Upload this program to the Arduino board.
3. Open the Serial Monitor to view real-time messages.
4. Observe messages displayed on the connected 20x4 LCD when pressure is detected.

## How Voltage Sensor Works
In our Project, we are going to use a Voltage sensor with an LCD display. For the Voltage Sensor, use this file: `Display_T1/Display_T1.ino`.

### Steps:
1. Connect the voltage divider circuit and 20x4 LCD to the Arduino board.
2. Upload this program to the Arduino board.
3. Open the Serial Monitor to view real-time voltage measurements.
4. Observe voltage displayed on the connected 20x4 LCD.

## How Current Sensor Works
We are going to use a Current sensor with an LCD display. For the Current Sensor, use this file: `Display_Power_T2/Display_Power_T2.ino`.

### Steps:
1. Connect the INA219 sensor and 20x4 LCD to the Arduino board.
2. Upload this program to the Arduino board.
3. Open the Serial Monitor to view real-time data.
4. Observe data displayed on the connected 20x4 LCD.

## Machine Learning
In Machine Learning, use these files: `CS682_Battery_Recharging_ML.ipynb`, `synthetic_data_5.csv`. In ML, we are going to make a prediction to find the State of Health (SOH) using the data of Battery Capacity.

### Steps:
1. Load data from a CSV file containing synthetic battery data.
2. Define input features (Capacity) and target variable (SOH).
3. Normalize the data using Min-Max scaling.
4. Split the data into training and testing sets.
5. Reshape the data for LSTM input.
6. Build an LSTM model with one LSTM layer and a linear output layer.
7. Compile and train the model on the training data.
8. Evaluate the model on the testing data and print the test loss.
9. Make predictions using the trained model.
10. Inverse transform the predictions and true values to the original scale.
11. Visualize the true and predicted SOH values using a scatter plot.

---

