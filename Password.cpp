#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}
/*
bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
}
*/

bool Password::has_mixed_case(string phrase){
  int u = 0, l = 0;
  for (char c: phrase){
    if ((c >= 65 && c <= 90)||(c >= 97 && c <= 122)){
      if (isupper(c))
        u = 1;
      else if (islower(c))
        l = 1;
    }
  }
  if (u && l)
    return 1;
  return 0;
}