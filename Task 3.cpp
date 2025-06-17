#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Function to change text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to check strength and give detailed feedback
string checkPasswordStrength(const string& password) {
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (specialChars.find(ch) != string::npos) hasSpecial = true;
    }

    int score = 0;
    if (password.length() >= 8) score++;
    if (hasLower) score++;
    if (hasUpper) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    setColor(14); // Yellow
    cout << "\nPassword Analysis:\n";
    setColor(7); // Reset

    cout << "- Length >= 8: " << (password.length() >= 8 ? "✔" : "❌") << endl;
    cout << "- Contains lowercase: " << (hasLower ? "✔" : "❌") << endl;
    cout << "- Contains uppercase: " << (hasUpper ? "✔" : "❌") << endl;
    cout << "- Contains number: " << (hasDigit ? "✔" : "❌") << endl;
    cout << "- Contains special character: " << (hasSpecial ? "✔" : "❌") << endl;

    string result;
    if (score == 5) {
        setColor(10); // Green
        result = "Very Strong 💪";
    } else if (score >= 4) {
        setColor(11); // Aqua
        result = "Strong ✅";
    } else if (score >= 3) {
        setColor(6); // Brownish Yellow
        result = "Moderate ⚠";
    } else {
        setColor(12); // Red
        result = "Weak ❌";
    }

    return result;
}

int main() {
    string password;

    setColor(13); // Purple
    cout << "Welcome to the SkillCraft Password Strength Checker 🔐" << endl;
    setColor(7); // Reset

    cout << "\nEnter your password: ";
    getline(cin, password);

    string strength = checkPasswordStrength(password);
    cout << "\nPassword Strength: " << strength << endl;

    setColor(7); // Reset color before exit
    return 0;
}