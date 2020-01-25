#include <iostream>
#include <string>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
class ReversibleString
{
public:
	ReversibleString() {}
	
	ReversibleString(const std::string & str) : data(str) { }

	void Reverse() 
	{
		std::reverse(begin(data), end(data));
	}

	std::string ToString() const 
	{
		return data;
	}
private:
	std::string data;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	ReversibleString s("live");
	s.Reverse();
	std::cout << s.ToString() << std::endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	std::cout << tmp << std::endl;

	ReversibleString empty;
	std::cout << '"' << empty.ToString() << '"' << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------