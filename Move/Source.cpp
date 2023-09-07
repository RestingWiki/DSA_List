#include <iostream>
using namespace std;




class String {
public:
	String() = default;
	// Param constructor
	String(const char* string)
	{
		printf("Created!\n");
		size = strlen(string);
		data = new char[size];
		memcpy(data, string, size);

	}

	// Copy constructor
	String(const String& other) {

		printf("Copied!\n");
		size = other.size;
		data = new char[size];
		memcpy(data, other.data, size);
	}
	// Move constructor
	String(String&& other) noexcept{
		printf("Moved!\n");
		size = other.size;
		data = other.data;

		other.data = nullptr;
		other.size = 0;
	}

	// Move operator
	String& operator=(String&& other) {
		printf("Moved!\n");

		if (this != &other)
		{
			delete this->data;

			data = other.data;
			size = other.size;

			other.data = nullptr;
			other.size = 0;
		}

		return *this; 
	}

	~String(){
		size = 0;
		delete data;
		printf("Destroyed!\n");

	}

	// 
	void Print() {
		for (size_t i = 0; i < size; i++)
			printf("%c", data[i]);

		printf("\n");
	}
private:
	char* data;
	size_t size;
};

class Entity {
public:
	Entity(const String& name) 
		: m_Name(name)
	{
			
	}

	Entity( String&& name) 
		: m_Name(move(name))
	{

	}

	~Entity() 
	{
		printf("Entity destroyed!\n");
	}


	void printName() {
		m_Name.Print();
	}

private:
	String m_Name;
};


int main() {
	Entity entity(String("Kiwi"));

	entity.printName();
	int a;
	cin >> a;
	return 0;
}