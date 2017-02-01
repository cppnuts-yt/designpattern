#include <iostream>
#include <string>
using namespace std;

class GameSetting {
	static GameSetting* _instance;
	int _brightness;
	int _width;
	int _height;
	GameSetting():_width(1300),_height(786),_brightness(75){}
	// all constructor should be private or protected(if you want to allow inheritance)
public:
	static GameSetting* getInstance() {
		if(_instance == NULL)
			_instance = new GameSetting();
		return _instance;
	}
	void setWidth(int width) {_width = width;}
	void setHeight(int height) {_height = height;}
	void setBrigtness(int brightness) { _brightness = brightness;}

	int getWidth() {return _width;}
	int getHeight(){return _height;}
	int getBrightNess() {return _brightness;}
	void displaySettings() {
		cout << endl << "brightness: " << _brightness << endl;
		cout << "height: " << _height << endl;
		cout << "width: " << _width << endl << endl;
	}
};

GameSetting* GameSetting::_instance;
void someFunction() {

	cout << "inside someFunction" << endl;
	GameSetting *setting = GameSetting::getInstance();
	setting->displaySettings();

}
int main() {
	cout << "inside main" << endl;
	GameSetting *setting = GameSetting::getInstance();
	setting->displaySettings();
	someFunction();
	return 0;
}