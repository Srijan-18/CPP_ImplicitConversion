#include <iostream>

using namespace std;

class Volume
{
    public:
        int length;
        int width;
        int height;

        Volume(int length, int width, int height)
        {
            this->length = length;
            this->width = width;
            this->height = height;
        }

        void displayVolume()
        {
            cout << "\nLength: " << length << "\nWidth: " << width << "\nHeight: " << height << endl;
        }
};

class Linear
{
    public:
        int width;

	 Linear(int width)
	{
		this->width = width;
	}

/*1*/        Linear(Volume& volume)
        {
            this->width = volume.width;
        }

/*2*/        Linear& operator = (const Volume& linear)
        {
            this->width = linear.width;
            return *this;
        }

/*3*/        operator Volume()
        {
            return Volume(0, this->width, 0);
        }

        void displayWidth()
        {
            cout << "\nWidth: " << width << endl;
        }
};

int main()
{
    Volume volume(100, 200, 300);
    volume.displayVolume();

    cout <<"\nUSING CONVERSION CONSTRUCTOR(VOLUME --> LINEAR)" << endl;

    Linear linear = volume;
    linear.displayWidth();

    cout <<"\nUSING = (Assignment) OPERATOR(VOLUME --> LINEAR)" << endl;

    linear = volume;
    linear.displayWidth();

    cout <<"\nUSING OPERATOR(LINEAR --> VOLUME)" << endl;
    volume = linear;
    volume.displayVolume();

	int a = 50;
	linear = a;

    return 0;
}
