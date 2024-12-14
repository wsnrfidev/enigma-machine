#include "../include/EnigmaApp.hpp"

EnigmaApp::EnigmaApp()
{
}

EnigmaApp::~EnigmaApp()
{
}

char EnigmaApp::toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') // Check if the character is an uppercase letter
        return c - 'A' + 'a';   // Convert to lowercase
    else
        return c;
}

int32_t EnigmaApp::letterToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a'; // Get index (0-25)
    } else {
        // Invalid input, return -1
        return -1;
    }
}

char EnigmaApp::indexToLetter(int32_t index) {
    if (index >= 0 && index <= 25) {
        return 'a' + index; // Convert index to lowercase letter
    } else {
        // Invalid input, return an error character or handle the error as needed
        return ' '; 
    }
}

char EnigmaApp::useEnigma(char c)
{
    if(c < 65 || c > 122)
    {
        return c;
    }
    else if(c >90 && c<97)
    {
        return c;
    }
    else
    {
        char c_small = toLowercase(c);
        int32_t index = letterToIndex(c_small);
        int32_t a = _em.getPermute(index);
        return indexToLetter(a);
    }

    return ' ';
}

std::string EnigmaApp::getEnigmaSig(AppLocations location)
{
    // current date and time on the current system
   time_t now = time(0);

    // convert now to string form
    std::string date_time{""};
    date_time += ctime(&now);
    date_time.erase(date_time.length() - 1);
    std::string _time{"["};

    _time += date_time;

    std::string enigma{""};

    switch (location)
    {
    case AppLocations::Encode:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Encode]" + Colors::RESET;
        break;
    case AppLocations::EncodeBySequence:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Encode By Sequence]" + Colors::RESET;
        break;
    case AppLocations::EncodeBySingles:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Encode Single Chars]" + Colors::RESET;
        break;
    case AppLocations::EncodeFromFile:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Encode From File]" + Colors::RESET;
        break;
    case AppLocations::MachineStat:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Machine Configuration Status]" + Colors::RESET;
        break;
    case AppLocations::BadInput:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Invalid Input!]" + Colors::RESET;
        break;
    case AppLocations::Menu:
        enigma = Colors::YELLOW + _time + " EnigmaApp - Menu]" + Colors::RESET;
        break;
    default:
        enigma = Colors::YELLOW + _time + " EnigmaApp]" + Colors::RESET;
        break;
    }

    return enigma;
}

void EnigmaApp::clearScreen()
{
    std::cout << "\033[2J\033[H";
}

void EnigmaApp::showMainMenu()
{
    
    std::string mainMenu{""};
    mainMenu += getEnigmaSig(AppLocations::Menu);
    mainMenu += "\n     1. Encode/Decode";
    mainMenu += "\n     2. Config Setting";
    mainMenu += "\n     3. Machine Status";
    mainMenu += "\n     4. Clear Screen";
    mainMenu += "\n     esc. Exit.";

    std::cout << mainMenu << std::endl;
}

MenuOption EnigmaApp::getMenuUserInput()
{
    char user_input{'0'};
    std::cin >> user_input;

    if(user_input != '1' && user_input != '2' && user_input != '3' && user_input != '4' && user_input != 27)
    {
        std::string bad_input{""};
        bad_input += getEnigmaSig(AppLocations::BadInput);
        bad_input += "\n";
        bad_input += Colors::RED  + " Invalid Input, Please follow the keywords and the instractions" +Colors::RESET;
        std::cout << bad_input << std::endl;
        return MenuOption::InvalidInput;
    }

    switch (user_input)
    {
    case '1':
        return MenuOption::EncodeDecode;
    case '2':
        return MenuOption::ConfigSetting;
    case '3':
        return MenuOption::MachineStatus;
    case '4':
        return MenuOption::ClearScreen;
    case 27:
        return MenuOption::Exit;    
    default:
        return MenuOption::InvalidInput;

    }
}

EncodeOption EnigmaApp::getEncodeUserInput()
{
    char user_input{'0'};
    std::cin >> user_input;

    if(user_input != '1' && user_input != '2' && user_input != '3' && user_input != '4' && user_input != 27)
    {
        std::string bad_input{""};
        bad_input += getEnigmaSig(AppLocations::BadInput);
        bad_input += "\n";
        bad_input += Colors::RED  + " Invalid Input, Please follow the keywords and the instractions" +Colors::RESET;
        std::cout << bad_input << std::endl;
        return EncodeOption::InvalidInput;
    }

    switch (user_input)
    {
    case '1':
        return EncodeOption::Single;
    case '2':
        return EncodeOption::Sequence;
    case '3':
        return EncodeOption::ReadFromFile;
    case '4':
        return EncodeOption::Exit;
    case 27:
        return EncodeOption::Exit;    
    default:
        return EncodeOption::InvalidInput;

    }

}

EncodeFromFileOptions EnigmaApp::getEncodeFromFileIserInput()
{
    char user_input{'0'};
    std::cin >> user_input;

    if(user_input != '1' && user_input != '2' &&  user_input != 27)
    {
        std::string bad_input{""};
        bad_input += getEnigmaSig(AppLocations::BadInput);
        bad_input += "\n";
        bad_input += Colors::RED  + " Invalid Input, Please follow the keywords and the instractions" +Colors::RESET;
        std::cout << bad_input << std::endl;
        return EncodeFromFileOptions::InvalidInput;
    }

    switch (user_input)
    {
    case '1':
        return EncodeFromFileOptions::EncodeAsSeq;
    case '2':
        return EncodeFromFileOptions::EncodeAsDataSet;
    case 27:
        return EncodeFromFileOptions::Exit;    
    default:
        return EncodeFromFileOptions::InvalidInput;

    }

}

void EnigmaApp::encode()
{
    std::string sequence_or_singleChars{""};
    sequence_or_singleChars += getEnigmaSig(AppLocations::Encode);
    sequence_or_singleChars += "\n     1. One Letter At Time";
    sequence_or_singleChars += "\n     2. Full Sequence";
    sequence_or_singleChars += "\n     3. Read From File";
    sequence_or_singleChars += "\n     4. Back";

    std::cout << sequence_or_singleChars << std::endl;

    EncodeOption user_input = getEncodeUserInput();

    switch (user_input)
    {
    case EncodeOption::Single:
        encodeSingle();
        break;
    case EncodeOption::Sequence:
        encodeSequence();
        break;
    case EncodeOption::ReadFromFile:
        encodeFromFile();
        break;
    case EncodeOption::Exit:
        break;
    default:
        break;
    }
}

void EnigmaApp::encodeSingle()
{
    std::string input_str{""};
    std::string output_str{""};
    std::string header{""};

    char user_input{'0'};

    header += getEnigmaSig(AppLocations::EncodeBySingles);
    header += "\nAdd a char then press enter, to exit press esc.";

    while(true)
    {
        std::cout << header << std::endl;
        std::cout << "- Input  :" << input_str << std::endl;
        std::cout << "- Output :" << output_str << std::endl;

        std::cin >> user_input;

        if(user_input == 27)
        {
            break;
        }
        if(user_input == ' ')
        {
            input_str  += ' ';
            output_str += ' ';
        }

        char em_user_input = useEnigma(user_input);
        input_str  += user_input;
        output_str += em_user_input;
    }

}

void EnigmaApp::encodeSequence()
{
    std::string input_str{""};
    std::string output_str{""};
    std::string header{""};

    char user_input{'0'};

    header += "\n       1. Add new Sequence\n       esc. to exit press";

    while(true)
    {
        std::cout << getEnigmaSig(AppLocations::EncodeBySequence) << header << std::endl;

        std::cin >> user_input;
        if (user_input == 27)
        {
            break;
        }
        std::cout <<"Add you Sequence here:" <<std::endl;
        std::cin >> user_input;
        
        std::string temp_str{""};
        std::getline(std::cin, temp_str);

        input_str = user_input + temp_str;

        for(size_t i = 0; i< input_str.size(); ++i)
        {
            output_str += useEnigma(input_str.at(i));
        }

        std::cout << "- Input  :" << input_str << std::endl;
        std::cout << "- Output :" << output_str << std::endl;

        input_str.clear();
        output_str.clear();
    }

}

void EnigmaApp::encodeFromFile()
{
    char user_input{'0'};
    std::string header{""};
    header += getEnigmaSig(AppLocations::EncodeFromFile);
    
    std::cout << header << std::endl;
    std::cout << " - Please add path to the txt file:\n";

    std::cin >> user_input;
    std::string temp_str{""};
    std::getline(std::cin, temp_str);

    std::string path_to_data{user_input + temp_str};
    

    std::cout << "Path Entered:" << path_to_data << std::endl;

    std::cout << "      1. Encode data as sequence\n";
    std::cout << "      2. Encode as data set format: originTxt Enigma(originTxt) machine_config\n";
    std::cout << "      esc. Exit\n";

    EncodeFromFileOptions from_file_input = getEncodeFromFileIserInput();

    switch (from_file_input)
    {
    case EncodeFromFileOptions::EncodeAsSeq:
        encodeFromFileAsSeq(path_to_data);
        break;
    case EncodeFromFileOptions::EncodeAsDataSet:
        encodeFromFileAsDataset(path_to_data);
        break;
    default:
        break;
    }

}

void EnigmaApp::encodeFromFileAsSeq(std::string path_to_file)
{
    std::ifstream inputFile(path_to_file);
    
    if (!inputFile.is_open()) 
    {
        std::cerr << "Could not open the input file." << std::endl;
        return;
    }
    
    // Extracting filename from path
    std::filesystem::path p{path_to_file};
    std::string filename = p.stem().string();

    std::filesystem::path outputPath(mannageOutoutFile(filename, "/enigma_output_seq"));
    
    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not open the output file." << std::endl;
        inputFile.close();
        return;
    }
    

    // Processing each word
    std::string word;
    while (inputFile >> word) {
        for(size_t i=0; i<word.size(); ++i)
        {
            char transformed_letter = useEnigma(word.at(i));
            outputFile << transformed_letter ;
        }
        outputFile << " ";
    }

    inputFile.close();
    outputFile.close();
}

std::string EnigmaApp::validateWord(std::string word)
{
    std::string clean_word{""};
    for(size_t i{0}; i < word.size(); ++i)
    {
        if(word.at(i) >= 'a' && word.at(i) <= 'z')
        {
            clean_word += word.at(i);
        }
        else if(word.at(i) >= 'A' && word.at(i) <= 'Z')
        {
            char temp = word.at(i) -'A';
            temp += 'a';
            clean_word += temp;
        }

    }

    return clean_word;
}

std::filesystem::path EnigmaApp::mannageOutoutFile(std::string filename, std::string output_file_name)
{
    // Getting the current date
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    std::string currentDate = oss.str();

    // Using environment variable to make path dynamic
    std::string homeDirectory = std::getenv("HOME"); // Get the home directory
    std::filesystem::path outputPath = homeDirectory + output_file_name; 


    if (!std::filesystem::exists(outputPath)) 
    {
        std::filesystem::create_directories(outputPath);
    }

    // Construct the full path for the output file
    outputPath /= filename + "_" + currentDate + ".txt";

    return outputPath;
}

void EnigmaApp::encodeFromFileAsDataset(std::string path_to_file)
{
    std::ifstream inputFile(path_to_file);
    
    if (!inputFile.is_open()) 
    {
        std::cerr << "Could not open the input file." << std::endl;
        return;
    }
    
    // Extracting filename from path
    std::filesystem::path p{path_to_file};
    std::string filename = p.stem().string();

    std::filesystem::path outputPath(mannageOutoutFile(filename, "/enigma_output_dataset_collection"));

    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not open the output file." << std::endl;
        inputFile.close();
        return;
    }
    

    // Processing each word
    std::string word;
    std::string valid_word;
    while (inputFile >> word) {
        valid_word = validateWord(word);
        outputFile << valid_word;
        outputFile << " ";
        for(size_t i=0; i<valid_word.size(); ++i)
        {
            char transformed_letter = useEnigma(valid_word.at(i));
            outputFile << transformed_letter ;
        }
        outputFile << "\n";
        _em.reConfigBaseEnigma();
    }

    inputFile.close();
    outputFile.close();

}

void EnigmaApp::showMachineStatus()
{
    std::cout <<getEnigmaSig(AppLocations::MachineStat) << "\n" << _em << std::endl;
}

void EnigmaApp::changeConfiguration()
{
    /**
     * 1. Reset to defualt Configuration.
     * 2. Choose configuration (0-100).
     * 3. Create Custom Cunfiguration.
     * 4. Save Current Configuration.
     * 5. Exit.
    */
}

void EnigmaApp::run()
{
    while (true) {
        if (to_clear) {
            clearScreen();
            to_clear = false;
        }

        showMainMenu();
        MenuOption input = getMenuUserInput();

        switch (input) {
            case MenuOption::EncodeDecode:
                encode();
                break;
            case MenuOption::ConfigSetting:
                changeConfiguration();
                break;
            case MenuOption::MachineStatus:
                showMachineStatus();
                break;
            case MenuOption::ClearScreen:
                to_clear = true;
                break;
            case MenuOption::Exit:
                return;
            default:
                // handleInvalidInput();
                break;
        }
    }
}


