#include <iostream>
#include <memory>
#include <cassert>
using namespace std;

#define sp std::shared_ptr
#define ms std::make_shared

enum class SongType {Rock,Pop,Classic,Invalid};

class Music{
	public:
		virtual string song() = 0;
	};
class RockMusic:public Music{
	public:
		string song()override{return "RockMusic";}
	};
class PopMusic:public Music{
	public:
		string song()override{return "PopMusic";}
	};
class ClassicMusic:public Music{
	public:
		string song()override{return "ClassicMusic";}
	};

class MusicFactory{
	public:
		sp<Music> getMusic(SongType type){
			sp<Music> music;
			switch(type){
				case SongType::Rock:
					music = ms<RockMusic>();
					break;
				case SongType::Pop:
					music =  ms<PopMusic>();
					break;
				case SongType::Classic:
					music =  ms<ClassicMusic>();
					break;
				default:
					assert("invalid argument");
					break;
			}
			return music;
		}
	};

int main(){
	
	MusicFactory musicFactory;
	sp<Music> rockMusic = musicFactory.getMusic(SongType::Rock);
	cout << rockMusic->song() << endl;
}
