#include "SaveManager.hpp"

#include <iostream>
#include <fstream>

void SaveManager::save_game_report_to_file(string gameReport, string fileType)
{
	cout << "Game Report: " << gameReport << endl;

    ofstream ofstream;
    ofstream.open(GAME_REPORT_FILE_SAVE_FOLDER + GAME_REPORT_FILE_NAME + "." + fileType);

    if (ofstream.is_open())
    {
        ofstream << gameReport << endl;
    }
    else
    {
        cout << "Sorry, the game report file could not be saved." << endl;
    }

    ofstream.close();
}
