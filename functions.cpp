//
// Created by myatz on 4/23/2023.
//

#include "functions.h"
void threeStringsCutNPaste()
{
    std::string line1, line2, line3;
    std::vector<std::string>line1Vector, line2Vector, line3Vector;
    std::cout << "Enter a sentence\n";
    std::getline(std::cin, line1);
    std::cout << "Enter the word(s) you want to edit\n";
    std::getline(std::cin, line2);
    std::cout << "Enter the word(s) you want to replace them with\n";
    std::getline(std::cin, line3);
    line1Vector = changeString2Vector(line1);
    line2Vector = changeString2Vector(line2);
    line3Vector = changeString2Vector(line3);
    for(int i = 0; i < line1Vector.size(); i++)
    {
        for(int j = 0; j < line2Vector.size(); j++)
        {
            if(line1Vector[i] == line2Vector[j])
            {
                line1Vector[i] = line3Vector[j];
            }
        }
        std::cout << line1Vector[i] << " ";
    }
}
std::vector<std::string> changeString2Vector(std::string string)
{
    std::vector<std::string> stringVector;
    std::string newString = " " + string + " ";
    int spaceCount = 0, space1 = 0, space2;
    for(int i = 0; i < newString.size(); i++)
    {
        if(newString[i] == ' ')
        {
            spaceCount++;
            if(spaceCount > 1)
            {
                space2 = i;
                std::string aWord = newString.substr((space1 + 1), (space2 - (space1 + 1)));
                stringVector.push_back(aWord);
                space1 = space2;
            }
        }
    }
    return stringVector;
}