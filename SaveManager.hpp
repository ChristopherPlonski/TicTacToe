#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <string>

using namespace std;

class SaveManager {

public:
	void save_game_report_to_file(string gameReport, string fileType);

private:
	const string GAME_REPORT_FILE_SAVE_FOLDER = "GameReports/";
	const string GAME_REPORT_FILE_NAME = "game_report";

};

#endif // !SAVEMANAGER_H
