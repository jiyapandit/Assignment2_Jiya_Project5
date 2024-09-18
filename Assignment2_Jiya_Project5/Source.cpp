
// Jiya Pandit
// Assignment2

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


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

    std::ifstream file("StudentData_Emails.txt");  // We are using the  email address of the students in pre-release mode

#else

    std::cout << "Running in Standard Mode" << std::endl;

    std::ifstream file("StudentData.txt");  // We don't need email in this one

#endif

    std::vector<STUDENT_DATA> Students;

    std::string line;

    // Reading from the file

    if (file.is_open())
    
    {
        while (std::getline(file, line)) 
        
        {
            std::istringstream ss(line);


            std::string FirstNameOfStudent, LastNameOfStudent, EmailAddressOfStudent;


#ifdef PRE_RELEASE

            // In pre-release, we have to do the first,last adn email addressof teh student


            if (std::getline(ss, FirstNameOfStudent, ',') && std::getline(ss, LastNameOfStudent, ',') && std::getline(ss, EmailAddressOfStudent)) 
            
            {
                STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent, EmailAddressOfStudent };

                Students.push_back(Student);
            }

#else

            // In standard, we only expect FirstName and LastName


            if (std::getline(ss, FirstNameOfStudent, ',') && std::getline(ss, LastNameOfStudent))
            
            {
                STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent, "" }; // No email in standard version


                Students.push_back(Student);
            }

#endif

        }


        file.close();


    }
    else 
    
    {
        std::cerr << "Sorry, we are not able to open the file!!!" << std::endl;

        return 1;  

    }

    int counter = 1;  // Counter for numbering students


#ifdef _DEBUG

  


#ifdef PRE_RELEASE

    
    for (const auto& Student : Students)
    
    {
        std::cout << counter << " First Name:- " << Student.FirstNameOfStudent << "       , Last Name:- " << Student.LastNameOfStudent << std::endl;

        std::cout << std::endl;
            
        std::cout << " Email:- " << Student.EmailAddressOfStudent << std::endl;

        std::cout << std::endl;

        counter++;
    }


#else

    //  Print only names

    for (const auto& Student : Students)
    
    {
        std::cout << counter << " First Name:- " << Student.FirstNameOfStudent<< "        , Last Name:- " << Student.LastNameOfStudent << std::endl;

        std::cout << std::endl;

        counter++;
    }

#endif


#else

  
#ifdef PRE_RELEASE

    //  It only prints the email address of the student in this mode


    for (const auto& Student : Students) 
    
    {
        std::cout << "Email:- " << Student.EmailAddressOfStudent << std::endl;

        std::cout << std::endl;

    }


#else

    std::cout << "Just running in Standard mode.\n";


#endif


#endif

    return 0;


}
