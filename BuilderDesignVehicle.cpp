
//============================================================================
// Name        : BuilderPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;
#define up unique_ptr
#define sp shared_ptr

class Vehicle{
protected:
	string _wheel, _engine, _seat, _handle,_vehicleType;
public:
	void setVehicleType(string type){_vehicleType = type;}
	void setWheel(string wheel){_wheel = wheel;}
	void setEngine(string engine){_engine = engine;}
	void setSeat(string seat){_seat = seat;}
	void setHandle(string handle){_handle = handle;}
	friend ostream& operator << (ostream& os, Vehicle& vehicle){
		os << "Type :" << vehicle._vehicleType << endl;
		os << "Wheel: " << vehicle._wheel << endl;
		os << "Engine: " << vehicle._engine << endl;
		os << "Seat : " << vehicle._seat << endl;
		os << "Handle: " << vehicle._handle << endl;
		return os;
	}
};

class VehicleBuilder{

public:
	virtual void setVehicleType() = 0;
	virtual void setWheel() = 0;
	virtual void setEngine() = 0;
	virtual void setSeat() = 0;
	virtual void setHandle() = 0;
	virtual ~VehicleBuilder(){};
	Vehicle getResult(){return _result;}
protected:
	Vehicle _result;
};
class CarBuilder:public VehicleBuilder{
public:
	void setVehicleType() {_result.setVehicleType("Car");}
	void setWheel(){_result.setWheel("four wheel");}
	void setEngine(){_result.setEngine("car engine");}
	void setSeat() {_result.setSeat("four wheel big seat");}
	void setHandle() {_result.setHandle("round handle");}
	virtual ~CarBuilder(){}
};
class BikeBuilder:public VehicleBuilder{
public:
	void setVehicleType() {_result.setVehicleType("Bike");}
	void setWheel(){_result.setWheel("two wheel");}
	void setEngine(){_result.setEngine("bike engine");}
	void setSeat() {_result.setSeat("two wheel small seat");}
	void setHandle() {_result.setHandle("straight handle");}
	virtual ~BikeBuilder(){}
};
class PlaneBuilder: public VehicleBuilder{
public:
	void setVehicleType() {_result.setVehicleType("Plane");}
	void setWheel(){_result.setWheel("two wheel");}
	void setEngine(){_result.setEngine("plane engine");}
	void setSeat() {_result.setSeat("full passenger seat");}
	void setHandle() {_result.setHandle("plane complex handle");}
	virtual ~PlaneBuilder(){}
};

class Director{
public:
	void setBuilder(sp<VehicleBuilder> builder){
		_builder = builder;
	}
	void construct(){
		_builder->setVehicleType();
		_builder->setWheel();
		_builder->setEngine();
		_builder->setSeat();
		_builder->setHandle();
	}
private:
	sp<VehicleBuilder> _builder;
};

int main() {
	sp<VehicleBuilder> carBuilder = up<CarBuilder>(new CarBuilder);
	Director director;
	director.setBuilder(carBuilder);
	director.construct();
	Vehicle vehicle = carBuilder->getResult();

	cout << vehicle;
	cout << "reached" << endl;
	return 0;
}
