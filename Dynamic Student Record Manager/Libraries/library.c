#include "library.h"

char gradeLetter(int grade){ //Function return grade in letter with grade in int
    if(grade >= 90) return 'A';
    if(grade >=80) return 'B';
    if(grade >= 70) return 'C';
    if(grade >=60) return 'D';
    if(grade >= 0) return 'F';
    return '?';//Invalid grade
}

//implement add, remove, update, search, compute statistics and display modular functions.
