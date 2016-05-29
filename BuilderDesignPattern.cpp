#include <iostream>
#include <memory>
using namespace std;
#define sp std::shared_ptr
#define ms std::make_shared
class HousePlan{
	public:
		virtual void setWindow(string) = 0;
		virtual void setDoor(string) = 0;
		virtual void setBathroom(string) = 0;
		virtual void setFloor(string) = 0;
		virtual void setKitchen(string) = 0;
	};
class House:public HousePlan{
	string window,door,bathroom,floor,kitchen;
	public:
	void setWindow(string window)override{this->window = window;} 
	void setDoor(string door)override{this->door = door;}
	void setBathroom(string bathroom)override{this->bathroom = bathroom;}
	void setFloor(string floor)override{this->floor = floor;}
	void setKitchen(string kitchen)override{this->kitchen = kitchen;}
	
	string getWindow(){return window;}
	string getDoor(){return door;}
	string getBathroom(){return bathroom;}
	string getFloor(){return floor;}
	string getKitchen(){return kitchen;}
	friend ostream& operator << (ostream& os, sp<House> house);
	};
	ostream& operator <<( ostream& os, sp<House> house){	
		os << "Window: " << house->getWindow() << endl;
		os << "Door: " << house->getDoor() << endl;
		os << "Bathroom: " << house->getBathroom() << endl;
		os << "Floor: " << house->getFloor() << endl;
		os << "Kitchen: " << house->getKitchen() << endl;
		return os;
	}
class HouseBuilder{
	public:
	virtual void buildWindow() = 0;
	virtual void buildDoor() = 0;
	virtual void buildBathroom() = 0;
	virtual void buildFloor() = 0;
	virtual void buildKitchen() = 0;
	
	virtual sp<House> getHouse() = 0;
	};
class LavisHouseBuilder:public HouseBuilder{
		sp<House> house;
	public:
		LavisHouseBuilder():house{ms<House>()}{}
		void buildWindow()override{house->setWindow("LavisWindow");}
		void buildDoor()override{house->setDoor("LavisDoor");}
		void buildBathroom()override{house->setBathroom("LavisBathroom");}
		void buildFloor()override{house->setFloor("LavisFloor");}
		void buildKitchen()override{house->setKitchen("LavisKitchen");}
		sp<House> getHouse()override{return house;}
	};
class NormalHouseBuilder:public HouseBuilder{
		sp<House> house;
	public:
		NormalHouseBuilder():house{ms<House>()}{}
		void buildWindow()override{house->setWindow("NormalWindow");}
		void buildDoor()override{house->setDoor("NormalDoor");}
		void buildBathroom()override{house->setBathroom("NormalBathroom");}
		void buildFloor()override{house->setFloor("NormalFloor");}
		void buildKitchen()override{house->setKitchen("NormalKitchen");}
		sp<House> getHouse()override{return house;}
	};
class Contractor {
		sp<HouseBuilder> houseBuilder;
	public:
		Contractor(sp<HouseBuilder> houseBuilder):houseBuilder{houseBuilder}{}
		sp<House> getHouse(){return houseBuilder->getHouse();}
		void buildHouse(){
			houseBuilder->buildWindow();
			houseBuilder->buildDoor();
			houseBuilder->buildBathroom();
			houseBuilder->buildFloor();
			houseBuilder->buildKitchen();
		}
	};
int main(){
	Contractor contractor1(ms<LavisHouseBuilder>());
	contractor1.buildHouse();
	sp<House> LavisHouse = contractor1.getHouse();
	cout << "LavisHouse :" << endl;
	cout << LavisHouse;
	Contractor contractor2(ms<NormalHouseBuilder>());
	contractor2.buildHouse();
	sp<House> NormalHouse = contractor2.getHouse();
	cout << "NoramlHouse :" << endl;
	cout << NormalHouse;
	}
