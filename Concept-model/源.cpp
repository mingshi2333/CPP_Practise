#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

template <typename T>
void Draw(const T& x, std::ostream& out, size_t position){

	out << std::string(position, ' ') << x << std::endl;
}

class DrawConcept
{
public:
	template <typename T>
	DrawConcept(const T& x) : m_object(new model<T>(x))
	{
		std::cout << "Ctor" << std::endl;
	}

	DrawConcept(const DrawConcept& x) : m_object(x.m_object->copy_())
	{
		std::cout << "Copy" << std::endl;
	}

	DrawConcept(DrawConcept&& x) : m_object(std::move(x.m_object)) { ; }

	DrawConcept& operator=(DrawConcept x)
	{
		m_object = std::move(x.m_object); return *this;
	}

	friend void Draw(const DrawConcept& x, std::ostream& out, size_t position)
	{
		x.m_object->draw_(out, position);
	}

private:
	struct concept_t
	{
		virtual ~concept_t() { ; }
		virtual concept_t* copy_() = 0;
		virtual void draw_(std::ostream& out, size_t position) const = 0;
	};

	template <typename T>
	struct model : concept_t
	{
		model(const T& x) : m_data(x) { ; }
		concept_t* copy_() { return new model(*this); }
		void draw_(std::ostream& out, size_t position) const
		{
			Draw(m_data, out, position);
		}
		T m_data;
	};
	std::unique_ptr<concept_t> m_object;
};

typedef std::vector<DrawConcept> Document;

void Draw(const Document& x, std::ostream& out, size_t position)
{
	out << std::string(position, ' ') << "<document>" << std::endl;
	for (auto& e : x) Draw(e, out, position + 2);
	out << std::string(position, ' ') << "</document>" << std::endl;
}

class MyClass
{
};

void Draw(const MyClass& mc, ostream& out, size_t position)
{
	out << "MyClass" << endl;
}

int main()
{
	Document document;
	
	document.reserve(5);
	

	document.emplace_back(0);
	document.emplace_back(string("Hello"));
	document.emplace_back(document);
	document.emplace_back(MyClass());

	reverse(document.begin(), document.end());
	reverse(document.begin(), document.end());

	Draw(document, cout, 0);
	return 0;
}