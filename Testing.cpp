//Mohamed Saleh

# include<iostream>
# include<limits>
# include<cmath>
# include<iomanip>
# include<string>
# include<cctype>
# include<cstring>
# include<string>
# include<vector>
# include<iterator>
# include<set>
# include<map>

using std::cout;

namespace PCSetup
{
	
std::map<int, int> intMemory;
int intMemoryAddress = 0;

std::map<int, double> doubleMemory;
int doubleMemoryAddress = 0;

std::map<int, char> charMemory;
int charMemoryAddress = 0;

std::map<int, bool> boolMemory;
int boolMemoryAddress = 0;

std::map<int, std::string> stringMemory;
int stringMemoryAddress = 0;

class CPU
{
	template<typename T>
	friend bool operator==(std::string x, T y);
	friend bool operator==(std::string x, const char* y);
	
	private:
		std::map<int, int> intAccumulator;
		std::map<int, double> doubleAccumulator;
		std::map<int, char> charAccumulator;
		std::map<int, bool> boolAccumulator;
		std::map<int, std::string> stringAccumulator;
	
	public:
		template<typename T>
		T load(int x, T y)
		{
			if(y == 1)
			{
				intAccumulator[x] = intMemory[x];
				
				return intAccumulator[x];
			}
			else if(y == 2.2)
			{
				doubleAccumulator[x] = doubleMemory[x];
				
				return doubleAccumulator[x];
			}
			else if(y == 'a')
			{
				charAccumulator[x] = charMemory[x];
				
				return charAccumulator[x];
			}
//			else if(y == "b")
//			{
//				stringAccumulator[x] = stringMemory[x];
//				
//				return stringAccumulator[x];
//			}
			else if(y == false)
			{
				boolAccumulator[x] = boolMemory[x];
				
				return boolAccumulator[x];
			}
		}
		
		void store(int x, int y)
		{
			intMemory[x] = y;
		}
		
		void store(int x, double y)
		{
			doubleMemory[x] = y;
		}
		
		void store(int x, char y)
		{
			charMemory[x] = y;
		}
		
		void store(int x, bool y)
		{
			boolMemory[x] = y;
		}
		
		void store(int x, std::string y)
		{
			stringMemory[x] = y;
		}
		
		template<typename T, typename U, typename S, typename R>
		S add(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w + v;
		}
		
		template<typename T, typename U, typename S, typename R>
		S subtract(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w - v;
		}
		
		template<typename T, typename U, typename S, typename R>
		S multiply(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w * v;
		}
		
		template<typename T, typename U, typename S, typename R>
		S divide(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w / v;
		}
		
		template<typename T, typename U, typename S, typename R>
		bool compareEqual(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w == v;
		}
		
		template<typename T, typename U, typename S, typename R>
		bool compareLess(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w < v;
		}
		
		template<typename T, typename U, typename S, typename R>
		bool compareGreater(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w > v;
		}
		
		template<typename T, typename U, typename S, typename R>
		bool logicalOpAnd(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w && v;
		}
		
		template<typename T, typename U, typename S, typename R>
		bool logicalOpOr(T x, U y, S z, R g)
		{
			S w = load(x, z);
			R v = load(y, g);
			
			return w || v;
		}
		
		template<typename T, typename U>
		bool logicalOpNot(T x, U y)
		{
			T z = load(x, y);
			
			return !z;
		}
		
};//End of CPU Class

template<typename T>
bool operator==(std::string x, T y)
{
	return x == std::to_string(y);
}

bool operator==(std::string x, const char* y)
{
	return x == y;
}

CPU cpu;


class mouse
{
	template<class T>
	friend bool operator!(T& x);
	
	private:
		int i, iAddress, dataType = 1;
		
	public:
		mouse(int x = 0): i(x), iAddress(intMemoryAddress)
		{
			cpu.store(iAddress, i);
			intMemoryAddress++;
		}
		
		int getData(){return i;}
		int getAddress(){return iAddress;}
		int getDataType(){return dataType;}
		
		void setData(int x){i = x;}
		
		template<typename T>
		int operator+(T x)
		{
			cpu.add(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		int operator-(T x)
		{
			cpu.subtract(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		int operator*(T x)
		{
			cpu.multiply(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		int operator/(T x)
		{
			cpu.divide(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator==(T x)
		{
			cpu.compareEqual(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator<(T x)
		{
			cpu.compareLess(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator>(T x)
		{
			cpu.compareGreater(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator&&(T x)
		{
			cpu.logicalOpAnd(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator||(T x)
		{
			cpu.logicalOpOr(iAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		
		
};//End of int mouse Class

class keyboard
{
	template<class T>
	friend bool operator!(T& x);
	
	private:
		double d, dataType = 2.2;
		int dAddress;
		
	public:
		keyboard(double x = 0): d(x), dAddress(doubleMemoryAddress)
		{
			cpu.store(dAddress, d);
			doubleMemoryAddress++;
		}
		
		double getData(){return d;}
		int getAddress(){return dAddress;}
		double getDataType(){return dataType;}
		
		void setData(double x){d = x;}
		
		template<typename T>
		double operator+(T x)
		{
			cpu.add(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		double operator-(T x)
		{
			cpu.subtract(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		double operator*(T x)
		{
			cpu.multiply(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		double operator/(T x)
		{
			cpu.divide(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator==(T x)
		{
			cpu.compareEqual(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator<(T x)
		{
			cpu.compareLess(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator>(T x)
		{
			cpu.compareGreater(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator&&(T x)
		{
			cpu.logicalOpAnd(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator||(T x)
		{
			cpu.logicalOpOr(dAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		
		
};//End of double keyboard Class

class headphone
{
	template<class T>
	friend bool operator!(T& x);
	
	private:
		char c, dataType = 'a';
		int cAddress;
		
	public:
		headphone(char x = ' '): c(x), cAddress(charMemoryAddress)
		{
			cpu.store(cAddress, c);
			charMemoryAddress++;
		}
		
		char getData(){return c;}
		int getAddress(){return cAddress;}
		char getDataType(){return dataType;}
		
		void setData(char x){c = x;}
		
		template<typename T>
		char operator+(T x)
		{
			cpu.add(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		char operator-(T x)
		{
			cpu.subtract(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		char operator*(T x)
		{
			cpu.multiply(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		char operator/(T x)
		{
			cpu.divide(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator==(T x)
		{
			cpu.compareEqual(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator<(T x)
		{
			cpu.compareLess(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator>(T x)
		{
			cpu.compareGreater(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator&&(T x)
		{
			cpu.logicalOpAnd(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator||(T x)
		{
			cpu.logicalOpOr(cAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		
		
};//End of char headphone Class

class monitor
{
	template<class T>
	friend bool operator!(T& x);
	
	private:
		std::string s, dataType = "b";
		int sAddress;
		
	public:
		monitor(const char* x = ""): s(x), sAddress(stringMemoryAddress)
		{
			cpu.store(sAddress, s);
			stringMemoryAddress++;
		}
		
		monitor(std::string x): s(x), sAddress(stringMemoryAddress)
		{
			cpu.store(sAddress, s);
			stringMemoryAddress++;
		}
		
		std::string getData(){return s;}
		int getAddress(){return sAddress;}
		std::string getDataType(){return dataType;}
		
		void setData(std::string x){s = x;}
		
		template<typename T>
		std::string operator+(T x)
		{
			cpu.add(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		std::string operator-(T x)
		{
			cpu.subtract(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		std::string operator*(T x)
		{
			cpu.multiply(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		std::string operator/(T x)
		{
			cpu.divide(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator==(T x)
		{
			cpu.compareEqual(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator<(T x)
		{
			cpu.compareLess(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator>(T x)
		{
			cpu.compareGreater(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator&&(T x)
		{
			cpu.logicalOpAnd(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator||(T x)
		{
			cpu.logicalOpOr(sAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		
		
};//End of string monitor Class

class charging
{
	template<class T>
	friend bool operator!(T& x);
	
	private:
		bool b, dataType = false;
		int bAddress;
		
	public:
		charging(bool x = false): b(x), bAddress(boolMemoryAddress)
		{
			cpu.store(bAddress, b);
			boolMemoryAddress++;
		}
		
		bool getData(){return b;}
		int getAddress(){return bAddress;}
		bool getDataType(){return dataType;}
		
		void setData(bool x){b = x;}
		
		template<typename T>
		bool operator+(T x)
		{
			cpu.add(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator-(T x)
		{
			cpu.subtract(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator*(T x)
		{
			cpu.multiply(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator/(T x)
		{
			cpu.divide(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator==(T x)
		{
			cpu.compareEqual(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator<(T x)
		{
			cpu.compareLess(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator>(T x)
		{
			cpu.compareGreater(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator&&(T x)
		{
			cpu.logicalOpAnd(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		template<typename T>
		bool operator||(T x)
		{
			cpu.logicalOpOr(bAddress, x.getAddress(), dataType, x.getDataType());
		}
		
		
		
};//End of bool charging Class

template<class T>
bool operator!(T& x)
{
	cpu.logicalOpNot(x.getAddress(), x.getDataType());
}

class Output
{
	public:
		Output operator<(int x)
		{
			std::cout<< x;
			return *this;
		}
		
		Output operator<(double x)
		{
			std::cout<< x;
			return *this;
		}
		
		Output operator<(char x)
		{
			std::cout<< x;
			return *this;
		}
		
		Output operator<(const char* x)
		{
			std::cout<< x;
			return *this;
		}
		
		Output operator<(std::string x)
		{
			std::cout<< x;
			return *this;
		}
		
		Output operator<(bool x)
		{
			std::cout<< x;
			return *this;
		}
		
		template<typename T>
		Output operator<(T x)
		{
			std::cout<< x.getData();
			return *this;
		}
		
};//End of cout Output Class

class Input
{
	public:
		template<typename T>
		void operator>(T& x)
		{
			double y = x.getDataType();
			
			std::cin>> y;
			std::cin.ignore();
			x.setData(y);
		}
		
		void operator>(headphone& x)
		{
			char y;
			
			std::cin>> y;
			std::cin.ignore();
			x.setData(y);
		}
		
		void operator>(monitor& x)
		{
			std::string y;
	
			std::getline(std::cin, y);
			x.setData(y);
		}
		
};//End of cin Input Class

}

using namespace PCSetup;

Output display;
Input plugin;

int main()
{
	mouse a = 2, f = 3;
	keyboard b = 2.2, g = 3.3;
	headphone c = 'a', h = 'b';
	monitor e = "aaa", j = "bbb";
	charging d = true, i = false;
	
	
	return 0;
}

