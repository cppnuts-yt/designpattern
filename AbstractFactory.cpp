#include <iostream>
#include <memory>
#include <exception>

using namespace std;

#define sp std::shared_ptr
#define up std::unique_ptr

class DumbMobile{
	public:
		virtual std::string show() = 0;
	};
class Asha: public DumbMobile{
	public:
		std::string show(){return "Asha";}
	};
class Premo: public DumbMobile{
	public:
		std::string show(){return "Premo";}
	};
class Genie: public DumbMobile{
	public:
		std::string show(){return "Genie";}
	};

class SmartMoblie{
	public:
		virtual std::string show() = 0;
	};
class Galaxy: public SmartMoblie{
	public:
		std::string show(){return "Galaxy";}
	};
class Titan: public SmartMoblie{
	public:
		std::string show(){return "Titan";}
	};
class Lumia: public SmartMoblie{
	public:
		std::string show(){return "Lumia";}
	};

class MobileFactory{
	public:
		virtual sp<DumbMobile> getDumbMobile() = 0;
		virtual sp<SmartMoblie> getSmartMobile() = 0;
	};
class SamsungFactory: public MobileFactory{
	public:
		sp<DumbMobile> getDumbMobile(){sp<DumbMobile> tmp(new Genie); return std::move(tmp);}
		sp<SmartMoblie> getSmartMobile(){sp<SmartMoblie> tmp(new Galaxy); return std::move(tmp);}
	};
class NokiaFactory: public MobileFactory{
	public:
		sp<DumbMobile> getDumbMobile(){sp<DumbMobile> tmp(new Asha); return std::move(tmp);}
		sp<SmartMoblie> getSmartMobile(){sp<SmartMoblie> tmp(new Lumia); return std::move(tmp);}
	};
class HtcFactory: public MobileFactory{
	public:
		sp<DumbMobile> getDumbMobile(){sp<DumbMobile> tmp(new Premo); return std::move(tmp);}
		sp<SmartMoblie> getSmartMobile(){sp<SmartMoblie> tmp(new Titan); return std::move(tmp);}
	};

int main(){
	
	sp<MobileFactory> samsungFactory = sp<SamsungFactory>();
	
	try{
		sp<DumbMobile> samsungDumb = samsungFactory->getDumbMobile();
	}catch(exception& e){
		cout << e.what() << endl;
	}
}
