//#include <iostream>
//#include <string>
//using namespace std;
//
//enum SurveyType { MULTIPLECHOICE, TEXTINPUT, RATINGSCALE };
//
//struct Survey {
//    SurveyType type;
//    int surveyNum;
//    string question;
//    string* options;
//    string textAnswer;
//    int ratingAnswer;
//    int multipleAnswer;
//    static int total_text;
//    static int total_multiple;
//    static int total_rating;
//    static int total_responses;
//
//    Survey() : surveyNum(0), question(""), options(nullptr), textAnswer(""), ratingAnswer(0), multipleAnswer(0) {}
//
//
//    Survey(const Survey& other) : surveyNum(other.surveyNum), type(other.type), question(other.question),
//        textAnswer(other.textAnswer), ratingAnswer(other.ratingAnswer), multipleAnswer(other.multipleAnswer) {
//        if (other.options) {
//            options = new string[4];
//            for (int i = 0; i < 4; i++) {
//                options[i] = other.options[i];
//            }
//        }
//        else {
//            options = nullptr;
//        }
//    }
//
//
//    Survey& operator=(const Survey& other) {
//        if (this != &other) {
//            delete[] options;
//            surveyNum = other.surveyNum;
//            type = other.type;
//            question = other.question;
//            textAnswer = other.textAnswer;
//            ratingAnswer = other.ratingAnswer;
//            multipleAnswer = other.multipleAnswer;
//
//            if (other.options) {
//                options = new string[4];
//                for (int i = 0; i < 4; i++) {
//                    options[i] = other.options[i];
//                }
//            }
//            else {
//                options = nullptr;
//            }
//        }
//        return *this;
//    }
//
//    ~Survey() {
//        delete[] options;
//    }
//};
//
//int Survey::total_text = 0;
//int Survey::total_multiple = 0;
//int Survey::total_rating = 0;
//int Survey::total_responses = 0;
//
//class Admin {
//private:
//    Survey* surveys;
//    int surveyCount;
//public:
//    Admin() : surveys(nullptr), surveyCount(0) {}
//    ~Admin() { delete[] surveys; }
//
//    void addSurvey() {
//        Survey* temp = new Survey[surveyCount + 1];
//        for (int i = 0; i < surveyCount; i++) {
//            temp[i] = surveys[i];
//        }
//
//        Survey newSurvey;
//        int choice;
//        cout << "Select Question type:\n1. Multiple Choice\n2. Text Input\n3. Rating Scale\nChoice: ";
//        cin >> choice;
//        cin.ignore();
//
//        switch (choice) {
//        case 1: {
//            newSurvey.type = MULTIPLECHOICE;
//            cout << "Enter Question Statement:\n";
//            getline(cin, newSurvey.question);
//            newSurvey.options = new string[4];
//            cout << "Enter 4 Choices:\n";
//            for (int i = 0; i < 4; i++) {
//                getline(cin, newSurvey.options[i]);
//            }
//            Survey::total_multiple++;
//            break;
//        }
//        case 2: {
//            newSurvey.type = TEXTINPUT;
//            cout << "Enter Question Statement:\n";
//            getline(cin, newSurvey.question);
//            Survey::total_text++;
//            break;
//        }
//        case 3: {
//            newSurvey.type = RATINGSCALE;
//            cout << "Enter Question Statement:\n";
//            getline(cin, newSurvey.question);
//            Survey::total_rating++;
//            break;
//        }
//        default:
//            cout << "Invalid Choice\n";
//            delete[] temp;
//            return;
//        }
//
//        newSurvey.surveyNum = surveyCount + 1;
//        temp[surveyCount] = newSurvey;
//        delete[] surveys;
//        surveys = temp;
//        surveyCount++;
//        cout << "New Survey Created Successfully!\n";
//    }
//
//    void displaySurveys() const {
//        cout << "Survey List:\n";
//        for (int i = 0; i < surveyCount; i++) {
//            cout << "Survey " << surveys[i].surveyNum << ": " << surveys[i].question << endl;
//            if (surveys[i].type == MULTIPLECHOICE) {
//                for (int j = 0; j < 4; j++) {
//                    cout << char('A' + j) << ". " << surveys[i].options[j] << endl;
//                }
//            }
//            cout << endl;
//        }
//    }
//
//    void displayStatistics() const {
//        cout << "\nSurvey Statistics:\n";
//        cout << "Total Surveys Created: " << surveyCount << endl;
//        cout << "Total Multiple Choice Surveys: " << Survey::total_multiple << endl;
//        cout << "Total Text Input Surveys: " << Survey::total_text << endl;
//        cout << "Total Rating Scale Surveys: " << Survey::total_rating << endl;
//        cout << "Total User Responses: " << Survey::total_responses << endl;
//    }
//
//    Survey* getSurveys() const { return surveys; }
//    int getSurveyCount() const { return surveyCount; }
//};
//
//class Users {
//private:
//    string username;
//    string password;
//public:
//    Users(string u, string p) : username(u), password(p) {}
//    bool authenticate(string u, string p) {
//        return (username == u && password == p);
//    }
//};
//
//void fillSurvey(Survey* surveys, int surveyCount) {
//    for (int i = 0; i < surveyCount; i++) {
//        cout << "Answer Survey " << surveys[i].surveyNum << ": " << surveys[i].question << endl;
//        if (surveys[i].type == MULTIPLECHOICE) {
//            for (int j = 0; j < 4; j++) {
//                cout << char('A' + j) << ". " << surveys[i].options[j] << endl;
//            }
//            cout << "Select option (1-4): ";
//            cin >> surveys[i].multipleAnswer;
//        }
//        else if (surveys[i].type == TEXTINPUT) {
//            cout << "Enter your answer: ";
//            cin.ignore();
//            getline(cin, surveys[i].textAnswer);
//        }
//        else if (surveys[i].type == RATINGSCALE) {
//            cout << "Rate from 1-5: ";
//            cin >> surveys[i].ratingAnswer;
//        }
//        Survey::total_responses++;
//    }
//    cout << "Survey responses recorded!\n";
//}
//
//int main() {
//    Admin admin;
//    Users adminUser("admin", "admin123");
//    Users normalUser("user", "user123");
//    int choice;
//    while (true) {
//        cout << "\nWelcome, Select from below:\n1- Admin Login\n2- User Login\n3- View Statistics\n4- Exit\nChoice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            string username, password;
//            cout << "Enter Admin Username: ";
//            cin >> username;
//            cout << "Enter Admin Password: ";
//            cin >> password;
//            if (adminUser.authenticate(username, password)) {
//                int adminChoice;
//                cout << "\nAdmin Menu:\n1- Add Survey\n2- View Statistics\nChoice: ";
//                cin >> adminChoice;
//                if (adminChoice == 1) {
//                    admin.addSurvey();
//                    admin.displaySurveys();
//                }
//                else if (adminChoice == 2) {
//                    admin.displayStatistics();
//                }
//                else {
//                    cout << "Invalid choice!\n";
//                }
//            }
//            else {
//                cout << "Invalid credentials!\n";
//            }
//            break;
//        }
//        case 2: {
//            string username, password;
//            cout << "Enter User Username: ";
//            cin >> username;
//            cout << "Enter User Password: ";
//            cin >> password;
//            if (normalUser.authenticate(username, password)) {
//                fillSurvey(admin.getSurveys(), admin.getSurveyCount());
//            }
//            else {
//                cout << "Invalid credentials!\n";
//            }
//            break;
//        }
//        case 3:
//            cout << "Exiting the program.\n";
//            return 0;
//        default:
//            cout << "Invalid choice! Please try again.\n";
//        }
//    }
//    system("pause");
//    return 0;
//}
