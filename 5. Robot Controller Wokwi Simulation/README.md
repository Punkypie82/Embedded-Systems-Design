# Robot Controller Wokwi Simulation

This project implements a gas detection robot controller with sensor integration, simulated using the Wokwi online electronics platform. The system demonstrates embedded control system design, sensor integration, and real-time decision making for hazardous gas detection and response.

## 📋 Project Overview

This module features:
- **Gas Detection System**: MQ-2 gas sensor integration for hazardous gas monitoring
- **Distance Measurement**: HC-SR04 ultrasonic sensor for obstacle detection
- **Motor Control**: Stepper motor control for robot movement
- **Stateflow Logic**: State machine-based decision making
- **Wokwi Simulation**: Complete virtual hardware simulation environment

## 📁 Files Description

### Simulink Models
- **`gas_detector_robot_controller.slx`**: Main Simulink model with Stateflow-based robot control logic

### Generated Code
- **`Controller_ert_rtw/`**: Embedded Real-Time (ERT) generated code directory
  - **`Controller.c/.h`**: Main controller implementation
  - **`ert_main.c`**: Entry point for embedded execution
  - **`rtwtypes.h`**: Data type definitions
  - Build and configuration files

### Circuit Documentation
- **`full_robot_circuit.png`**: Complete robot system circuit diagram
- **`hc_sr04_sensor_circuit.png`**: Ultrasonic sensor wiring diagram
- **`hc_sr04_sensor_test.png`**: Sensor testing setup
- **`mq2_sensor_circuit.png`**: Gas sensor wiring configuration
- **`mq2_sensor_test.png`**: Gas sensor testing setup
- **`mq2_sensor_calculation.png`**: Sensor calibration calculations
- **`stepper_motor_circuit.png`**: Motor control circuit
- **`robot_controller_stateflow_diagram.png`**: State machine visualization

### Simulation Links
- **`wokwi_links.txt`**: URLs to live Wokwi simulation projects for different configurations

### Project Files
- **`slprj/`**: Simulink project build artifacts and generated code

## 🎯 System Architecture

### Hardware Components
- **Arduino Uno**: Main microcontroller platform
- **MQ-2 Gas Sensor**: Detects combustible gases (LPG, propane, methane)
- **HC-SR04 Ultrasonic Sensor**: Measures distance to obstacles
- **28BYJ-48 Stepper Motor**: Provides precise movement control
- **ULN2003 Driver**: Stepper motor driver board
- **LEDs and Resistors**: Status indication
- **Breadboard and Jumper Wires**: Circuit connections

### Software Architecture
```
Robot Controller System
├── Sensor Input Layer
│   ├── MQ-2 Gas Sensor (Analog)
│   └── HC-SR04 Distance Sensor (Digital)
├── Control Logic Layer
│   ├── Stateflow State Machine
│   ├── Safety Threshold Monitoring
│   └── Decision Making Algorithm
└── Actuator Output Layer
    ├── Stepper Motor Control
    ├── Status LED Control
    └── Alert System
```

## 🚀 Getting Started

### Prerequisites
- MATLAB R2019a or later with Simulink
- Embedded Coder Toolbox
- Stateflow
- Arduino IDE (for manual code compilation)
- Web browser (for Wokwi simulation)

### Running Wokwi Simulations
1. Open the `wokwi_links.txt` file
2. Click on any of the provided simulation links:
   - **q03_a**: Basic gas detection
   - **q03_b**: Distance measurement integration
   - **q03_c**: Motor control implementation
   - **q03_d**: Complete system integration
   - **q03_e**: Advanced features and optimization

3. Interact with the virtual sensors in the Wokwi interface
4. Observe robot behavior and state transitions

### Running Simulink Model
1. Open MATLAB and navigate to this directory
2. Open the main model:
   ```matlab
   open('gas_detector_robot_controller.slx')
   ```
3. Configure simulation parameters
4. Run simulation to test control logic
5. Generate code for embedded deployment:
   ```matlab
   % Build model for target
   rtwbuild('gas_detector_robot_controller')
   ```

## 🔧 System Operation

### State Machine Logic
The robot operates using a Stateflow-based state machine:

#### States
1. **IDLE**: System initialization and standby
2. **MONITORING**: Continuous sensor data acquisition
3. **GAS_DETECTED**: Hazardous gas level detected
4. **APPROACHING**: Moving towards gas source
5. **EVACUATING**: Moving away from danger zone
6. **EMERGENCY**: Critical safety response

#### Transitions
- **Gas Level Threshold**: Triggers gas detection response
- **Distance Threshold**: Obstacle avoidance activation
- **Safety Timeout**: Emergency state activation
- **Manual Override**: User intervention capability

### Sensor Integration

#### MQ-2 Gas Sensor
- **Detection Range**: 200-10000 ppm
- **Response Time**: < 10 seconds
- **Calibration**: PPM = (Voltage - B) / A
- **Threshold**: Configurable safety limit

#### HC-SR04 Ultrasonic Sensor
- **Range**: 2cm - 400cm
- **Accuracy**: ±3mm
- **Update Rate**: 40Hz maximum
- **Calculation**: Distance = (Duration × 343m/s) / 2

### Motor Control
- **Type**: 28BYJ-48 5V Stepper Motor
- **Steps per Revolution**: 2048 (with gear reduction)
- **Control Method**: 4-wire unipolar drive
- **Speed Control**: Variable speed based on sensor input
- **Direction Control**: Forward/reverse/stop commands

## 📊 Performance Specifications

### Real-Time Performance
- **Sensor Sampling Rate**: 10 Hz
- **Control Loop Frequency**: 50 Hz
- **Response Time**: < 500ms for gas detection
- **Motor Response**: < 100ms for direction changes

### Safety Features
- **Gas Threshold Monitoring**: Continuous safety level checking
- **Obstacle Avoidance**: Automatic collision prevention
- **Emergency Stop**: Immediate system shutdown capability
- **Watchdog Timer**: System health monitoring
- **Fail-Safe Operation**: Safe state on system failure

## 🎓 Educational Objectives

This project demonstrates:
1. **Embedded System Design**: Complete system development workflow
2. **Sensor Integration**: Multi-sensor data fusion techniques
3. **Real-Time Control**: Time-critical system implementation
4. **State Machine Design**: Complex behavior modeling
5. **Hardware Simulation**: Virtual prototyping and testing
6. **Code Generation**: Model-to-code development process

## 🔍 Simulation Features

### Wokwi Platform Advantages
- **No Hardware Required**: Complete virtual environment
- **Real-Time Simulation**: Accurate timing behavior
- **Interactive Components**: Clickable sensors and controls
- **Code Debugging**: Built-in debugging tools
- **Sharing Capability**: Easy project sharing via links
- **Component Library**: Extensive parts catalog

### Virtual Testing Scenarios
1. **Gas Leak Detection**: Simulate various gas concentrations
2. **Obstacle Navigation**: Test collision avoidance algorithms
3. **Emergency Situations**: Validate safety response procedures
4. **Sensor Failures**: Test system robustness
5. **Performance Limits**: Stress testing under extreme conditions

## 🛠️ Circuit Implementation

### Power Supply
- **Voltage**: 5V DC from USB or external adapter
- **Current**: ~500mA total system consumption
- **Distribution**: Regulated power to all components
- **Protection**: Reverse polarity and overcurrent protection

### Signal Conditioning
- **Analog Inputs**: 10-bit ADC for gas sensor
- **Digital I/O**: GPIO pins for ultrasonic sensor
- **PWM Outputs**: Motor control signals
- **Pull-up Resistors**: Digital input conditioning

### Wiring Specifications
```
MQ-2 Gas Sensor:
- VCC → 5V
- GND → Ground  
- A0 → Arduino A0

HC-SR04 Ultrasonic:
- VCC → 5V
- GND → Ground
- Trig → Digital Pin 7
- Echo → Digital Pin 8

28BYJ-48 Stepper Motor:
- IN1 → Digital Pin 2
- IN2 → Digital Pin 3  
- IN3 → Digital Pin 4
- IN4 → Digital Pin 5
```

## 🔧 Advanced Features

### Adaptive Behavior
- **Learning Algorithm**: Adapts to environmental conditions
- **Threshold Adjustment**: Dynamic safety limit modification
- **Path Optimization**: Efficient navigation algorithms
- **Energy Management**: Power consumption optimization

### Communication Capabilities
- **Serial Communication**: Debug and monitoring interface
- **Wireless Options**: WiFi/Bluetooth integration potential
- **Data Logging**: Sensor data recording and analysis
- **Remote Control**: External command interface

## 📈 Performance Optimization

### Code Optimization
- **Fixed-Point Arithmetic**: Faster computation on microcontroller
- **Lookup Tables**: Pre-computed values for sensor calibration
- **Interrupt-Driven I/O**: Efficient sensor data acquisition
- **Memory Management**: Optimized RAM usage

### Algorithm Efficiency
- **Sensor Fusion**: Kalman filtering for improved accuracy
- **Predictive Control**: Anticipatory behavior algorithms
- **Path Planning**: Optimal route calculation
- **Resource Scheduling**: Efficient task management

## 🔍 Troubleshooting

### Common Issues
1. **Sensor Calibration**: Ensure proper sensor calibration
2. **Power Supply**: Check voltage levels and current capacity
3. **Wiring Connections**: Verify all connections are secure
4. **Code Upload**: Ensure correct board and port selection
5. **Simulation Lag**: Check internet connection for Wokwi

### Debug Strategies
- **Serial Monitor**: Use for real-time debugging output
- **LED Indicators**: Visual status indication
- **Wokwi Debugger**: Step-through code execution
- **Logic Analyzer**: Signal timing analysis
- **Oscilloscope**: Analog signal inspection

## 📚 Extensions and Improvements

### Hardware Enhancements
1. **Additional Sensors**: Temperature, humidity, pressure
2. **Better Actuators**: Servo motors, DC motors with encoders
3. **Communication Modules**: WiFi, Bluetooth, LoRa
4. **Display Interface**: LCD or OLED status display
5. **GPS Integration**: Location-aware functionality

### Software Improvements
1. **Machine Learning**: AI-based decision making
2. **Cloud Integration**: IoT connectivity and data analytics
3. **Mobile App**: Smartphone control interface
4. **Web Dashboard**: Real-time monitoring interface
5. **Predictive Maintenance**: System health prediction

## 📖 References

1. Arduino Programming Reference - Arduino.cc
2. MQ-2 Gas Sensor Datasheet - Hanwei Electronics
3. HC-SR04 Ultrasonic Sensor Manual - Cytron Technologies
4. Wokwi Documentation - docs.wokwi.com
5. Embedded Systems Design - Steve Heath

---

*This project provides hands-on experience in embedded system design, sensor integration, and virtual hardware simulation, essential skills for modern robotics and IoT applications.*