//this program implements the adapter pattern
//code for company that makes shipping containers
//used to make only cube containers initially
//is making transition to box containers with improved functionality

#include<iostream>
using namespace std;

//old client code uses only cube shaped box with fixed side length
class Cube
{
public:
	int side;
	virtual void volume_cube()=0;
};

//new client code uses box of different length, width and height
class Box
{
public:
	int ht, ln, wd;
	virtual void volume_box()=0;
	void show()
	{
		cout<<"This is a new and improved box container"<<endl;
	}
};

//concrete class cube_class implements Cube
class cube_class: public Cube
{
public:
	cube_class(int side)
	{
		this->side=side;
	}
	void volume_cube()
	{
		cout<<"The volume of cube container is: "<< side*side*side<<endl;
	}
};

//concrete class box_class implements Box
class box_class: public Box
{
public:
	box_class(int ht, int ln, int wd)
	{
		this->ht=ht;
		this->ln=ln;
		this->wd=wd;
	}
	box_class();
	void volume_box()
	{
		cout<<"The volume of box container is:" <<ht*wd*ln<<endl;
	}
};

//converts cube to box class interface
class Cube_adapter: public Box
{
	Cube *cube_obj; //programs to interface (Cube) not implementation
public:
	Cube_adapter(Cube *cube_obj1)
	{
		cube_obj=cube_obj1;
	}
	void volume_box()
	{
		cube_obj->volume_cube();
	}
};

int main()
{
	//old code can use both cube and box objects
	cout<<"Old code Output:"<<endl;
	cube_class *cube1= new cube_class(10);
	box_class *box1 = new box_class(20,10,10);
	cube1->volume_cube();
	box1->volume_box();


	cout<<endl<<"New code Output:"<<endl;
    //new code can only use box objects
	//because we have added improved functionality to box (show method in Box interface)
	//the client can still create cube containers
	//however, we need to use the adapter to convert cube into box
    cube_class *cube2 =  new cube_class(20); //client creates old-style cube object
    Box* cube_adapter= new Cube_adapter(cube2); //adapter converts cube to box object
    cube_adapter->volume_box();  //note that the adapter uses box class methods
    cube_adapter->show(); //the adapter can use improved functionality of box
}
