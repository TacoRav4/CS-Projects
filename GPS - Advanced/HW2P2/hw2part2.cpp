#include <iostream>
#include <json/json.h>
#include <fstream>
#include <iomanip>
#include <string>

// Function to parse JSON from file
Json::Value parseJsonFromFile(const std::string& filename) {
    std::ifstream file(filename);
    Json::Value root;
    file >> root;
    return root;
}

// Read Json files 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <location_json> <question_json>" << std::endl;
        return 1;
    }

    Json::Value locations = parseJsonFromFile(argv[1]);
    Json::Value question = parseJsonFromFile(argv[2]);

    std::string query_time = question["Time"].asString();
    Json::Value best_match;
    std::string best_time;

    for (const auto& item : locations) {
        std::string current_time = item["Time"].asString();

        /*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
        /*:: For debugging purpose                                          :*/
        /*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
        //std::cout << "Latitude parsed: " << item["GPS_DD"]["latitude"].asDouble() << std::endl;
        //std::cout << "Longitude parsed: " << item["GPS_DD"]["longitude"].asDouble() << std::endl;

        if (current_time < query_time && (best_time.empty() || current_time > best_time)) {
            best_match = item;
            best_time = current_time;
        }
    }

    std::cout << std::fixed << std::setprecision(1); // Setting up decimal places to 1

    /*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
    /*:: For debugging purpose                                          :*/
    /*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
    // best_match["GPS_DD"]["latitude"] = 1.0;
    // best_match["GPS_DD"]["longitude"] = -1.0;

    // // Matching to the output format 
    if (best_match.isNull()) {
        std::cout << "{\"GPS_DD\": {\"latitude\": 0.0, \"longitude\": 0.0}}" << std::endl;
    } 
    else {
        std::cout << "{\"GPS_DD\": {\"latitude\": " << best_match["GPS_DD"]["latitude"].asDouble() 
                  << ", \"longitude\": " << best_match["GPS_DD"]["longitude"].asDouble() << "}}" << std::endl;
    } 

    return 0;
}