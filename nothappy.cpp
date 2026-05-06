#include <iostream>
#include <string>
using namespace std;
class Student{
protected:
    string fullName;
    string studentID;
    double GPA;
public:
    void Input();
    void Output();
};
void Student::Input(){
    cout << "Nhap ten sinh vien: ";
    getline(cin, fullName);
    cout << "Nhap ID cua sinh vien: ";
    getline(cin, studentID);
    cout << "Nhap gpa cua sinh vien: ";
    cin >> GPA;
    cin.ignore();
}
void Student::Output(){
    cout << "Ho va ten cua sinh vien la " << fullName << endl;
    cout << "ID cua sinh vien la " << studentID << endl;
    cout << "GPA cua sinh vien la " << GPA << endl;
}
class ScholarshipStudent:public Student{
private:
    double scholarshipAmount;
    int researchHours;
public:
    void Input();
    void Output();
    void CheckScholarship(){
        if(GPA >= 3.2 && researchHours >= 20) cout << "Sinh vien du dieu kien nhan tiep hoc bong." << endl;
        else cout << "Sinh vien khong du dieu kien nhan hoc bong." << endl;
    }
};
void ScholarshipStudent::Input(){
    Student::Input();
    cout << "Nhap so luong hoc bong: ";
    cin >> scholarshipAmount;
    cout << "Nhap so gio nghien cuu: ";
    cin >> researchHours;
    cin.ignore();
}
void ScholarshipStudent::Output(){
    Student::Output();
    cout << "So luong hoc bong la " << scholarshipAmount << endl;
    cout << "So gio nghien cuu la " << researchHours << endl;
    CheckScholarship();
}
int main(){
    ScholarshipStudent st;
    st.Input();
    st.Output();
    return 0;
}
