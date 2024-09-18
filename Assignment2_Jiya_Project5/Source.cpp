//Jiya Pandit
//Assignment2


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>



//Creating the struct

struct STUDENT_DATA
{
    std::string FirstNameOfStudent;

    std::string LastNameOfStudent;
};

int main()
{
   
    std::ifstream file("StudentData.txt");  // to open this file

    std::string line;

    std::vector<STUDENT_DATA> Students;

  
    if (file.is_open())
    {
       
        for (; std::getline(file, line); )   //to get read and get data idf file is open
        {
            std::istringstream ss(line);

            std::string FirstNameOfStudent, LastNameOfStudent;

           
            if (std::getline(ss, FirstNameOfStudent, ',') && std::getline(ss, LastNameOfStudent)) // to get the first and last name of student

            {
                
                STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent };

                Students.push_back(Student);
            }

        }

        file.close();   //this is for closing the file
    }

    else

    {
        std::cerr << "Sorry, we are not able to open the file!!!" << std::endl;  // printing incase the file is not opened

        return 1;  
    }

    int counter = 1; // counter for numbering of students
  
    for (const auto& Student : Students)
    {
        //output displatying thenames of teh students

        std::cout << counter <<" First Name:- " << Student.FirstNameOfStudent<< ", Last Name:- " << Student.LastNameOfStudent << std::endl;

        counter++;
        
    }

    return 0;

}
