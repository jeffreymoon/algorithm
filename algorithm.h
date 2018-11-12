#pragma once
namespace ehlib
{
  template <typename Iter, typename Fun>
  Iter find_if(Iter beg, Iter end, Fun fun)
  {
    for( ; beg != end; ++beg) {
      if(fun(*beg)) {
        break;
      }
    }
    return beg;
  }
}