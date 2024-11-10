#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Function for simple sentiment analysis based on keywords
string sentimentAnalysis(const string& userInput) {
    vector<string> positiveWords = {"good", "great", "happy", "love", "awesome"};
    vector<string> negativeWords = {"bad", "sad", "angry", "hate", "terrible"};

    for (const string& word : positiveWords) {
        if (userInput.find(word) != string::npos) {
            return "positive";
        }
    }
    for (const string& word : negativeWords) {
        if (userInput.find(word) != string::npos) {
            return "negative";
        }
    }
    return "neutral";
}

// Function for simple response generation
string generateResponse(const string& userInput) {
    unordered_map<string, string> responses = {
        {"hello", "Hi there! How can I help you today?"},
        {"how are you", "I'm just a bot, but I'm here to help you!"},
        {"bye", "Goodbye! Have a great day!"},
        {"your name", "I'm ChatBot, your virtual assistant."},
        {"thank you", "You're welcome!"}
    };

    for (const auto& [key, response] : responses) {
        if (userInput.find(key) != string::npos) {
            return response;
        }
    }
    return "I'm not sure how to respond to that. Can you please clarify?";
}

int main() {
    cout << "Hello! I am your chatbot. Type 'bye' to exit.\n";

    while (true) {
        string userInput;
        cout << "You: ";
        getline(cin, userInput);

        // Convert user input to lowercase for easier matching
        for (char& c : userInput) c = tolower(c);

        // Exit condition
        if (userInput == "bye") {
            cout << "ChatBot: Goodbye! Have a great day!\n";
            break;
        }

        // Analyze sentiment and generate response
        string sentiment = sentimentAnalysis(userInput);
        string response = generateResponse(userInput);

        cout << "ChatBot (" << sentiment << "): " << response << endl;
    }
    return 0;
}
