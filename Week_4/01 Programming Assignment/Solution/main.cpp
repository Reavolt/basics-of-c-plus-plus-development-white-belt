#include <iostream>
#include <string>

//----------------------------------------------------------------------------------------------------
struct Week
{
	std::string value;
	explicit Week(const std::string & val) { value = val; }
};
//----------------------------------------------------------------------------------------------------
struct Specialization 
{
	std::string value;
	explicit Specialization(const std::string & val) { value = val; }
};
//----------------------------------------------------------------------------------------------------
struct Course
{
	std::string value;
	explicit Course(const std::string & val) { value = val; }
};
//----------------------------------------------------------------------------------------------------
struct LectureTitle
{
	std::string specialization;
	std::string course;
	std::string week;

	LectureTitle(const Specialization & spec, const Course & cur, const Week & wk) :
		specialization(spec.value), course(cur.value), week(wk.value) { }
};
//----------------------------------------------------------------------------------------------------
//int main()
//{
//	LectureTitle title_1(Specialization("C++"), Course("White belt"), Week("4th"));
//
//	LectureTitle title_2("C++", "White belt", "4th");
//
//	LectureTitle title_3(string("C++"), string("White belt"), string("4th"));
//
//	LectureTitle title_4 = { "C++", "White belt", "4th" };
//
//	LectureTitle title_5 = { {"C++"}, {"White belt"}, {"4th"} };
//
//	LectureTitle title_6(Course("White belt"), Specialization("C++"), Week("4th"));
//
//	LectureTitle title(Specialization("C++"), Week("4th"), Course("White belt"));
//
//	return 0;
//}
//----------------------------------------------------------------------------------------------------