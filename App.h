#pragma once

#include <vector>
#include <algorithm>
#include "Genre.h"
#include "ehglobal.h"

using std::vector;
using std::find;
using std::find_if;

typedef vector<Genre*> Genres;
//using Genres = vector<Genre*>;
typedef Genres::iterator GIter;
typedef Genres::const_iterator GCIter;

class App
{
  Genres genres;
  int last_gnum;
  public:
  App(void);
  ~App(void);
  void Run();
  private:
  int SelectMenu();
  void AddGenre();
  void RemoveGenreByName();
  void RemoveGenreByNum();
  void FindGenreByNum() const;
  void FindGenreByName() const;
  void ListGenre() const;
};