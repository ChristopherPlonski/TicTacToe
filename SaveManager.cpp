#include "SaveManager.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

void SaveManager::save_game_report_to_file(string gameReport, string fileType)
{   
	cout << "Game Report: " << gameReport << endl;
    
    filesystem::path gameReportFolderPath = filesystem::current_path() / GAME_REPORT_FOLDER_NAME;

    if (!filesystem::exists(gameReportFolderPath)) {
        // If the game report folder doesn't exist, create it
        filesystem::create_directory(gameReportFolderPath);
    }

    filesystem::path gameReportFilePath = gameReportFolderPath / (GAME_REPORT_FILE_NAME + "." + fileType);
    ofstream outputFileStream = ofstream(gameReportFilePath);

    if (outputFileStream.is_open())
    {
        outputFileStream << gameReport << endl;
        cout << "Game report saved successfully @ " << gameReportFilePath.generic_string() << endl;
    }
    else
    {
        cout << "Sorry, the game report file could not be saved." << endl;
    }

    outputFileStream.close();
}

// Method version for testing
/*
void SaveManager::save_game_report_to_file(string gameReport, string fileType)
{
    //cout << "Current Working Directory: " << filesystem::current_path().generic_string() << endl;
    cout << "Game Report: " << gameReport << endl;

    //string currentDirectoryPathString = filesystem::current_path().generic_string();
    //filesystem::path gameReportFolderPath = filesystem::path(currentDirectoryPathString + "/" + GAME_REPORT_FOLDER_NAME);
    filesystem::path gameReportFolderPath = filesystem::current_path() / GAME_REPORT_FOLDER_NAME;
    //cout << "GAME REPORT FILE FOLDER PATH: " << gameReportFolderPath.generic_string() << endl;

    if (!filesystem::exists(gameReportFolderPath)) {
        //cout << "GAME REPORT SAVE FOLDER DOES NOT EXIST! Creating... \n";
        filesystem::create_directory(gameReportFolderPath);
    }

    filesystem::path gameReportFilePath = gameReportFolderPath / (GAME_REPORT_FILE_NAME + "." + fileType);
    //cout << "File Path: " << gameReportFilePath.generic_string() << endl;
    ofstream outputFileStream = ofstream(gameReportFilePath);

    if (outputFileStream.is_open())
    {
        outputFileStream << gameReport << endl;
        cout << "Game report saved successfully @ " << gameReportFilePath.generic_string() << endl;
    }
    else
    {
        cout << "Sorry, the game report file could not be saved." << endl;
    }

    outputFileStream.close();
}

*/
