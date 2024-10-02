#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Function to simulate a standard normal distribution
double gaussian_random() {
    static random_device rd;
    static mt19937 generator(rd());
    static normal_distribution<> distribution(0.0, 1.0);
    return distribution(generator);
}

// Function to simulate the option price path using Geometric Brownian Motion (GBM)
vector<double> simulate_price_path(double S0, double r, double sigma, double T, int steps) {
    vector<double> price_path(steps + 1);
    price_path[0] = S0;
    double dt = T / steps;

    for (int i = 1; i <= steps; ++i) {
        double Z = gaussian_random();
        price_path[i] = price_path[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
    }

    return price_path;
}

// Monte Carlo simulation for European option pricing
double european_option_pricing(char option_type, double S0, double K, double r, double sigma, double T, int steps, int simulations) {
    double option_price = 0.0;
    
    for (int i = 0; i < simulations; ++i) {
        vector<double> price_path = simulate_price_path(S0, r, sigma, T, steps);
        double payoff = 0.0;

        if (option_type == 'C') { // Call option
            payoff = max(0.0, price_path.back() - K);
        } else if (option_type == 'P') { // Put option
            payoff = max(0.0, K - price_path.back());
        }

        option_price += payoff;
    }

    option_price = (option_price / simulations) * exp(-r * T);
    return option_price;
}

// Monte Carlo simulation for American option pricing (using early exercise logic)
double american_option_pricing(char option_type, double S0, double K, double r, double sigma, double T, int steps, int simulations) {
    double option_price = 0.0;
    
    for (int i = 0; i < simulations; ++i) {
        vector<double> price_path = simulate_price_path(S0, r, sigma, T, steps);
        double payoff = 0.0;
        
        // American option allows early exercise
        for (int j = 0; j <= steps; ++j) {
            if (option_type == 'C') { // Call option
                payoff = max(payoff, max(0.0, price_path[j] - K));
            } else if (option_type == 'P') { // Put option
                payoff = max(payoff, max(0.0, K - price_path[j]));
            }
        }

        option_price += payoff;
    }

    option_price = (option_price / simulations) * exp(-r * T);
    return option_price;
}

int main() {
    // Option parameters
    double S0 = 100.0;  // Initial stock price
    double K = 100.0;   // Strike price
    double r = 0.05;    // Risk-free interest rate
    double sigma = 0.2; // Volatility
    double T = 1.0;     // Time to maturity in years
    int steps = 100;    // Number of time steps
    int simulations = 10000; // Number of Monte Carlo simulations

    // Calculate European Call and Put Option Prices
    double euro_call = european_option_pricing('C', S0, K, r, sigma, T, steps, simulations);
    double euro_put = european_option_pricing('P', S0, K, r, sigma, T, steps, simulations);

    // Calculate American Call and Put Option Prices
    double amer_call = american_option_pricing('C', S0, K, r, sigma, T, steps, simulations);
    double amer_put = american_option_pricing('P', S0, K, r, sigma, T, steps, simulations);

    // Output the results
    cout << "European Call Option Price: " << euro_call << endl;
    cout << "European Put Option Price: " << euro_put << endl;
    cout << "American Call Option Price: " << amer_call << endl;
    cout << "American Put Option Price: " << amer_put << endl;

    return 0;
}
