#include "App.h"
class EqualerByNum
{
  int num;
  public:
  EqualerByNum(int num)
  {
    this->num = num;
  }
  bool operator()(const Genre* genre) const
  {
    return num == genre->GetNum();
  }
};

class EqualerByName
{
  string name;
  public:
  EqualerByName(string name)
  {
    this->name = name;
  }
  bool operator()(const Genre* genre) const
  {
    return name.compare(genre->GetName()) == 0;
  }
};

App::App(void)
{
  last_gnum = 0;
}

App::~App(void)
{
  GIter seek = genres.begin();
  GIter last = genres.end();
  const Genre* genre;
  for( ; seek != last; ++seek) {
    genre = (*seek);
    delete genre;
  }
}
void App::Run()
{
  int key = NO_DEFINED;
  while((key = SelectMenu()) != ESC) {
    switch(key) {
      case F1: AddGenre(); break;
      case F2: RemoveGenreByNum(); break;
      case F3: RemoveGenreByName(); break;
      case F4: FindGenreByNum(); break;
      case F5: FindGenreByName(); break;
      case F6: ListGenre(); break;
      default: cout << "Select another key. Please." << endl; break;
    }
    cout << "Press any key." << endl;
    ehglobal::getkey();
  }
}

int App::SelectMenu()
{
  ehglobal::clrscr();
  cout << "Genre Management Program [ESC]: Quit" << endl;
  cout << "F1: Add Genre" << endl;
  cout << "F2: Delete Genre by number " << endl;
  cout << " F3: Delete Genre by name" << endl;
  cout << "F4: Search by number " << endl;
  cout << " F5: Search by name " << endl;
  cout << " F6: Print Genre" << endl;
  return ehglobal::getkey();
}

void App::AddGenre()
{
  last_gnum++;
  cout << last_gnum << "st name of genre: ";
  string name = ehglobal::getstr();
  Genre* genre = new Genre(last_gnum, name);
  genres.push_back(genre);
}

void App::ListGenre() const
{
  GCIter seek = genres.begin();
  GCIter last = genres.end();
  const Genre* genre;
  for ( ; seek != last; ++seek) {
    genre = (*seek);
    genre->View();
  }
}

void App::RemoveGenreByNum()
{
  int num = 0;
  cout << "Number to delete: ";
  num = ehglobal::getnum();
  EqualerByNum ebnum(num);

  GIter seek = find_if(genres.begin(), genres.end(), ebnum);
  if(seek != genres.end()) {
    delete(*seek);
    genres.erase(seek);
    cout << "Deleted success." << endl;
  } else {
    cout << "There is no match number." << endl;
  }
}

void App::RemoveGenreByName()
{
  string name ;
  cout << "Name to delete: ";
  name = ehglobal::getstr();
  EqualerByName ebname(name);

  GIter seek = find_if(genres.begin(), genres.end(), ebname);
  if(seek != genres.end()) {
    Genre* genre = (*seek);
    delete genre;
    genres.erase(seek);
    cout << "Deleted success." << endl;
  } else {
    cout << "There is no match name." << endl;
  }
}

void App::FindGenreByNum() const
{
  int num = 0;
  cout << "Number to find: ";
  num = ehglobal::getnum();
  EqualerByNum ebnum(num);

  GCIter seek = find_if(genres.begin(), genres.end(), ebnum);
  if(seek != genres.end()) {
    Genre* genre = (*seek);
    genre->View();
  } else {
    cout << "There is no match number." << endl;
  }
}

void App::FindGenreByName() const
{
  string name;
  cout << "Name to find: ";
  name = ehglobal::getstr();
  EqualerByName ebnum(name);

  GCIter seek = find_if(genres.begin(), genres.end(), ebnum);
  if (seek != genres.end()) {
    Genre* genre = (*seek);
    genre->View();
  } else {
    cout << "There is no match number." << endl;
  }
}