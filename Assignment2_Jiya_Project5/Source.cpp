//Jiya Pandit
//Assignment2


//Header files

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>



//Creating the struct

struct STUDENT_DATA
{
    std::string FirstNameOfStudent;

    std::string LastNameOfStudent;

    std::string EmailAddressOfStudent;
};

int main()
{
   
#ifdef PRE_RELEASE

    std::cout << "Running in Pre-Release Mode" << std::endl;

    std::ifstream file("StudentData_Emails.txt");  //This is because we want to use the email address of the students in the pre release mode
#else

    std::cout << "Running in Standard Mode" << std::endl;

    std::ifstream file("StudentData.txt"); 

#endif

    std::string line;

    std::vector<STUDENT_DATA> Students;

  
    if (file.is_open())
    {
       
        for (; std::getline(file, line); )   //to get read and get data idf file is open
        {
            std::istringstream ss(line);

            std::string FirstNameOfStudent, LastNameOfStudent, EmailAddressOfStudent;


#ifdef PRE_RELEASE

            if (std::getline(ss, FirstNameOfStudent, ',') && std::getline(ss, LastNameOfStudent, ',') && std::getline(ss, EmailAddressOfStudent))
            
            {
                STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent, EmailAddressOfStudent };  // Include email address of student in the  pre-release
#else
            if (std::getline(ss, FirstNameOfStudent, ',') && std::getline(ss, LastNameOfStudent))
            
            {
                STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent, "" };  // No email address in standard mode
#endif
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

        std::cout << counter <<" First Name:- " << Student.FirstNameOfStudent<< " Last Name:- " << Student.LastNameOfStudent << std::endl;

        std::cout << std::endl;

#ifdef PRE_RELEASE

        std::cout << " Email: " << Student.EmailAddressOfStudent;  // Print email only in pre-release mode

        std::cout << std::endl;
#endif
        std::cout << std::endl;

        counter++;
        
    }


    return 0;

}
