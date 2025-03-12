#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

string calculateShippingFee(double weight, double distance, const string& service) {
    if (weight < 0.1 || weight > 50.0) {
        return "Error(Invalid Weight)";
    }
    if (distance < 1.0 || distance > 1000.0) {
        return "Error(Invalid Distance)";
    }
    if (service != "Standard" && service != "Express") {
        return "Error(Invalid Service)";
    }

    double fee = 0.0;
    if (service == "Standard") {
        fee = 5000 + 3000 * weight + 2000 * distance;
    } else {
        fee = 10000 + 5000 * weight + 4000 * distance;
    }

    ostringstream oss;
    oss << fixed << setprecision(2) << fee;
    return oss.str();
}

int main() {
    double weight, distance;
    string service;

    cout << "Fill in order information:\n";
    cout << "Weight (0.1 - 50): ";
    cin >> weight;
    cout << "Distance (1 - 1000): ";
    cin >> distance;
    cout << "Service (Standard / Express): ";
    cin >> service;

    string result = calculateShippingFee(weight, distance, service);

    cout << "Result" << result << endl;

    return 0;
}
