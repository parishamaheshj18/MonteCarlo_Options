# Monte Carlo Simulation for Option Pricing

This project implements a Monte Carlo simulation in C++ to price both European and American options. The code simulates random price paths of an underlying asset using the Geometric Brownian Motion model and calculates the option prices based on different market conditions.

## Features
- European Call and Put Option Pricing
- American Call and Put Option Pricing with early exercise logic
- Simulates random asset price paths using the Monte Carlo method
- Implemented using C++ for efficient numerical computation

## Requirements
To compile and run this project, you need:
- A C++ compiler (such as `g++`)
- A terminal or command line to execute the commands

## Compilation and Execution

### Steps to Execute the Program:
1. **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/monte-carlo-option-pricing.git](https://github.com/parishamaheshj18/MonteCarlo_Options.git)
    cd Scripts
    ```

2. **Compile the C++ code:**
    Use the `g++` compiler to compile the code.
    ```bash
    g++ monte_carlo.cpp -o monte_carlo
    ```

3. **Run the executable:**
    After compiling, you can run the program with the following command:
    ```bash
    ./monte_carlo
    ```

4. **Expected Output:**
    The program will output the calculated option prices for both European and American options. For example:
    ```
    European Call Option Price: 10.4505
    European Put Option Price: 5.5731
    American Call Option Price: 10.5702
    American Put Option Price: 5.6829
    ```

## Parameters
The following option pricing parameters are hardcoded in the `main()` function of the code. You can modify these directly in the code for different simulations:

- `S0`: Initial stock price (default: 100.0)
- `K`: Strike price (default: 100.0)
- `r`: Risk-free interest rate (default: 0.05)
- `sigma`: Volatility of the stock price (default: 0.2)
- `T`: Time to maturity in years (default: 1.0)
- `steps`: Number of time steps (default: 100)
- `simulations`: Number of Monte Carlo simulations (default: 10,000)

## Modify the Code
To modify any of the parameters, simply edit the values inside the `main()` function in the `monte_carlo_option_pricing.cpp` file. For example, you can change the number of Monte Carlo simulations or the volatility (`sigma`).

