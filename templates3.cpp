#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;

template <typename T>
class Item{

private:
    std::string name;
    T value;

public:
    Item(std::string name, T value)
        :name{name}, value{value}
        {
            cout << "2 arg constructor called!" << endl;
        }

    std::string get_name() const
    {
        return name;
    }

    T get_value() const
    {
        return value;
    }


};


int main()
{

      Item<int> book{"Bible",100};
      Item<double> chair{"Bible",200};

      Item<std::string> title{"Shubham","engineer"};

      cout << title.get_name() << " " << title.get_value() << endl;

      Item<Item<std::string>> item1 {"Frank",{"C++","Professor"}};
      cout << item1.get_name() << " " << item1.get_value().get_name() << " " << 
            item1.get_value().get_value() << endl;  


      std::vector<Item<int>> vec1;
        typedef Item<int> sp_item; // typedef usage here

        vec1.push_back(sp_item {"Larry",100} );
        vec1.push_back(sp_item {"Moe",200});

        for(auto & item:vec1)
        {
            cout << item.get_name() <<" " << item.get_value() << endl;
        }

      std::pair<std::string,int> p1 {"Frank",100};
      cout << p1.first << endl;
      cout << p1.second << endl;

}