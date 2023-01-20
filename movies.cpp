
#include<stdio.h>
#include<iostream>
#include<string>
#include "movies.hpp"
#include "movie.hpp"

using namespace std;


Movies::Movies()
{
 //   cout << "default constructor for movies!" << endl;
}

void Movies::add_movie(std::string name_in,std::string rating_in, int watched_in)
{
    if (vec_movies.size()==0)
    {
         vec_movies.push_back(Movie {name_in,rating_in,watched_in});

    }else{

    for(int ii=0;ii<vec_movies.size();ii++)
    {

        if(name_in!=vec_movies[ii].get_name())
        {
          vec_movies.push_back(Movie {name_in,rating_in,watched_in});
             break;
        }else{
            cout << name_in << " already exists!" << endl;
            break;
        }

    }

    }

}

void Movies::display_movies()
{

cout << "===========================================" << endl;

    for(int ii=0;ii<vec_movies.size();ii++)
    {
        cout << "Name: "<< vec_movies[ii].get_name() << " ,Rating: "
         << vec_movies[ii].get_rating() << " ,Watched: " 
         <<vec_movies[ii].get_watched() <<endl;
    }
cout << "===========================================" << endl;


}

void Movies::increment_watched(std::string name_in, int num_in)
{
    int temp=0;
    for(int ii=0;ii<vec_movies.size();ii++)
    {

        if(name_in==vec_movies[ii].get_name())
        {
            vec_movies[ii].increment_watched(num_in);
            temp=1;
            break;
        }  
      

    }

    if (temp==0)
    {
        cout << name_in <<  " is not available!" << endl;
    }


}

Movies::~Movies()
{
     //   cout << "default destructor for movies!" << endl;

}