#include <iostream>
#include <vector>
#include <fstream>

class Student
{
	std::string m_first = "First";
	std::string m_last = "Last";
	int	m_id = 0;
	float m_avg = 0;

public: 

	Student() {}

	Student(std::string first, std::string last, int id, float avg)
		: m_first(first)
		, m_last(last)
		, m_id(id)
		, m_avg(avg)

	{
	}


	float getAvg()const
	{
			return m_avg;
	}


	int getID()const
	{
			return m_id;
	}

		std::string getFirst()
	{
			return m_first;
	}

	std::string getLast()
	{
		return m_last;
	}

	void print()const
	{
		std::cout << m_first << " " << m_last << " ";
		std::cout << m_id << " " << m_avg << "\n";

	}
};

class Course
{
	std::string	m_name = "Example Course";
	std::vector<Student> m_student;

public: 
	
	Course(){}

	Course(const std::string& name)
		: m_name(name)

	{
	}

	void addStudent(const Student& s)
	{
		m_student.push_back(s);
	}

	const std::vector<Student>& getStudents() const
	{
		return m_student;
	}

	void loadFromFile(const std::string& filename)
	{
		std::ifstream fin(filename);
		std::string temp;

		//std::cout << "Hello" << "\n";

			while (fin >> temp)
			{
				std::cout << temp << "\n";
		}
	}

	void print() const
	{
		for (const auto& s : m_student)
		{
			s.print();
		}
	}
};




int main()
{
	Student s1;
	Student s2("Kadeem", "Tyrell", 1, 9702.34);
	Student s3("Baz", "Foo", 203984, 88.23);

	//std::cout << s3.getLast() << "\n";
	//s3.print();
	//s2.getLast();

	Course comp4300("COMP 4300");
	//comp4300.addStudent(s2);
	//comp4300.addStudent(s3);
	//comp4300.addStudent(Student("Uchiha", "Sasuke", 13, 98.65));
	//comp4300.addStudent(Student("Uzumaki", "Naruto", 12, 30.30));

	comp4300.loadFromFile("students.txt");

	comp4300.print();


	return 0;

};