
class Brick
{
public:
	int getHealth(); //get health function
	void setHealth(int health); //set health function
	Brick(); //default constructor
	Brick(int health); //constructor with health decided
	Brick(const Brick & obj); // copy constructor 
	~Brick(); //destructor
private:
	int _health; //var holding health
};