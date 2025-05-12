# Smart Parking: An IoT Based Solution for Smart University

This project is a Smart University Parking Management System designed to efficiently manage parking spaces on a university campus. The system aims to reduce congestion, enhance user experience, and ensure optimal utilization of parking slots. It leverages IoT components and integrates seamlessly with the Blynk platform to provide real-time parking slot availability.
## Table of Contents

- [Components](#components)
- [System Overview](#system-overview)
- [Installation](#installation)
- [How It Works](#how-it-works)
- [Blynk Web Dashboard](#blynk-web-dashboard)
- [License](#license)
- [Contributing](#contributing)

## Components

- NodeMCU ESP8266
- IR Sensors
- Servo Motors
- Jumper Wires
- Breadboard
- USB Cable
- Toy Cars (for simulation)
- LCD Display 16x2
- Plywood Board Sheets (for model setup)
- Others

## System Overview

The Smart University Parking Management System automates the process of parking management by using IR sensors and NodeMCU ESP8266 microcontrollers. The system is designed to:
1. Automatically open and close the entry and exit gates based on the availability of parking slots.
2. Display the parking slot status on an LCD screen at the parking entrance.
3. Update parking slot availability in real-time on a web dashboard and mobile application via the Blynk platform.

## Installation

### Prerequisites

1. Arduino IDE
2. Blynk Library (Install via Arduino Library Manager)
3. NodeMCU ESP8266 Drivers

### Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/your-username/smart-university-parking.git
   cd smart-university-parking
   ```

2. **Upload the Code**
   - Connect the NodeMCU ESP8266 to your computer using a USB cable.
   - Open the Arduino IDE and load the provided `.ino` file.
   - Select the correct board (NodeMCU 1.0) and port.
   - Upload the code to the NodeMCU.

3. **Set Up the Hardware**
   - Connect the IR sensors, servo motors, and LCD display to the NodeMCU as per the wiring diagram provided in the repository.
   - Assemble the physical model using plywood sheets to simulate the parking area.

4. **Configure Blynk**
   - Register on the Blynk platform and create a new project.
   - Set up the web dashboard and mobile application as described in the Blynk section.

## How It Works

1. **Entry Gate Operation**
   - When a car approaches the entry gate, the IR sensor detects the vehicle.
   - If a parking slot is available, the servo motor opens the gate.
   - The NodeMCU updates the status of the slot to "FULL" once the car is parked.

2. **Parking Slot Detection**
   - Each parking slot has an IR sensor that detects whether the slot is occupied.
   - The NodeMCU receives signals from the IR sensors and updates the parking status in real-time.

3. **Exit Gate Operation**
   - As a car leaves the parking area, the IR sensor at the exit detects it.
   - The slot status is updated to "EMPTY," and the exit gate opens automatically.

4. **LCD Display**
   - The LCD display at the entrance shows whether the parking area is "FULL" or has "EMPTY" slots available.

5. **Parking Slot Full Condition**
   - If all slots are full, the entry gate will remain closed, and the user must wait or find another parking area.

## Blynk Web Dashboard

The Blynk platform provides a web dashboard and mobile application where users can:

- View real-time status of each parking slot.
- Monitor the availability of parking spaces.
- Receive notifications about parking slot status changes.

### Steps to Set Up Blynk

1. Register on the Blynk platform.
2. Create a new project and obtain the Auth Token.
3. Set up widgets on the Blynk web dashboard to monitor each parking slot.
4. Use the Blynk mobile application to remotely monitor the parking status.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open an Issue to discuss potential changes.
