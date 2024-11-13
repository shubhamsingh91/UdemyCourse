// h/t to reader Waldo for this example
#include <string>

// Main base class Fluent. This fluent returns a ref to the object of derived class, with the
// help of a down-cast.

template<typename Derived>
class Fluent {
public:
    // Return a reference to the derived type
    Derived& derived() {
        return static_cast<Derived&>(*this); // for this down-cast, Derived have to be Derived from Fluent
    }
};

struct Point2D
{
	int x{};
	int y{};
};

class Box : public Fluent<Box> {
public:
    Box& setTopLeft(Point2D point) { m_topLeft = point; return derived(); } // CRTP
    Box& setBottomRight(Point2D point) { m_bottomRight = point; return derived(); }
private:
    Point2D m_topLeft{};
    Point2D m_bottomRight{};
};

class Label // mixin Label class
{
public:
	void setText(const std::string_view str) { m_text = str; }
	void setFontSize(int fontSize) { m_fontSize = fontSize; }
private:
	std::string m_text{};
	int m_fontSize{};
};

class Tooltip // mixin Tooltip class
{
public:
	void setText(const std::string_view str) { m_text = str; }
private:
	std::string m_text{};
};

class Button : public Box, public Label, public Tooltip {}; // Button using three mixins

int main()
{
	Button button{};
	button.Box::setTopLeft({ 1, 1 });
	button.Box::setBottomRight({ 10, 10 });
	button.Label::setText("Submit");
	button.Label::setFontSize(6);
	button.Tooltip::setText("Submit the form to the server");

    Fluent<Box> f1;
    Box &obj {f1.derived()}; // returns a reference to the object of type Box
    obj.setBottomRight({12,1});



}