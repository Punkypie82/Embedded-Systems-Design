# Hierarchical and Composite Models

This project demonstrates advanced Simulink modeling techniques including hierarchical subsystems, composite models, and Synchronous Data Flow (SDF) graph implementations. The project showcases model organization, reusability, and efficient system design practices.

## 📋 Project Overview

This module focuses on:
- **Hierarchical Modeling**: Multi-level system decomposition
- **Composite Models**: Reusable model components
- **SDF Graphs**: Synchronous data flow implementation
- **Model Organization**: Best practices for complex systems
- **Code Generation**: From high-level models to C implementation

## 📁 Files Description

### Simulink Models
- **`hierarchical_model.slx`**: Demonstrates hierarchical subsystem design with multiple levels of abstraction
- **`composite_model.slx`**: Shows composite modeling techniques and component reusability

### C Implementation
- **`sdf_graph_implementation.c`**: Complete C implementation of a Synchronous Data Flow graph with token-based execution

### Documentation
- **`sdf_graph.png`**: Visual representation of the SDF graph structure and data flow

### Generated Files
- **`slprj/`**: Simulink project files and build artifacts containing compilation data and generated code

## 🎯 System Architecture

### Hierarchical Design Principles
The hierarchical model demonstrates:
- **Top-Level System**: Overall system interface and coordination
- **Subsystem Levels**: Functional decomposition into manageable components  
- **Atomic Blocks**: Lowest level implementation details
- **Interface Management**: Clean data and control flow between levels

### Composite Model Features
- **Reusable Components**: Parameterized subsystems for multiple use
- **Library Blocks**: Centralized component management
- **Variant Subsystems**: Conditional model execution
- **Masked Subsystems**: User-friendly parameter interfaces

## 🔧 SDF Graph Implementation

### Graph Structure
The SDF graph implementation includes:
- **Processes (P1-P4)**: Computational nodes with defined firing rules
- **Buffers (a-e)**: Data storage with capacity constraints
- **Token Flow**: Synchronous data movement between processes

### Buffer Configuration
```c
BufferID: a (P1→P2), b (P2→P3), c (P3→P1), d (P4→P1), e (P3→P4)
Buffer Sizes: [2, 4, 4, 2, 2]
```

### Process Firing Rules
- **P1**: Consumes 4 tokens from c, 2 from d → Produces 2 tokens to a
- **P2**: Consumes 1 token from a → Produces 2 tokens to b  
- **P3**: Consumes 4 tokens from b → Produces 4 tokens to c, 2 to e
- **P4**: Consumes 1 token from e → Produces 1 token to d

## 🚀 Getting Started

### Prerequisites
- MATLAB R2018b or later
- Simulink
- GCC compiler (for C implementation)

### Running Simulink Models
1. Open MATLAB and navigate to this directory
2. Open the hierarchical model:
   ```matlab
   open('hierarchical_model.slx')
   ```
3. Explore the subsystem hierarchy by double-clicking blocks
4. Run simulation to observe multi-level behavior
5. For composite models:
   ```matlab
   open('composite_model.slx')
   ```

### Compiling SDF Implementation
1. Compile the C implementation:
   ```bash
   gcc -o sdf_graph sdf_graph_implementation.c
   ```
2. Run the executable:
   ```bash
   ./sdf_graph
   ```
3. Observe token flow and process firing sequence

## 📊 SDF Graph Execution

### Execution Sequence
The SDF graph follows a specific firing sequence:
```
Initial State: [2, 0, 0, 0, 0]
P2 fired → [1, 2, 0, 0, 0]
P2 fired → [0, 4, 0, 0, 0]  
P3 fired → [0, 0, 4, 0, 2]
P4 fired → [0, 0, 4, 1, 1]
P4 fired → [0, 0, 4, 2, 0]
P1 fired → [2, 0, 0, 0, 0]
```

### Key Features
- **Deadlock Prevention**: Careful buffer sizing prevents system deadlock
- **Overflow/Underflow Detection**: Runtime checks for buffer violations
- **Deterministic Execution**: Predictable token flow and timing
- **Resource Management**: Efficient memory and computation usage

## 🔍 Design Patterns

### Hierarchical Patterns
1. **Functional Decomposition**: Breaking complex systems into simpler parts
2. **Abstraction Levels**: Different detail levels for different audiences
3. **Interface Standardization**: Consistent data and control interfaces
4. **Modularity**: Independent, testable subsystems

### Composite Patterns
1. **Component Libraries**: Reusable building blocks
2. **Parameterization**: Configurable component behavior
3. **Variant Management**: Multiple implementation options
4. **Mask Interfaces**: User-friendly parameter setting

## 📈 Performance Analysis

### Model Complexity Metrics
- **Hierarchical Depth**: Number of subsystem levels
- **Component Reuse**: Percentage of reused vs. unique components
- **Interface Complexity**: Number and types of connections
- **Simulation Performance**: Execution time and memory usage

### SDF Graph Metrics
- **Throughput**: Tokens processed per time unit
- **Latency**: Time from input to output
- **Buffer Utilization**: Average buffer occupancy
- **Process Utilization**: Percentage of time each process is active

## 🎓 Educational Objectives

This project teaches:
1. **System Decomposition**: Breaking complex problems into manageable parts
2. **Model Organization**: Structuring models for maintainability
3. **Reusability**: Creating components for multiple uses
4. **Data Flow Modeling**: Understanding synchronous data flow principles
5. **Implementation Mapping**: From high-level models to code

## 🔧 Advanced Techniques

### Model Referencing
- **Atomic Subsystems**: Independent compilation units
- **Model Workspace**: Isolated parameter spaces
- **Incremental Loading**: Efficient memory management
- **Parallel Simulation**: Multi-core execution support

### Code Generation Optimization
- **Subsystem Inlining**: Performance optimization
- **Data Type Optimization**: Memory efficiency
- **Function Packaging**: Modular code organization
- **Interface Optimization**: Minimal overhead communication

## 🛠️ Best Practices

### Hierarchical Design
1. **Clear Interfaces**: Well-defined input/output specifications
2. **Appropriate Abstraction**: Right level of detail for each layer
3. **Consistent Naming**: Systematic naming conventions
4. **Documentation**: Comprehensive model documentation

### Composite Modeling
1. **Parameterization**: Flexible, configurable components
2. **Error Handling**: Robust parameter validation
3. **Testing**: Comprehensive component testing
4. **Version Control**: Systematic component versioning

## 🔍 Debugging and Analysis

### Model Analysis Tools
- **Model Advisor**: Automated model checking
- **Dependency Analyzer**: Component relationship analysis
- **Performance Advisor**: Optimization recommendations
- **Coverage Analysis**: Test completeness assessment

### SDF Debugging
- **Token Tracing**: Following token flow through the graph
- **Buffer Monitoring**: Real-time buffer state observation
- **Deadlock Detection**: Identifying potential deadlock conditions
- **Performance Profiling**: Process execution timing analysis

## 📚 Extensions and Applications

### Potential Extensions
1. **Dynamic SDF**: Runtime graph reconfiguration
2. **Multi-Rate Systems**: Different sampling rates
3. **Distributed Execution**: Multi-processor implementation
4. **Real-Time Constraints**: Timing requirement enforcement

### Application Domains
- **Signal Processing**: Multi-stage filter implementations
- **Communication Systems**: Protocol stack modeling
- **Control Systems**: Multi-loop control architectures
- **Embedded Systems**: Resource-constrained implementations

## 📖 References

1. Simulink User's Guide - MathWorks
2. "Synchronous Data Flow" - Edward Lee and David Messerschmitt
3. Model-Based Design for Embedded Systems - CRC Press
4. "Hierarchical Modeling in Simulink" - MathWorks Documentation

---

*This project provides comprehensive experience in advanced Simulink modeling techniques and synchronous data flow implementation, essential for complex system design and embedded applications.*